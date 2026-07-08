#[cfg(debug_assertions)]
pub(crate) mod enabled {
    use std::fs::OpenOptions;
    use std::io::Write;
    use std::sync::{Mutex, OnceLock};
    use std::time::{SystemTime, UNIX_EPOCH};

    unsafe extern "system" {
        fn GetTempPathW(nBufferLength: u32, lpBuffer: *mut u16) -> u32;
    }

    fn temp_dir() -> String {
        unsafe {
            let mut buf = [0u16; 260];
            let len = GetTempPathW(buf.len() as u32, buf.as_mut_ptr());
            if len == 0 {
                return String::from("C:\\");
            }
            String::from_utf16_lossy(&buf[..len as usize])
        }
    }

    struct LogState {
        file: Mutex<Option<std::fs::File>>,
    }

    static LOG: OnceLock<LogState> = OnceLock::new();

    fn log_state() -> &'static LogState {
        LOG.get_or_init(|| {
            let path = format!("{}spt_fuyu.log", temp_dir());
            let mut file = OpenOptions::new()
                .create(true)
                .append(true)
                .open(&path)
                .ok();
            if let Some(ref mut f) = file {
                let _ = writeln!(f, "=== SPT Fuyu log opened: {} ===", path);
            }
            LogState {
                file: Mutex::new(file),
            }
        })
    }

    pub(crate) fn log_impl(msg: &str) {
        let state = log_state();
        if let Ok(mut guard) = state.file.lock() {
            if let Some(ref mut f) = *guard {
                let ts = SystemTime::now()
                    .duration_since(UNIX_EPOCH)
                    .map(|d| d.as_millis())
                    .unwrap_or(0);
                let _ = writeln!(f, "[{:>12}] {}", ts, msg);
                let _ = f.flush();
            }
        }
    }
}

macro_rules! spt_log {
    ($($arg:tt)*) => {
        #[cfg(debug_assertions)]
        crate::log::enabled::log_impl(&format!($($arg)*));
    };
}

pub(crate) use spt_log;
