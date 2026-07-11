mod exports;
mod hooks;

use std::ffi::c_void;

const DLL_PROCESS_ATTACH: u32 = 1;

unsafe extern "system" {
    fn DisableThreadLibraryCalls(module: *mut c_void) -> i32;
}

#[unsafe(no_mangle)]
unsafe extern "system" fn DllMain(hinst: *mut c_void, reason: u32, _reserved: *mut c_void) -> i32 {
    unsafe {
        if reason == DLL_PROCESS_ATTACH {
            DisableThreadLibraryCalls(hinst);
            std::thread::spawn(|| {
                let ok = hooks::install_hooks();
                if ok {
                    hooks::change_window_title();
                }
            });
        }
        1
    }
}
