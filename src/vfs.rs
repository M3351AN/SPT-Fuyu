use std::collections::HashMap;
use std::ffi::c_void;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{LazyLock, Mutex};

pub const HKEY_LOCAL_MACHINE: usize = 0x80000002u32 as i32 as usize;
const VIRTUAL_KEY_VALUE: usize = 0xDEADBEEF;
const FILE_HANDLE_SEED: u64 = 0xBEEF;
const FILE_HANDLE_INCREMENT: u64 = 0x11;

pub const ERROR_SUCCESS: u32 = 0;
pub const ERROR_FILE_NOT_FOUND: u32 = 2;
pub const ERROR_MORE_DATA: u32 = 234;
pub const ERROR_INSUFFICIENT_BUFFER: u32 = 122;

pub const FILE_ATTRIBUTE_NORMAL: u32 = 128;
pub const FILE_ATTRIBUTE_DIRECTORY: u32 = 16;

pub const STATUS_SUCCESS: i32 = 0;
pub const STATUS_OBJECT_NAME_NOT_FOUND: i32 = 0xC0000034u32 as i32;
pub const STATUS_NO_MORE_FILES: i32 = 0x80000006u32 as i32;

pub const GET_FILE_EX_INFO_STANDARD: u32 = 0;
pub const FILE_INFO_FILE_BASIC: u32 = 0;
pub const FILE_INFO_FILE_STANDARD: u32 = 1;

pub const INVALID_HANDLE_VALUE: usize = !0;

pub const REG_SZ: u32 = 1;

#[repr(C)]
pub struct UnicodeString {
    pub length: u16,
    pub maximum_length: u16,
    pub buffer: *mut u16,
}

#[repr(C)]
pub struct ObjectAttributes {
    pub length: u32,
    pub root_directory: *mut c_void,
    pub object_name: *mut UnicodeString,
    pub attributes: u32,
    pub security_descriptor: *mut c_void,
    pub security_quality_of_service: *mut c_void,
}

#[repr(C)]
#[derive(Clone, Copy, Default)]
pub struct NtFileBasicInformation {
    pub creation_time: i64,
    pub last_access_time: i64,
    pub last_write_time: i64,
    pub change_time: i64,
    pub file_attributes: u32,
}

#[repr(C)]
#[derive(Clone, Copy, Default)]
pub struct FileTime {
    pub low_date_time: u32,
    pub high_date_time: u32,
}

#[repr(C)]
#[derive(Clone, Copy, Default)]
pub struct Win32FileAttributeData {
    pub file_attributes: u32,
    pub creation_time: FileTime,
    pub last_access_time: FileTime,
    pub last_write_time: FileTime,
    pub file_size_high: u32,
    pub file_size_low: u32,
}

#[repr(C)]
#[derive(Clone, Copy)]
pub struct FileStandardInfo {
    pub allocation_size: i64,
    pub end_of_file: i64,
    pub number_of_links: u32,
    pub delete_pending: i32,
    pub directory: i32,
}

#[repr(C)]
#[derive(Clone, Copy)]
pub struct FileBasicInfo {
    pub creation_time: i64,
    pub last_access_time: i64,
    pub last_write_time: i64,
    pub change_time: i64,
    pub file_attributes: u32,
}

fn to_wide(s: &str) -> Vec<u16> {
    s.encode_utf16().collect()
}

pub unsafe fn wide_ptr_to_slice<'a>(ptr: *const u16) -> &'a [u16] {
    unsafe {
        if ptr.is_null() {
            return &[];
        }
        let mut len = 0;
        while *ptr.add(len) != 0 {
            len += 1;
        }
        std::slice::from_raw_parts(ptr, len)
    }
}

pub fn wide_eq_ptr(ptr: *const u16, s: &[u16]) -> bool {
    unsafe { wide_ptr_to_slice(ptr) == s }
}

fn lower_u16(c: u16) -> u16 {
    match c {
        0x0041..=0x005A => c + 0x20,
        _ => c,
    }
}

pub fn normalize_path(path: &[u16]) -> Vec<u16> {
    let mut result: Vec<u16> = path.iter().map(|&c| lower_u16(c)).collect();

    if result.len() >= 4
        && result[0] == b'\\' as u16
        && result[1] == b'\\' as u16
        && result[2] == b'?' as u16
        && result[3] == b'\\' as u16
    {
        result = result[4..].to_vec();
    }

    if result.len() > 3 && *result.last().unwrap() == b'\\' as u16 {
        result.pop();
    }

    for c in result.iter_mut() {
        if *c == b'/' as u16 {
            *c = b'\\' as u16;
        }
    }

    result
}

static VIRTUAL_PATH: LazyLock<Vec<u16>> = LazyLock::new(|| to_wide("A:\\SPTFuyuVirtualPath"));
static TARGET_REGISTRY_KEY: LazyLock<Vec<u16>> = LazyLock::new(|| {
    to_wide(
        "Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\EscapeFromTarkov",
    )
});
static TARGET_REGISTRY_VALUE: LazyLock<Vec<u16>> = LazyLock::new(|| to_wide("InstallLocation"));

static VIRTUAL_FILES_RAW: &[&str] = &[
    "BattlEye\\BEClient_x64.dll",
    "ConsistencyInfo",
    "Uninstall.exe",
    "UnityCrashHandler64.exe",
    "UnityPlayer.dll",
    "WinPixEventRuntime.dll",
    "Escapefromtarkov.exe",
    "EscapeFromTarkov_BE.exe",
    "baselib.dll",
    "GameAssembly.dll",
    "Logging.config",
];

static NORMALIZED_VIRTUAL_PATH: LazyLock<Vec<u16>> =
    LazyLock::new(|| normalize_path(&VIRTUAL_PATH));

static NORMALIZED_VIRTUAL_FILES: LazyLock<Vec<Vec<u16>>> = LazyLock::new(|| {
    VIRTUAL_FILES_RAW
        .iter()
        .map(|f| {
            let mut full = NORMALIZED_VIRTUAL_PATH.clone();
            full.push(b'\\' as u16);
            full.extend(normalize_path(&to_wide(f)));
            full
        })
        .collect()
});

struct VirtualFileMeta {
    size: i64,
    attrs: u32,
}

pub struct VirtualFileSystem {
    file_meta: Mutex<HashMap<usize, VirtualFileMeta>>,
    file_handle_seed: AtomicU64,
}

impl VirtualFileSystem {
    pub fn new() -> Self {
        Self {
            file_meta: Mutex::new(HashMap::new()),
            file_handle_seed: AtomicU64::new(FILE_HANDLE_SEED),
        }
    }

    pub fn is_virtual_path(path: &[u16]) -> bool {
        let normalized = normalize_path(path);
        normalized.starts_with(&NORMALIZED_VIRTUAL_PATH[..])
    }

    pub fn is_virtual_directory(path: &[u16]) -> bool {
        let normalized = normalize_path(path);
        normalized == NORMALIZED_VIRTUAL_PATH[..]
    }

    pub fn is_virtual_file(path: &[u16]) -> bool {
        let normalized = normalize_path(path);
        if normalized == NORMALIZED_VIRTUAL_PATH[..] {
            return false;
        }
        NORMALIZED_VIRTUAL_FILES
            .iter()
            .any(|f| &normalized[..] == &f[..])
    }

    pub fn is_virtual_path_ptr(path: *const u16) -> bool {
        unsafe { Self::is_virtual_path(wide_ptr_to_slice(path)) }
    }

    pub fn is_virtual_directory_ptr(path: *const u16) -> bool {
        unsafe { Self::is_virtual_directory(wide_ptr_to_slice(path)) }
    }

    pub fn is_virtual_file_ptr(path: *const u16) -> bool {
        unsafe { Self::is_virtual_file(wide_ptr_to_slice(path)) }
    }

    pub fn is_target_registry_key(key: usize, sub_key: *const u16) -> bool {
        key == HKEY_LOCAL_MACHINE && wide_eq_ptr(sub_key, &TARGET_REGISTRY_KEY)
    }

    pub fn make_virtual_file_handle(&self, is_directory: bool) -> usize {
        let handle = (self
            .file_handle_seed
            .fetch_add(FILE_HANDLE_INCREMENT, Ordering::SeqCst)
            + FILE_HANDLE_INCREMENT) as usize;
        let meta = VirtualFileMeta {
            size: if is_directory { 0 } else { 1024 },
            attrs: if is_directory {
                FILE_ATTRIBUTE_DIRECTORY
            } else {
                FILE_ATTRIBUTE_NORMAL
            },
        };
        self.file_meta.lock().unwrap().insert(handle, meta);
        handle
    }

    pub fn get_file_meta(&self, handle: usize) -> Option<(i64, u32)> {
        self.file_meta
            .lock()
            .unwrap()
            .get(&handle)
            .map(|m| (m.size, m.attrs))
    }

    pub fn remove_file_handle(&self, handle: usize) -> bool {
        self.file_meta.lock().unwrap().remove(&handle).is_some()
    }

    pub fn virtual_key() -> usize {
        VIRTUAL_KEY_VALUE
    }

    pub fn target_registry_value() -> &'static [u16] {
        &TARGET_REGISTRY_VALUE
    }

    pub fn virtual_path() -> &'static [u16] {
        &VIRTUAL_PATH
    }

    pub fn create_virtual_file_handle(file_name: *const u16) -> usize {
        if Self::is_virtual_directory_ptr(file_name) {
            return VFS.make_virtual_file_handle(true);
        }
        if Self::is_virtual_file_ptr(file_name) {
            return VFS.make_virtual_file_handle(false);
        }
        unsafe { SetLastError(ERROR_FILE_NOT_FOUND) };
        INVALID_HANDLE_VALUE
    }
}

pub static VFS: LazyLock<VirtualFileSystem> = LazyLock::new(VirtualFileSystem::new);

unsafe extern "system" {
    fn GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: *mut FileTime);
    fn SetLastError(error: u32);
}

pub fn get_current_file_time() -> FileTime {
    let mut ft = FileTime::default();
    unsafe { GetSystemTimeAsFileTime(&mut ft) };
    ft
}

pub fn get_current_file_time_i64() -> i64 {
    let ft = get_current_file_time();
    (ft.high_date_time as i64) << 32 | ft.low_date_time as i64
}
