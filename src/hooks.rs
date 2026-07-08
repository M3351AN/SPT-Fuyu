use std::ffi::c_void;
use std::ptr;

#[cfg(debug_assertions)]
use std::sync::atomic::{AtomicBool, Ordering};

use ilhook::x64::{CallbackOption, HookFlags, HookType, Hooker, Registers};

use crate::log::spt_log;
use crate::vfs::*;

#[cfg(debug_assertions)]
static REG_HOOK_LOGGED: AtomicBool = AtomicBool::new(false);

type FnRegOpenKeyExW =
    unsafe extern "system" fn(usize, *const u16, u32, u32, *mut usize) -> u32;
type FnRegQueryValueExW =
    unsafe extern "system" fn(usize, *const u16, *mut u32, *mut u32, *mut u8, *mut u32) -> u32;
type FnRegCloseKey = unsafe extern "system" fn(usize) -> u32;
type FnCreateFileW =
    unsafe extern "system" fn(*const u16, u32, u32, *const c_void, u32, u32, usize) -> usize;
type FnGetFileAttributesExW = unsafe extern "system" fn(*const u16, u32, *mut c_void) -> i32;
type FnNtQueryAttributesFile =
    unsafe extern "system" fn(*const ObjectAttributes, *mut NtFileBasicInformation) -> i32;
type FnCloseHandle = unsafe extern "system" fn(usize) -> i32;
type FnCreateFile2 =
    unsafe extern "system" fn(*const u16, u32, u32, u32, *const c_void) -> usize;
type FnGetFileInformationByHandleEx =
    unsafe extern "system" fn(usize, u32, *mut c_void, u32) -> i32;
type FnNtQueryDirectoryFile = unsafe extern "system" fn(
    usize,
    usize,
    usize,
    usize,
    usize,
    usize,
    u32,
    u32,
    i32,
    usize,
    i32,
) -> i32;

unsafe extern "win64" fn hook_reg_open_key_ex_w(
    reg: *mut Registers,
    ori: usize,
    _: usize,
) -> usize {
    unsafe {
        let key = (*reg).rcx as usize;
        let sub_key = (*reg).rdx as *const u16;
        let options = (*reg).r8 as u32;
        let desired = (*reg).r9 as u32;
        let result = (*reg).get_stack(5) as *mut usize;

        #[cfg(debug_assertions)]
        if !REG_HOOK_LOGGED.swap(true, Ordering::Relaxed) {
            spt_log!(
                "hook_reg_open_key_ex_w: first call, key=0x{:x} (HKEY_LOCAL_MACHINE=0x{:x})",
                key,
                HKEY_LOCAL_MACHINE
            );
        }

        if VirtualFileSystem::is_target_registry_key(key, sub_key) {
            spt_log!("hook_reg_open_key_ex_w: intercepted target key");
            *result = VirtualFileSystem::virtual_key();
            return ERROR_SUCCESS as usize;
        }

        let ori_fn: FnRegOpenKeyExW = std::mem::transmute(ori);
        ori_fn(key, sub_key, options, desired, result) as usize
    }
}

unsafe extern "win64" fn hook_reg_query_value_ex_w(
    reg: *mut Registers,
    ori: usize,
    _: usize,
) -> usize {
    unsafe {
        let key = (*reg).rcx as usize;
        let value_name = (*reg).rdx as *const u16;
        let reserved = (*reg).r8 as *mut u32;
        let ty = (*reg).r9 as *mut u32;
        let data = (*reg).get_stack(5) as *mut u8;
        let data_size = (*reg).get_stack(6) as *mut u32;

        if key == VirtualFileSystem::virtual_key()
            && wide_eq_ptr(value_name, VirtualFileSystem::target_registry_value())
        {
            let vp = VirtualFileSystem::virtual_path();
            let required_size = (vp.len() + 1) * 2;

            if !data.is_null()
                && !data_size.is_null()
                && *data_size >= required_size as u32
            {
                ptr::copy_nonoverlapping(vp.as_ptr(), data as *mut u16, vp.len());
                *(data as *mut u16).add(vp.len()) = 0;
                if !ty.is_null() {
                    *ty = REG_SZ;
                }
                *data_size = required_size as u32;
                return ERROR_SUCCESS as usize;
            } else if !data_size.is_null() {
                *data_size = required_size as u32;
                return ERROR_MORE_DATA as usize;
            }
        }

        let ori_fn: FnRegQueryValueExW = std::mem::transmute(ori);
        ori_fn(key, value_name, reserved, ty, data, data_size) as usize
    }
}

unsafe extern "win64" fn hook_reg_close_key(reg: *mut Registers, ori: usize, _: usize) -> usize {
    unsafe {
        let key = (*reg).rcx as usize;

        if key == VirtualFileSystem::virtual_key() {
            return ERROR_SUCCESS as usize;
        }

        let ori_fn: FnRegCloseKey = std::mem::transmute(ori);
        ori_fn(key) as usize
    }
}

unsafe extern "win64" fn hook_create_file_w(
    reg: *mut Registers,
    ori: usize,
    _: usize,
) -> usize {
    unsafe {
        let file_name = (*reg).rcx as *const u16;
        let desired_access = (*reg).rdx as u32;
        let share_mode = (*reg).r8 as u32;
        let sa = (*reg).r9 as *const c_void;
        let creation_disposition = (*reg).get_stack(5) as u32;
        let flags_and_attributes = (*reg).get_stack(6) as u32;
        let template_file = (*reg).get_stack(7) as usize;

        if !VirtualFileSystem::is_virtual_path_ptr(file_name) {
            let ori_fn: FnCreateFileW = std::mem::transmute(ori);
            return ori_fn(
                file_name,
                desired_access,
                share_mode,
                sa,
                creation_disposition,
                flags_and_attributes,
                template_file,
            ) as usize;
        }

        let handle = VirtualFileSystem::create_virtual_file_handle(file_name);
        if handle != INVALID_HANDLE_VALUE {
            SetLastError(ERROR_SUCCESS);
        }
        handle
    }
}

unsafe extern "win64" fn hook_create_file2(
    reg: *mut Registers,
    ori: usize,
    _: usize,
) -> usize {
    unsafe {
        let file_name = (*reg).rcx as *const u16;
        let desired_access = (*reg).rdx as u32;
        let share_mode = (*reg).r8 as u32;
        let creation_disposition = (*reg).r9 as u32;
        let params = (*reg).get_stack(5) as *const c_void;

        if !VirtualFileSystem::is_virtual_path_ptr(file_name) {
            let ori_fn: FnCreateFile2 = std::mem::transmute(ori);
            return ori_fn(
                file_name,
                desired_access,
                share_mode,
                creation_disposition,
                params,
            ) as usize;
        }

        let handle = VirtualFileSystem::create_virtual_file_handle(file_name);
        if handle != INVALID_HANDLE_VALUE {
            SetLastError(ERROR_SUCCESS);
        }
        handle
    }
}

unsafe extern "win64" fn hook_get_file_attributes_ex_w(
    reg: *mut Registers,
    ori: usize,
    _: usize,
) -> usize {
    unsafe {
        let file_name = (*reg).rcx as *const u16;
        let level = (*reg).rdx as u32;
        let info = (*reg).r8 as *mut c_void;

        if !VirtualFileSystem::is_virtual_path_ptr(file_name)
            || level != GET_FILE_EX_INFO_STANDARD
            || info.is_null()
        {
            let ori_fn: FnGetFileAttributesExW = std::mem::transmute(ori);
            return ori_fn(file_name, level, info) as usize;
        }

        let attr = &mut *(info as *mut Win32FileAttributeData);
        let now = get_current_file_time();
        attr.creation_time = now;
        attr.last_access_time = now;
        attr.last_write_time = now;

        if VirtualFileSystem::is_virtual_directory_ptr(file_name) {
            attr.file_attributes = FILE_ATTRIBUTE_DIRECTORY;
            attr.file_size_low = 0;
            attr.file_size_high = 0;
        } else if VirtualFileSystem::is_virtual_file_ptr(file_name) {
            attr.file_attributes = FILE_ATTRIBUTE_NORMAL;
            attr.file_size_low = 1024;
            attr.file_size_high = 0;
        } else {
            SetLastError(ERROR_FILE_NOT_FOUND);
            return 0;
        }

        SetLastError(ERROR_SUCCESS);
        1
    }
}

unsafe extern "win64" fn hook_nt_query_attributes_file(
    reg: *mut Registers,
    ori: usize,
    _: usize,
) -> usize {
    unsafe {
        let obj_attrs = (*reg).rcx as *const ObjectAttributes;
        let file_info = (*reg).rdx as *mut NtFileBasicInformation;

        if !obj_attrs.is_null() && !(*obj_attrs).object_name.is_null() {
            let obj_name = &*(*obj_attrs).object_name;
            let file_path = std::slice::from_raw_parts(
                obj_name.buffer,
                (obj_name.length / 2) as usize,
            );

            if VirtualFileSystem::is_virtual_path(file_path) {
                if !file_info.is_null() {
                    let fi = &mut *file_info;
                    fi.file_attributes = if VirtualFileSystem::is_virtual_directory(file_path) {
                        FILE_ATTRIBUTE_DIRECTORY
                    } else {
                        FILE_ATTRIBUTE_NORMAL
                    };
                    let time = get_current_file_time_i64();
                    fi.creation_time = time;
                    fi.last_access_time = time;
                    fi.last_write_time = time;
                    fi.change_time = time;
                    return STATUS_SUCCESS as usize;
                }
                return STATUS_OBJECT_NAME_NOT_FOUND as usize;
            }
        }

        let ori_fn: FnNtQueryAttributesFile = std::mem::transmute(ori);
        ori_fn(obj_attrs, file_info) as usize
    }
}

unsafe extern "win64" fn hook_close_handle(reg: *mut Registers, ori: usize, _: usize) -> usize {
    unsafe {
        let handle = (*reg).rcx as usize;

        if VFS.remove_file_handle(handle) {
            return 1;
        }

        let ori_fn: FnCloseHandle = std::mem::transmute(ori);
        ori_fn(handle) as usize
    }
}

unsafe extern "win64" fn hook_get_file_information_by_handle_ex(
    reg: *mut Registers,
    ori: usize,
    _: usize,
) -> usize {
    unsafe {
        let h_file = (*reg).rcx as usize;
        let info_class = (*reg).rdx as u32;
        let file_info = (*reg).r8 as *mut c_void;
        let buffer_size = (*reg).r9 as u32;

        let meta = match VFS.get_file_meta(h_file) {
            Some(m) => m,
            None => {
                let ori_fn: FnGetFileInformationByHandleEx = std::mem::transmute(ori);
                return ori_fn(h_file, info_class, file_info, buffer_size) as usize;
            }
        };

        let (size, attrs) = meta;

        if info_class == FILE_INFO_FILE_STANDARD {
            if (buffer_size as usize) < std::mem::size_of::<FileStandardInfo>() {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }
            let si = &mut *(file_info as *mut FileStandardInfo);
            si.allocation_size = size;
            si.end_of_file = size;
            si.number_of_links = 1;
            si.delete_pending = 0;
            si.directory = if attrs & FILE_ATTRIBUTE_DIRECTORY != 0 { 1 } else { 0 };
            return 1;
        }

        if info_class == FILE_INFO_FILE_BASIC {
            if (buffer_size as usize) < std::mem::size_of::<FileBasicInfo>() {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }
            let bi = &mut *(file_info as *mut FileBasicInfo);
            let time = get_current_file_time_i64();
            bi.creation_time = time;
            bi.last_access_time = time;
            bi.last_write_time = time;
            bi.change_time = time;
            bi.file_attributes = attrs;
            return 1;
        }

        let ori_fn: FnGetFileInformationByHandleEx = std::mem::transmute(ori);
        ori_fn(h_file, info_class, file_info, buffer_size) as usize
    }
}

unsafe extern "win64" fn hook_nt_query_directory_file(
    reg: *mut Registers,
    ori: usize,
    _: usize,
) -> usize {
    unsafe {
        let file_handle = (*reg).rcx as usize;

        if let Some((_, attrs)) = VFS.get_file_meta(file_handle) {
            if attrs & FILE_ATTRIBUTE_DIRECTORY != 0 {
                return STATUS_NO_MORE_FILES as usize;
            }
        }

        let event = (*reg).rdx as usize;
        let apc_routine = (*reg).r8 as usize;
        let apc_context = (*reg).r9 as usize;
        let io_status_block = (*reg).get_stack(5) as usize;
        let file_information = (*reg).get_stack(6) as usize;
        let length = (*reg).get_stack(7) as u32;
        let file_info_class = (*reg).get_stack(8) as u32;
        let return_single_entry = (*reg).get_stack(9) as i32;
        let file_name = (*reg).get_stack(10) as usize;
        let restart_scan = (*reg).get_stack(11) as i32;

        let ori_fn: FnNtQueryDirectoryFile = std::mem::transmute(ori);
        ori_fn(
            file_handle,
            event,
            apc_routine,
            apc_context,
            io_status_block,
            file_information,
            length,
            file_info_class,
            return_single_entry,
            file_name,
            restart_scan,
        ) as usize
    }
}

unsafe extern "system" {
    fn GetModuleHandleA(name: *const u8) -> *mut c_void;
    fn LoadLibraryA(name: *const u8) -> *mut c_void;
    fn GetProcAddress(module: *mut c_void, name: *const u8) -> *const c_void;
    fn SetLastError(error: u32);
}

unsafe fn get_module_handle_or_load(dll: &[u8]) -> Option<*mut c_void> {
    unsafe {
        let module = GetModuleHandleA(dll.as_ptr());
        if !module.is_null() {
            return Some(module);
        }
        let module = LoadLibraryA(dll.as_ptr());
        if module.is_null() {
            None
        } else {
            Some(module)
        }
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

unsafe fn get_original_function(name: &str) -> usize {
    unsafe {
        let dll_name: &[u8] = if name.contains("Reg") {
            b"advapi32.dll\0"
        } else if name.contains("Nt") {
            b"ntdll.dll\0"
        } else if name.contains("GetFileVersionInfo") || name.contains("VerQueryValue") {
            b"version.dll\0"
        } else {
            b"KernelBase.dll\0"
        };

        let module = get_module_handle_or_load(dll_name).or_else(|| {
            if dll_name == b"KernelBase.dll\0" {
                get_module_handle_or_load(b"kernel32.dll\0")
            } else {
                None
            }
        });

        let name_c = format!("{}\0", name);
        module
            .and_then(|m| get_proc_address(m, name_c.as_bytes()))
            .unwrap_or(0)
    }
}

type HookCallback = unsafe extern "win64" fn(*mut Registers, usize, usize) -> usize;

#[cfg_attr(not(debug_assertions), allow(unused_variables, unused_assignments))]
pub fn install_hooks() -> bool {
    let hooks: &[(&str, HookCallback)] = &[
        ("RegOpenKeyExW", hook_reg_open_key_ex_w),
        ("RegQueryValueExW", hook_reg_query_value_ex_w),
        ("RegCloseKey", hook_reg_close_key),
        ("CreateFileW", hook_create_file_w),
        ("NtQueryAttributesFile", hook_nt_query_attributes_file),
        ("GetFileAttributesExW", hook_get_file_attributes_ex_w),
        ("CloseHandle", hook_close_handle),
        ("CreateFile2", hook_create_file2),
        (
            "GetFileInformationByHandleEx",
            hook_get_file_information_by_handle_ex,
        ),
        ("NtQueryDirectoryFile", hook_nt_query_directory_file),
    ];

    let mut ok_count = 0usize;
    let mut fail_count = 0usize;

    for &(name, callback) in hooks {
        unsafe {
            let addr = get_original_function(name);
            if addr == 0 {
                spt_log!("install: {} -> address not found, skipping", name);
                fail_count += 1;
                continue;
            }
            spt_log!("install: {} -> addr 0x{:x}", name, addr);
            let hooker = Hooker::new(
                addr,
                HookType::Retn(callback),
                CallbackOption::None,
                0,
                HookFlags::empty(),
            );
            match hooker.hook() {
                Ok(hp) => {
                    let _ = Box::leak(Box::new(hp));
                    ok_count += 1;
                    spt_log!("install: {} -> OK", name);
                }
                Err(e) => {
                    fail_count += 1;
                    spt_log!("install: {} -> FAILED: {:?}", name, e);
                }
            }
        }
    }

    spt_log!("install_hooks done: {} ok, {} failed", ok_count, fail_count);
    ok_count > 0
}

#[link(name = "user32")]
unsafe extern "system" {
    fn FindWindowW(class: *const u16, title: *const u16) -> *mut c_void;
    fn SetWindowTextW(window: *mut c_void, title: *const u16) -> i32;
}

#[cfg_attr(not(debug_assertions), allow(unused_variables))]
pub fn change_window_title() {
    std::thread::spawn(|| {
        spt_log!("change_window_title: thread started, polling for SPT.Launcher window");
        unsafe {
            let title: Vec<u16> = "SPT.Launcher"
                .encode_utf16()
                .chain(std::iter::once(0))
                .collect();
            let mut attempts = 0u32;
            loop {
                let window = FindWindowW(ptr::null(), title.as_ptr());
                if !window.is_null() {
                    let new_title: Vec<u16> = "SPT.Fuyu.Launcher"
                        .encode_utf16()
                        .chain(std::iter::once(0))
                        .collect();
                    let ok = SetWindowTextW(window, new_title.as_ptr());
                    spt_log!(
                        "change_window_title: found window 0x{:x}, SetWindowTextW returned {}",
                        window as usize,
                        ok
                    );
                    break;
                }
                attempts += 1;
                if attempts % 50 == 0 {
                    spt_log!("change_window_title: still polling ({} attempts)", attempts);
                }
                std::thread::sleep(std::time::Duration::from_millis(200));
            }
        }
    });
}
