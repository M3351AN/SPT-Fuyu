#![allow(non_snake_case)]

mod exports;
mod hooks;
mod log;
mod vfs;

use std::ffi::c_void;

use crate::log::spt_log;

const DLL_PROCESS_ATTACH: u32 = 1;

extern "system" {
    fn DisableThreadLibraryCalls(module: *mut c_void) -> i32;
}

#[no_mangle]
unsafe extern "system" fn DllMain(hinst: *mut c_void, reason: u32, _reserved: *mut c_void) -> i32 {
    if reason == DLL_PROCESS_ATTACH {
        DisableThreadLibraryCalls(hinst);
        spt_log!("DllMain: DLL_PROCESS_ATTACH");
        std::thread::spawn(|| {
            spt_log!("worker thread: calling install_hooks");
            let ok = hooks::install_hooks();
            spt_log!("install_hooks returned {}", ok);
            if ok {
                hooks::change_window_title();
            }
        });
    }
    1
}
