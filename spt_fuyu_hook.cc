// Copyright (c) 2025 渟雲. All rights reserved.
//
// Licensed under the TOSSRCU 2025.9 License (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  https://raw.githubusercontent.com/M3351AN/M3351AN/9e7630a8511b8306c62952ca1a4f1ce0cc5b784a/LICENSE
//
// -----------------------------------------------------------------------------
// File: spt_fuyu_hook.cc
// Author: 渟雲(quq[at]outlook.it)
// Date: 2025-11-30
//
// Description:
//   This file includes functions of SPT Fuyu hooks.
//
// -----------------------------------------------------------------------------

#include "pch.h"
#ifdef NDEBUG
#include "./dll_proxy.h"
#endif
#include "./MinHook.h"

namespace build {
constexpr wchar_t kVirtualPath[] = L"A:\\SPTFuyuVirturalPath";

constexpr wchar_t kTargetRegistryKey[] =
    L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\"
    L"EscapeFromTarkov";
constexpr wchar_t kTargetRegistryValue[] = L"InstallLocation";

static const std::vector<std::wstring> kVirtualFiles = {
    L"BattlEye\\BEClient_x64.dll",
    L"ConsistencyInfo",
    L"Uninstall.exe",
    L"UnityCrashHandler64.exe",
    L"UnityPlayer.dll",
    L"WinPixEventRuntime.dll",
    L"Escapefromtarkov.exe"};
}  // namespace build

namespace spt_fuyu {

typedef long NTSTATUS;
constexpr NTSTATUS kStatusSuccess = 0x00000000L;
constexpr NTSTATUS kStatusObjectNameNotFound = 0xC0000034L;

typedef struct _UNICODE_STRING {
  USHORT length;
  USHORT maximum_length;
  PWSTR buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _OBJECT_ATTRIBUTES {
  ULONG length;
  HANDLE root_directory;
  PUNICODE_STRING object_name;
  ULONG attributes;
  PVOID security_descriptor;
  PVOID security_quality_of_service;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef struct _FILE_BASIC_INFORMATION {
  LARGE_INTEGER creation_time;
  LARGE_INTEGER last_access_time;
  LARGE_INTEGER last_write_time;
  LARGE_INTEGER change_time;
  ULONG file_attributes;
} FILE_BASIC_INFORMATION, *PFILE_BASIC_INFORMATION;

typedef enum _FILE_INFO_BY_HANDLE_CLASS {
  FileBasicInfo = 0,
  FileStandardInfo = 1
} FILE_INFO_BY_HANDLE_CLASS;

typedef struct _FILE_STANDARD_INFO {
  LARGE_INTEGER AllocationSize;
  LARGE_INTEGER EndOfFile;
  DWORD NumberOfLinks;
  BOOLEAN DeletePending;
  BOOLEAN Directory;
} FILE_STANDARD_INFO, *PFILE_STANDARD_INFO;

typedef struct _FILE_BASIC_INFO {
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  DWORD FileAttributes;
} FILE_BASIC_INFO, *PFILE_BASIC_INFO;

// Function pointer types
typedef NTSTATUS(WINAPI* NtQueryDirectoryFileFunc)(HANDLE, HANDLE, PVOID, PVOID,
                                                   PVOID, PVOID, ULONG, ULONG,
                                                   BOOLEAN, PUNICODE_STRING,
                                                   BOOLEAN);
typedef LSTATUS(WINAPI* RegOpenKeyExWFunc)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY);
typedef LSTATUS(WINAPI* RegQueryValueExWFunc)(HKEY, LPCWSTR, LPDWORD, LPDWORD,
                                              LPBYTE, LPDWORD);
typedef LSTATUS(WINAPI* RegCloseKeyFunc)(HKEY);
typedef HANDLE(WINAPI* CreateFileWFunc)(LPCWSTR, DWORD, DWORD,
                                        LPSECURITY_ATTRIBUTES, DWORD, DWORD,
                                        HANDLE);
typedef BOOL(WINAPI* GetFileAttributesExWFunc)(LPCWSTR, GET_FILEEX_INFO_LEVELS,
                                               LPVOID);
typedef NTSTATUS(WINAPI* NtQueryAttributesFileFunc)(POBJECT_ATTRIBUTES,
                                                    PFILE_BASIC_INFORMATION);
typedef BOOL(WINAPI* VerQueryValueWFunc)(LPCVOID pBlock, LPCWSTR lpSubBlock,
                                         LPVOID* lplpBuffer, PUINT puLen);
typedef DWORD(WINAPI* GetFileVersionInfoSizeExWFunc)(DWORD dwFlags,
                                                     LPCWSTR lptstrFilename,
                                                     LPDWORD lpdwHandle);
typedef BOOL(WINAPI* GetFileVersionInfoExWFunc)(DWORD dwFlags,
                                                LPCWSTR lptstrFilename,
                                                DWORD dwHandle, DWORD dwLen,
                                                LPVOID lpData);
// Original function pointers
static RegOpenKeyExWFunc original_reg_open_key_ex_w = nullptr;
static RegQueryValueExWFunc original_reg_query_value_ex_w = nullptr;
static RegCloseKeyFunc original_reg_close_key = nullptr;
static CreateFileWFunc original_create_file_w = nullptr;
static GetFileAttributesExWFunc original_get_file_attributes_ex_w = nullptr;
static NtQueryAttributesFileFunc original_nt_query_attributes_file = nullptr;
static BOOL(WINAPI* original_close_handle)(HANDLE) = nullptr;
static HANDLE(WINAPI* original_create_file2)(LPCWSTR, DWORD, DWORD, DWORD,
                                             LPVOID) = nullptr;
static BOOL(WINAPI* original_get_file_information_by_handle_ex)(
    HANDLE, FILE_INFO_BY_HANDLE_CLASS, LPVOID, DWORD) = nullptr;
static NtQueryDirectoryFileFunc original_nt_query_directory_file = nullptr;
static VerQueryValueWFunc original_ver_query_value_w = nullptr;
static GetFileVersionInfoSizeExWFunc original_get_file_version_info_size_ex_w =
    nullptr;
static GetFileVersionInfoExWFunc original_get_file_version_info_ex_w = nullptr;

struct VirtualFileMeta {
  LARGE_INTEGER size;
  DWORD attrs;
};

class VirtualFileSystem {
 private:
  std::unordered_map<HANDLE, VirtualFileMeta> file_meta_;
  std::atomic<uint64_t> file_handle_seed_{0xBEEF};
  HKEY virtual_key_ = reinterpret_cast<HKEY>(0xDEADBEEF);

 public:
  // Path utilities
  static std::wstring NormalizePath(LPCWSTR path) {
    if (!path) return L"";
    std::wstring result(path);
    std::transform(result.begin(), result.end(), result.begin(), ::towlower);

    if (result.rfind(L"\\\\?\\", 0) == 0) {
      result = result.substr(4);
    }
    if (result.length() > 3 && result.back() == L'\\') {
      result.pop_back();
    }
    std::replace(result.begin(), result.end(), L'/', L'\\');
    return result;
  }

  static bool IsVirtualPath(LPCWSTR path) {
    const std::wstring req = NormalizePath(path);
    const std::wstring root = NormalizePath(build::kVirtualPath);
    return req.rfind(root, 0) == 0;
  }

  static bool IsVirtualDirectory(LPCWSTR path) {
    const std::wstring req = NormalizePath(path);
    const std::wstring root = NormalizePath(build::kVirtualPath);
    return req == root;
  }

  static bool IsVirtualFile(LPCWSTR file_name) {
    const std::wstring req = NormalizePath(file_name);
    const std::wstring root = NormalizePath(build::kVirtualPath);

    if (req == root) return false;

    for (const auto& vf : build::kVirtualFiles) {
      const std::wstring full = root + L"\\" + NormalizePath(vf.c_str());
      if (req == full) return true;
    }
    return false;
  }

  static bool IsTargetRegistryKey(HKEY key, LPCWSTR sub_key) {
    return key == HKEY_LOCAL_MACHINE && sub_key &&
           wcscmp(sub_key, build::kTargetRegistryKey) == 0;
  }

  // File handle management
  HANDLE MakeVirtualFileHandle(bool is_directory = false) {
    HANDLE handle = reinterpret_cast<HANDLE>(
        static_cast<uintptr_t>(file_handle_seed_ += 0x11));
    LARGE_INTEGER size;
    size.QuadPart = is_directory ? 0 : 1024;
    file_meta_[handle] = {
        size, static_cast<DWORD>(is_directory ? FILE_ATTRIBUTE_DIRECTORY
                                              : FILE_ATTRIBUTE_NORMAL)};
    return handle;
  }

  VirtualFileMeta* GetFileMeta(HANDLE handle) {
    auto it = file_meta_.find(handle);
    return it != file_meta_.end() ? &it->second : nullptr;
  }

  bool RemoveFileHandle(HANDLE handle) { return file_meta_.erase(handle) > 0; }

  HKEY GetVirtualKey() const { return virtual_key_; }

  // Common file time utility
  static void GetCurrentFileTime(LARGE_INTEGER& time) {
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    time.LowPart = ft.dwLowDateTime;
    time.HighPart = ft.dwHighDateTime;
  }

  static void GetCurrentFileTime(FILETIME& ft) { GetSystemTimeAsFileTime(&ft); }
};

static VirtualFileSystem g_vfs;

// Registry hooks
LSTATUS WINAPI HookedRegOpenKeyExW(HKEY key, LPCWSTR sub_key, DWORD options,
                                   REGSAM desired, PHKEY result) {
  if (VirtualFileSystem::IsTargetRegistryKey(key, sub_key)) {
    *result = g_vfs.GetVirtualKey();
    return ERROR_SUCCESS;
  }
  return original_reg_open_key_ex_w(key, sub_key, options, desired, result);
}

LSTATUS WINAPI HookedRegQueryValueExW(HKEY key, LPCWSTR value_name,
                                      LPDWORD reserved, LPDWORD type,
                                      LPBYTE data, LPDWORD data_size) {
  if (key == g_vfs.GetVirtualKey() && value_name &&
      wcscmp(value_name, build::kTargetRegistryValue) == 0) {
    const size_t required_size =
        (wcslen(build::kVirtualPath) + 1) * sizeof(wchar_t);

    if (data && data_size && *data_size >= required_size) {
      wcscpy_s(reinterpret_cast<wchar_t*>(data), *data_size / sizeof(wchar_t),
               build::kVirtualPath);
      if (type) *type = REG_SZ;
      *data_size = static_cast<DWORD>(required_size);
      return ERROR_SUCCESS;
    } else if (data_size) {
      *data_size = static_cast<DWORD>(required_size);
      return ERROR_MORE_DATA;
    }
  }
  return original_reg_query_value_ex_w(key, value_name, reserved, type, data,
                                       data_size);
}

LSTATUS WINAPI HookedRegCloseKey(HKEY key) {
  return (key == g_vfs.GetVirtualKey()) ? ERROR_SUCCESS
                                        : original_reg_close_key(key);
}

// Common virtual file creation logic
static HANDLE CreateVirtualFileHandle(LPCWSTR file_name) {
  if (VirtualFileSystem::IsVirtualDirectory(file_name)) {
    return g_vfs.MakeVirtualFileHandle(true);
  }

  if (VirtualFileSystem::IsVirtualFile(file_name)) {
    return g_vfs.MakeVirtualFileHandle(false);
  }

  SetLastError(ERROR_FILE_NOT_FOUND);
  return INVALID_HANDLE_VALUE;
}

// File system hooks
HANDLE WINAPI HookedCreateFileW(LPCWSTR file_name, DWORD desired_access,
                                DWORD share_mode, LPSECURITY_ATTRIBUTES sa,
                                DWORD creation_disposition,
                                DWORD flags_and_attributes,
                                HANDLE template_file) {
  if (!VirtualFileSystem::IsVirtualPath(file_name)) {
    return original_create_file_w(file_name, desired_access, share_mode, sa,
                                  creation_disposition, flags_and_attributes,
                                  template_file);
  }

  HANDLE handle = CreateVirtualFileHandle(file_name);
  if (handle != INVALID_HANDLE_VALUE) {
    SetLastError(ERROR_SUCCESS);
  }
  return handle;
}

HANDLE WINAPI HookedCreateFile2(LPCWSTR file_name, DWORD desired_access,
                                DWORD share_mode, DWORD creation_disposition,
                                LPVOID params) {
  if (!VirtualFileSystem::IsVirtualPath(file_name)) {
    return original_create_file2(file_name, desired_access, share_mode,
                                 creation_disposition, params);
  }

  HANDLE handle = CreateVirtualFileHandle(file_name);
  if (handle != INVALID_HANDLE_VALUE) {
    SetLastError(ERROR_SUCCESS);
  }
  return handle;
}

BOOL WINAPI HookedGetFileAttributesExW(LPCWSTR file_name,
                                       GET_FILEEX_INFO_LEVELS level,
                                       LPVOID info) {
  if (!VirtualFileSystem::IsVirtualPath(file_name) ||
      level != GetFileExInfoStandard || !info) {
    return original_get_file_attributes_ex_w(file_name, level, info);
  }

  auto* attr = reinterpret_cast<WIN32_FILE_ATTRIBUTE_DATA*>(info);
  FILETIME now;
  VirtualFileSystem::GetCurrentFileTime(now);
  attr->ftCreationTime = now;
  attr->ftLastAccessTime = now;
  attr->ftLastWriteTime = now;

  if (VirtualFileSystem::IsVirtualDirectory(file_name)) {
    attr->dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
    attr->nFileSizeLow = 0;
    attr->nFileSizeHigh = 0;
  } else if (VirtualFileSystem::IsVirtualFile(file_name)) {
    attr->dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
    attr->nFileSizeLow = 1024;
    attr->nFileSizeHigh = 0;
  } else {
    SetLastError(ERROR_FILE_NOT_FOUND);
    return FALSE;
  }

  SetLastError(ERROR_SUCCESS);
  return TRUE;
}

NTSTATUS WINAPI HookedNtQueryAttributesFile(
    POBJECT_ATTRIBUTES object_attributes, PFILE_BASIC_INFORMATION file_info) {
  if (object_attributes && object_attributes->object_name) {
    std::wstring file_path(
        object_attributes->object_name->buffer,
        object_attributes->object_name->length / sizeof(wchar_t));

    if (VirtualFileSystem::IsVirtualPath(file_path.c_str())) {
      if (file_info) {
        file_info->file_attributes =
            VirtualFileSystem::IsVirtualDirectory(file_path.c_str())
                ? FILE_ATTRIBUTE_DIRECTORY
                : FILE_ATTRIBUTE_NORMAL;

        LARGE_INTEGER time;
        VirtualFileSystem::GetCurrentFileTime(time);
        file_info->creation_time = time;
        file_info->last_access_time = time;
        file_info->last_write_time = time;
        file_info->change_time = time;

        return kStatusSuccess;
      }
      return kStatusObjectNameNotFound;
    }
  }
  return original_nt_query_attributes_file(object_attributes, file_info);
}

BOOL WINAPI HookedCloseHandle(HANDLE hObject) {
  return g_vfs.RemoveFileHandle(hObject) ? TRUE
                                         : original_close_handle(hObject);
}

BOOL WINAPI HookedGetFileInformationByHandleEx(
    HANDLE hFile, FILE_INFO_BY_HANDLE_CLASS infoClass, LPVOID lpFileInformation,
    DWORD dwBufferSize) {
  VirtualFileMeta* meta = g_vfs.GetFileMeta(hFile);
  if (!meta) {
    return original_get_file_information_by_handle_ex(
        hFile, infoClass, lpFileInformation, dwBufferSize);
  }

  if (infoClass == FileStandardInfo) {
    if (dwBufferSize < sizeof(FILE_STANDARD_INFO)) {
      SetLastError(ERROR_INSUFFICIENT_BUFFER);
      return FALSE;
    }
    auto* stdinfo = reinterpret_cast<PFILE_STANDARD_INFO>(lpFileInformation);
    stdinfo->AllocationSize = meta->size;
    stdinfo->EndOfFile = meta->size;
    stdinfo->NumberOfLinks = 1;
    stdinfo->DeletePending = FALSE;
    stdinfo->Directory =
        (meta->attrs & FILE_ATTRIBUTE_DIRECTORY) ? TRUE : FALSE;
    return TRUE;
  }

  if (infoClass == FileBasicInfo) {
    if (dwBufferSize < sizeof(FILE_BASIC_INFO)) {
      SetLastError(ERROR_INSUFFICIENT_BUFFER);
      return FALSE;
    }
    auto* binfo = reinterpret_cast<PFILE_BASIC_INFO>(lpFileInformation);
    VirtualFileSystem::GetCurrentFileTime(binfo->CreationTime);
    binfo->LastAccessTime = binfo->CreationTime;
    binfo->LastWriteTime = binfo->CreationTime;
    binfo->ChangeTime = binfo->CreationTime;
    binfo->FileAttributes = meta->attrs;
    return TRUE;
  }

  return original_get_file_information_by_handle_ex(
      hFile, infoClass, lpFileInformation, dwBufferSize);
}

NTSTATUS WINAPI HookedNtQueryDirectoryFile(
    HANDLE FileHandle, HANDLE Event, PVOID ApcRoutine, PVOID ApcContext,
    PVOID IoStatusBlock, PVOID FileInformation, ULONG Length,
    ULONG FileInformationClass, BOOLEAN ReturnSingleEntry,
    PUNICODE_STRING FileName, BOOLEAN RestartScan) {
  VirtualFileMeta* meta = g_vfs.GetFileMeta(FileHandle);
  if (meta && (meta->attrs & FILE_ATTRIBUTE_DIRECTORY)) {
    return 0x80000006L;  // STATUS_NO_MORE_FILES
  }

  return original_nt_query_directory_file(
      FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, FileInformation,
      Length, FileInformationClass, ReturnSingleEntry, FileName, RestartScan);
}

BOOL WINAPI HookedVerQueryValueW(LPCVOID pBlock, LPCWSTR lpSubBlock,
                                 LPVOID* lplpBuffer, PUINT puLen) {
  if (lpSubBlock && wcsstr(lpSubBlock, L"ProductVersion")) {
    static wchar_t fakeProduct[] = L"99.0.0.0";
    *lplpBuffer = fakeProduct;
    if (puLen) *puLen = (UINT)wcslen(fakeProduct);
    return TRUE;
  }
  if (lpSubBlock && wcsstr(lpSubBlock, L"FileVersion")) {
    static wchar_t fakeFile[] = L"99.0.0.0";
    *lplpBuffer = fakeFile;
    if (puLen) *puLen = (UINT)wcslen(fakeFile);
    return TRUE;
  }
  return FALSE;
}

DWORD WINAPI HookedGetFileVersionInfoSizeExW(DWORD dwFlags,
                                             LPCWSTR lptstrFilename,
                                             LPDWORD lpdwHandle) {
  if (VirtualFileSystem::IsVirtualFile(lptstrFilename)) {
    if (lpdwHandle) *lpdwHandle = 0;
    return 256;
  }
  return original_get_file_version_info_size_ex_w(dwFlags, lptstrFilename,
                                                  lpdwHandle);
}

BOOL WINAPI HookedGetFileVersionInfoExW(DWORD dwFlags, LPCWSTR lptstrFilename,
                                        DWORD dwHandle, DWORD dwLen,
                                        LPVOID lpData) {
  if (VirtualFileSystem::IsVirtualFile(lptstrFilename)) {
    return TRUE;
  }
  return original_get_file_version_info_ex_w(dwFlags, lptstrFilename, dwHandle,
                                             dwLen, lpData);
}


// Helper function to get original function addresses
FARPROC GetOriginalFunction(const char* func_name) {
  auto load_module = [](const char* dll) -> HMODULE {
    HMODULE h = GetModuleHandleA(dll);
    return h ? h : LoadLibraryA(dll);
  };

  const char* dll_name = "KernelBase.dll";
  if (strstr(func_name, "Reg")) {
    dll_name = "advapi32.dll";
  } else if (strstr(func_name, "Nt")) {
    dll_name = "ntdll.dll";
  } else if (strstr(func_name, "GetFileVersionInfo") ||
             strstr(func_name, "VerQueryValue")) {
    dll_name = "version.dll";
  }

  HMODULE module = load_module(dll_name);
  if (!module && strcmp(dll_name, "KernelBase.dll") == 0) {
    module = load_module("kernel32.dll");
  }

  return module ? GetProcAddress(module, func_name) : nullptr;
}

// Hook management
struct HookDefinition {
  const char* name;
  LPVOID* original;
  LPVOID hook;
};

bool InstallSingleHook(const HookDefinition& hook) {
  FARPROC target = GetOriginalFunction(hook.name);
  if (!target) return true;  // Skip if function not found

  return MH_CreateHook(target, hook.hook,
                       reinterpret_cast<LPVOID*>(hook.original)) == MH_OK;
}

bool InstallHooks() {
  if (MH_Initialize() != MH_OK) {
    return false;
  }

  static const HookDefinition hooks[] = {
      {"RegOpenKeyExW", reinterpret_cast<LPVOID*>(&original_reg_open_key_ex_w),
       reinterpret_cast<LPVOID>(&HookedRegOpenKeyExW)},
      {"RegQueryValueExW",
       reinterpret_cast<LPVOID*>(&original_reg_query_value_ex_w),
       reinterpret_cast<LPVOID>(&HookedRegQueryValueExW)},
      {"RegCloseKey", reinterpret_cast<LPVOID*>(&original_reg_close_key),
       reinterpret_cast<LPVOID>(&HookedRegCloseKey)},
      {"CreateFileW", reinterpret_cast<LPVOID*>(&original_create_file_w),
       reinterpret_cast<LPVOID>(&HookedCreateFileW)},
      {"NtQueryAttributesFile",
       reinterpret_cast<LPVOID*>(&original_nt_query_attributes_file),
       reinterpret_cast<LPVOID>(&HookedNtQueryAttributesFile)},
      {"GetFileAttributesExW",
       reinterpret_cast<LPVOID*>(&original_get_file_attributes_ex_w),
       reinterpret_cast<LPVOID>(&HookedGetFileAttributesExW)},
      {"CloseHandle", reinterpret_cast<LPVOID*>(&original_close_handle),
       reinterpret_cast<LPVOID>(&HookedCloseHandle)},
      {"CreateFile2", reinterpret_cast<LPVOID*>(&original_create_file2),
       reinterpret_cast<LPVOID>(&HookedCreateFile2)},
      {"GetFileInformationByHandleEx",
       reinterpret_cast<LPVOID*>(&original_get_file_information_by_handle_ex),
       reinterpret_cast<LPVOID>(&HookedGetFileInformationByHandleEx)},
      {"NtQueryDirectoryFile",
       reinterpret_cast<LPVOID*>(&original_nt_query_directory_file),
       reinterpret_cast<LPVOID>(&HookedNtQueryDirectoryFile)} ,
      /*{"VerQueryValueW",
      reinterpret_cast<LPVOID*>(&original_ver_query_value_w),
       reinterpret_cast<LPVOID>(&HookedVerQueryValueW)},
      {"GetFileVersionInfoSizeExW",
       reinterpret_cast<LPVOID*>(&original_get_file_version_info_size_ex_w),
       reinterpret_cast<LPVOID>(&HookedGetFileVersionInfoSizeExW)},
      {"GetFileVersionInfoExW",
       reinterpret_cast<LPVOID*>(&original_get_file_version_info_ex_w),
       reinterpret_cast<LPVOID>(&HookedGetFileVersionInfoExW)},*/
  };

  for (const auto& hook : hooks) {
    if (!InstallSingleHook(hook)) {
      return false;
    }
  }

  return MH_EnableHook(MH_ALL_HOOKS) == MH_OK;
}

void RemoveHooks() {
  MH_DisableHook(MH_ALL_HOOKS);
  MH_Uninitialize();
}

// Window title management
void ChangeWindowTitleWorker() {
  HWND window = nullptr;
  while ((window = FindWindowW(nullptr, L"SPT.Launcher")) == nullptr) {
    Sleep(200);
  }
  SetWindowTextW(window, L"SPT.Fuyu.Launcher");
}

void ChangeWindowTitle() { std::thread(ChangeWindowTitleWorker).detach(); }

void Initialize() {
  std::thread([] {
    if (InstallHooks()) {
      ChangeWindowTitle();
    }
  }).detach();
}

}  // namespace spt_fuyu

// DLL entry point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
      DisableThreadLibraryCalls(hModule);
#ifdef NDEBUG
      char path[MAX_PATH];
      GetWindowsDirectoryA(path, sizeof(path));
      strcat_s(path, "\\System32\\user32.dll");
      user32.dll = LoadLibraryA(path);
      setupFunctions();
#endif
      spt_fuyu::Initialize();
      break;

    case DLL_PROCESS_DETACH:
      spt_fuyu::RemoveHooks();
#ifdef NDEBUG
      FreeLibrary(user32.dll);
#endif
      break;
  }
  return TRUE;
}
