use std::ffi::c_void;
use std::ptr;
use std::sync::atomic::{AtomicBool, Ordering};

use ilhook::x64::{CallbackOption, HookFlags, HookType, Hooker, Registers};

#[allow(non_snake_case)]
#[repr(C)]
pub struct CORINFO_METHOD_INFO {
    pub ftn: usize,
    pub scope: usize,
    pub ILCode: *const u8,
    pub ILCodeSize: u32,
    pub maxStack: u32,
    pub localVarSigTok: u32,
    pub EHcount: u32,
    pub options: u32,
    pub dynamicInfo: usize,
    pub moreStackInfo: usize,
}

static VALIDATE_PATCHED: AtomicBool = AtomicBool::new(false);

static REPLACEMENT_IL: [u8; 2] = [0x17, 0x2A]; // ldc.i4.1; ret

unsafe extern "system" {
    fn GetModuleHandleA(name: *const u8) -> *mut c_void;
    fn LoadLibraryA(name: *const u8) -> *mut c_void;
    fn GetProcAddress(module: *mut c_void, name: *const u8) -> *const c_void;
}

type FnGetJit = unsafe extern "system" fn() -> *mut c_void;

unsafe fn get_compile_method_address() -> Option<usize> {
    unsafe {
        let clrjit_dll = b"clrjit.dll\0";
        let module = get_module_handle_or_load(clrjit_dll)?;

        let get_jit_name = b"getJit\0";
        let get_jit_addr = get_proc_address(module, get_jit_name)?;

        let get_jit: FnGetJit = std::mem::transmute(get_jit_addr);
        let compiler = get_jit();
        if compiler.is_null() {
            return None;
        }

        let vtable = *(compiler as *const usize);
        let compile_method = *(vtable as *const usize);

        Some(compile_method)
    }
}

unsafe fn get_module_handle_or_load(dll: &[u8]) -> Option<*mut c_void> {
    unsafe {
        let module = GetModuleHandleA(dll.as_ptr());
        if !module.is_null() {
            return Some(module);
        }
        let module = LoadLibraryA(dll.as_ptr());
        if module.is_null() { None } else { Some(module) }
    }
}

unsafe fn get_proc_address(module: *mut c_void, name: &[u8]) -> Option<usize> {
    unsafe {
        let addr = GetProcAddress(module, name.as_ptr());
        if addr.is_null() {
            None
        } else {
            Some(addr as usize)
        }
    }
}

unsafe extern "win64" fn hook_compile_method(reg: *mut Registers, ori: usize, _: usize) -> usize {
    unsafe {
        let method_info_ptr = (*reg).r8 as *const CORINFO_METHOD_INFO;

        if !method_info_ptr.is_null() && !VALIDATE_PATCHED.load(Ordering::Acquire) {
            let method_info = &*method_info_ptr;

            if !method_info.ILCode.is_null()
                && method_info.ILCodeSize == 288
                && method_info.maxStack == 5
            {
                let info = &mut *(method_info_ptr as *mut CORINFO_METHOD_INFO);
                info.ILCode = REPLACEMENT_IL.as_ptr();
                info.ILCodeSize = 2;
                info.maxStack = 1;
                info.localVarSigTok = 0;
                info.EHcount = 0;

                VALIDATE_PATCHED.store(true, Ordering::Release);
            }
        }

        type FnCompileMethod = unsafe extern "system" fn(
            *mut c_void,
            *mut c_void,
            *const CORINFO_METHOD_INFO,
            u32,
            *mut *const u8,
            *mut u32,
        ) -> usize;

        let ori_fn: FnCompileMethod = std::mem::transmute(ori);
        let this_ptr = (*reg).rcx as *mut c_void;
        let comp = (*reg).rdx as *mut c_void;
        let flags = (*reg).r9 as u32;
        let entry_address = (*reg).get_stack(5) as *mut *const u8;
        let native_size = (*reg).get_stack(6) as *mut u32;

        ori_fn(
            this_ptr,
            comp,
            method_info_ptr,
            flags,
            entry_address,
            native_size,
        )
    }
}

pub fn install_hooks() -> bool {
    std::thread::spawn(|| {
        install_compile_method_hook();
    });

    true
}

fn install_compile_method_hook() {
    for _ in 0..100 {
        unsafe {
            if let Some(compile_method_addr) = get_compile_method_address() {
                let hooker = Hooker::new(
                    compile_method_addr,
                    HookType::Retn(hook_compile_method),
                    CallbackOption::None,
                    0,
                    HookFlags::empty(),
                );

                match hooker.hook() {
                    Ok(hp) => {
                        let _ = Box::leak(Box::new(hp));
                        return;
                    }
                    Err(_) => {
                        return;
                    }
                }
            }
        }

        std::thread::sleep(std::time::Duration::from_millis(100));
    }
}

#[link(name = "user32")]
unsafe extern "system" {
    fn FindWindowW(class: *const u16, title: *const u16) -> *mut c_void;
    fn SetWindowTextW(window: *mut c_void, title: *const u16) -> i32;
}

#[cfg_attr(not(debug_assertions), allow(unused_variables))]
pub fn change_window_title() {
    std::thread::spawn(|| unsafe {
        let title: Vec<u16> = "SPT.Launcher"
            .encode_utf16()
            .chain(std::iter::once(0))
            .collect();
        loop {
            let window = FindWindowW(ptr::null(), title.as_ptr());
            if !window.is_null() {
                let new_title: Vec<u16> = "SPT.Fuyu.Launcher"
                    .encode_utf16()
                    .chain(std::iter::once(0))
                    .collect();
                SetWindowTextW(window, new_title.as_ptr());
                break;
            }
            std::thread::sleep(std::time::Duration::from_millis(200));
        }
    });
}
