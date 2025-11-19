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
// Date: 2025-11-19
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
    L"BattlEye\\BEClient_x64.dll", L"ConsistencyInfo", L"Uninstall.exe",
    L"UnityCrashHandler64.exe", L"WinPixEventRuntime.dll",
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

typedef NTSTATUS(WINAPI* NtQueryDirectoryFileFunc)(
    HANDLE FileHandle, HANDLE Event,
    PVOID ApcRoutine,  // simplified
    PVOID ApcContext, PVOID IoStatusBlock, PVOID FileInformation, ULONG Length,
    ULONG FileInformationClass, BOOLEAN ReturnSingleEntry,
    PUNICODE_STRING FileName, BOOLEAN RestartScan);

typedef LSTATUS(WINAPI* RegOpenKeyExWFunc)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY);
typedef LSTATUS(WINAPI* RegQueryValueExWFunc)(HKEY, LPCWSTR, LPDWORD, LPDWORD,
                                              LPBYTE, LPDWORD);
typedef LSTATUS(WINAPI* RegCloseKeyFunc)(HKEY);
typedef HANDLE(WINAPI* CreateFileWFunc)(LPCWSTR, DWORD, DWORD,
                                        LPSECURITY_ATTRIBUTES, DWORD, DWORD,
                                        HANDLE);
typedef BOOL(WINAPI* GetFileAttributesExWFunc)(
    LPCWSTR file_name, GET_FILEEX_INFO_LEVELS info_level_id,
    LPVOID file_information);
typedef NTSTATUS(WINAPI* NtQueryAttributesFileFunc)(POBJECT_ATTRIBUTES,
                                                    PFILE_BASIC_INFORMATION);
typedef struct _CREATEFILE2_EXTENDED_PARAMETERS {
  DWORD dwSize;
  DWORD dwFileAttributes;
  DWORD dwFileFlags;
  DWORD dwSecurityQosFlags;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  HANDLE hTemplateFile;
} CREATEFILE2_EXTENDED_PARAMETERS, *LPCREATEFILE2_EXTENDED_PARAMETERS;

static RegOpenKeyExWFunc original_reg_open_key_ex_w = nullptr;
static RegQueryValueExWFunc original_reg_query_value_ex_w = nullptr;
static RegCloseKeyFunc original_reg_close_key = nullptr;
static CreateFileWFunc original_create_file_w = nullptr;
static GetFileAttributesExWFunc original_get_file_attributes_ex_w = nullptr;
static NtQueryAttributesFileFunc original_nt_query_attributes_file = nullptr;
static BOOL(WINAPI* original_close_handle)(HANDLE) = nullptr;
static HANDLE(WINAPI* original_create_file2)(
    LPCWSTR, DWORD, DWORD, DWORD, LPCREATEFILE2_EXTENDED_PARAMETERS) = nullptr;
static BOOL(WINAPI* original_get_file_information_by_handle_ex)(
    HANDLE, FILE_INFO_BY_HANDLE_CLASS, LPVOID, DWORD) = nullptr;
static NtQueryDirectoryFileFunc original_nt_query_directory_file = nullptr;

struct VirtualFileMeta {
  LARGE_INTEGER size;
  DWORD attrs;
};

static std::unordered_map<HANDLE, VirtualFileMeta> g_file_meta;
static std::atomic<uint64_t> g_file_handle_seed{0xBEEF};

static HANDLE MakeVirtualFileHandle() {
  return reinterpret_cast<HANDLE>((g_file_handle_seed += 0x11));
}


static HKEY g_virtual_key = reinterpret_cast<HKEY>(0xDEADBEEF);

bool IsTargetRegistryKey(HKEY key, LPCWSTR sub_key) {
  if (key != HKEY_LOCAL_MACHINE) return false;
  if (!sub_key) return false;
  return wcscmp(sub_key, build::kTargetRegistryKey) == 0;
}

std::wstring NormalizePath(LPCWSTR path) {
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

bool IsVirtualPath(LPCWSTR path) {
  if (!path) return false;
  const std::wstring req = NormalizePath(path);
  const std::wstring root = NormalizePath(build::kVirtualPath);
  return req.rfind(root, 0) == 0;
}

bool IsVirtualDirectory(LPCWSTR path) {
  if (!path) return false;
  const std::wstring req = NormalizePath(path);
  const std::wstring root = NormalizePath(build::kVirtualPath);
  return req == root;
}

bool IsVirtualFile(LPCWSTR file_name) {
  if (!file_name) return false;
  const std::wstring req = NormalizePath(file_name);
  const std::wstring root = NormalizePath(build::kVirtualPath);
  if (req == root) return false;
  for (const auto& vf : build::kVirtualFiles) {
    const std::wstring full = root + L"\\" + NormalizePath(vf.c_str());
    if (req == full) return true;
  }
  return false;
}


LSTATUS WINAPI HookedRegOpenKeyExW(HKEY key, LPCWSTR sub_key, DWORD options,
                                   REGSAM desired, PHKEY result) {
  if (IsTargetRegistryKey(key, sub_key)) {
    *result = g_virtual_key;
    return ERROR_SUCCESS;
  }
  return original_reg_open_key_ex_w(key, sub_key, options, desired, result);
}

LSTATUS WINAPI HookedRegQueryValueExW(HKEY key, LPCWSTR value_name,
                                      LPDWORD reserved, LPDWORD type,
                                      LPBYTE data, LPDWORD data_size) {
  if (key == g_virtual_key && value_name &&
      wcscmp(value_name, build::kTargetRegistryValue) == 0) {
    if (data && data_size &&
        *data_size >= (wcslen(build::kVirtualPath) + 1) * sizeof(wchar_t)) {
      wcscpy_s(reinterpret_cast<wchar_t*>(data), *data_size / sizeof(wchar_t),
               build::kVirtualPath);
      if (type) *type = REG_SZ;
      *data_size = (wcslen(build::kVirtualPath) + 1) * sizeof(wchar_t);
      return ERROR_SUCCESS;
    } else if (data_size) {
      *data_size = (wcslen(build::kVirtualPath) + 1) * sizeof(wchar_t);
      return ERROR_MORE_DATA;
    }
  }
  return original_reg_query_value_ex_w(key, value_name, reserved, type, data,
                                       data_size);
}

LSTATUS WINAPI HookedRegCloseKey(HKEY key) {
  if (key == g_virtual_key) {
    return ERROR_SUCCESS;
  }
  return original_reg_close_key(key);
}

HANDLE WINAPI HookedCreateFileW(LPCWSTR file_name, DWORD desired_access,
                                DWORD share_mode, LPSECURITY_ATTRIBUTES sa,
                                DWORD creation_disposition,
                                DWORD flags_and_attributes,
                                HANDLE template_file) {
  if (!IsVirtualPath(file_name)) {
    return original_create_file_w(file_name, desired_access, share_mode, sa,
                                  creation_disposition, flags_and_attributes,
                                  template_file);
  }

  if (IsVirtualDirectory(file_name)) {
    HANDLE h = MakeVirtualFileHandle();
    LARGE_INTEGER sz;
    sz.QuadPart = 0;
    g_file_meta[h] = {sz, FILE_ATTRIBUTE_DIRECTORY};
    SetLastError(ERROR_SUCCESS);
    return h;
  }

  if (IsVirtualFile(file_name)) {
    HANDLE h = MakeVirtualFileHandle();
    LARGE_INTEGER sz;
    sz.QuadPart = 1024;
    g_file_meta[h] = {sz, FILE_ATTRIBUTE_NORMAL};
    SetLastError(ERROR_SUCCESS);
    return h;
  }

  SetLastError(ERROR_FILE_NOT_FOUND);
  return INVALID_HANDLE_VALUE;
}

BOOL WINAPI HookedGetFileAttributesExW(LPCWSTR file_name,
                                       GET_FILEEX_INFO_LEVELS level,
                                       LPVOID info) {
  if (!IsVirtualPath(file_name)) {
    return original_get_file_attributes_ex_w(file_name, level, info);
  }
  if (level != GetFileExInfoStandard || !info) {
    SetLastError(ERROR_INVALID_PARAMETER);
    return FALSE;
  }
  auto* attr = reinterpret_cast<WIN32_FILE_ATTRIBUTE_DATA*>(info);
  FILETIME now;
  GetSystemTimeAsFileTime(&now);
  attr->ftCreationTime = now;
  attr->ftLastAccessTime = now;
  attr->ftLastWriteTime = now;

  if (IsVirtualDirectory(file_name)) {
    attr->dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
    attr->nFileSizeLow = 0;
    attr->nFileSizeHigh = 0;
    SetLastError(ERROR_SUCCESS);
    return TRUE;
  }
  if (IsVirtualFile(file_name)) {
    attr->dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
    attr->nFileSizeLow = 1024;
    attr->nFileSizeHigh = 0;
    SetLastError(ERROR_SUCCESS);
    return TRUE;
  }
  SetLastError(ERROR_FILE_NOT_FOUND);
  return FALSE;
}

NTSTATUS WINAPI
HookedNtQueryAttributesFile(POBJECT_ATTRIBUTES object_attributes,
                            PFILE_BASIC_INFORMATION file_information) {
  if (object_attributes && object_attributes->object_name) {
    std::wstring file_path(
        object_attributes->object_name->buffer,
        object_attributes->object_name->length / sizeof(wchar_t));
    if (IsVirtualPath(file_path.c_str())) {
      if (IsVirtualFile(file_path.c_str())) {
        if (file_information) {
          if (IsVirtualDirectory(file_path.c_str())) {
            file_information->file_attributes = FILE_ATTRIBUTE_DIRECTORY;
          } else {
            file_information->file_attributes = FILE_ATTRIBUTE_NORMAL;
          }

          LARGE_INTEGER time;
          GetSystemTimeAsFileTime(reinterpret_cast<FILETIME*>(&time));
          file_information->creation_time = time;
          file_information->last_access_time = time;
          file_information->last_write_time = time;
          file_information->change_time = time;

          return kStatusSuccess;
        }
      } else {
        return kStatusObjectNameNotFound;
      }
    }
  }
  return original_nt_query_attributes_file(object_attributes, file_information);
}

BOOL WINAPI HookedCloseHandle(HANDLE hObject) {
  auto it = g_file_meta.find(hObject);
  if (it != g_file_meta.end()) {
    g_file_meta.erase(it);
    SetLastError(ERROR_SUCCESS);
    return TRUE;
  }
  return original_close_handle(hObject);
}

HANDLE WINAPI HookedCreateFile2(LPCWSTR file_name, DWORD desired_access,
                                DWORD share_mode, DWORD creation_disposition,
                                LPCREATEFILE2_EXTENDED_PARAMETERS params) {
  if (!IsVirtualPath(file_name)) {
    return original_create_file2(file_name, desired_access, share_mode,
                                 creation_disposition, params);
  }

  if (IsVirtualDirectory(file_name)) {
    HANDLE h = MakeVirtualFileHandle();
    LARGE_INTEGER sz;
    sz.QuadPart = 0;
    g_file_meta[h] = {sz, FILE_ATTRIBUTE_DIRECTORY};
    SetLastError(ERROR_SUCCESS);
    return h;
  }

  if (IsVirtualFile(file_name)) {
    HANDLE h = MakeVirtualFileHandle();
    LARGE_INTEGER sz;
    sz.QuadPart = 1024;
    g_file_meta[h] = {sz, FILE_ATTRIBUTE_NORMAL};
    SetLastError(ERROR_SUCCESS);
    return h;
  }

  SetLastError(ERROR_FILE_NOT_FOUND);
  return INVALID_HANDLE_VALUE;
}

BOOL WINAPI HookedGetFileInformationByHandleEx(
    HANDLE hFile, FILE_INFO_BY_HANDLE_CLASS infoClass, LPVOID lpFileInformation,
    DWORD dwBufferSize) {
  auto it = g_file_meta.find(hFile);
  if (it == g_file_meta.end()) {
    return original_get_file_information_by_handle_ex(
        hFile, infoClass, lpFileInformation, dwBufferSize);
  }

  const auto& meta = it->second;

  if (infoClass == FileStandardInfo) {
    if (dwBufferSize < sizeof(FILE_STANDARD_INFO)) {
      SetLastError(ERROR_INSUFFICIENT_BUFFER);
      return FALSE;
    }
    auto* stdinfo = reinterpret_cast<PFILE_STANDARD_INFO>(lpFileInformation);
    stdinfo->AllocationSize = meta.size;
    stdinfo->EndOfFile = meta.size;
    stdinfo->NumberOfLinks = 1;
    stdinfo->DeletePending = FALSE;
    stdinfo->Directory = (meta.attrs & FILE_ATTRIBUTE_DIRECTORY) ? TRUE : FALSE;
    return TRUE;
  }

  if (infoClass == FileBasicInfo) {
    if (dwBufferSize < sizeof(FILE_BASIC_INFO)) {
      SetLastError(ERROR_INSUFFICIENT_BUFFER);
      return FALSE;
    }
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    LARGE_INTEGER t;
    t.LowPart = static_cast<LONG>(ft.dwLowDateTime);
    t.HighPart = static_cast<LONG>(ft.dwHighDateTime);

    auto* binfo = reinterpret_cast<PFILE_BASIC_INFO>(lpFileInformation);
    binfo->CreationTime = t;
    binfo->LastAccessTime = t;
    binfo->LastWriteTime = t;
    binfo->ChangeTime = t;
    binfo->FileAttributes = meta.attrs;
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
  auto it = g_file_meta.find(FileHandle);
  if (it != g_file_meta.end() &&
      (it->second.attrs & FILE_ATTRIBUTE_DIRECTORY)) {
    return 0x80000006L;
  }

  return original_nt_query_directory_file(
      FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, FileInformation,
      Length, FileInformationClass, ReturnSingleEntry, FileName, RestartScan);
}

FARPROC GetOriginalFunction(const char* func_name) {
  auto load = [&](const char* dll) -> HMODULE {
    HMODULE h = GetModuleHandleA(dll);
    if (!h) h = LoadLibraryA(dll);
    return h;
  };
  HMODULE module = nullptr;

  if (strstr(func_name, "RegOpenKey") || strstr(func_name, "RegQueryValue") ||
      strstr(func_name, "RegCloseKey")) {
    module = load("advapi32.dll");
  } else if (strstr(func_name, "Nt")) {
    module = load("ntdll.dll");
  } else if (strstr(func_name, "CreateFile2") ||
             strstr(func_name, "CreateFile") ||
             strstr(func_name, "GetFileInformationByHandleEx") ||
             strstr(func_name, "GetFileAttributes") ||
             strstr(func_name, "FindFirstFileExFromApp") ||
             strstr(func_name, "FindFirstFileEx") ||
             strstr(func_name, "FindFirstFile") ||
             strstr(func_name, "FindNextFile") ||
             strstr(func_name, "FindClose") ||
             strstr(func_name, "CloseHandle")) {
    module = load("KernelBase.dll");
    if (!module) module = load("kernel32.dll");
  } else {
    module = load("KernelBase.dll");
    if (!module) module = load("kernel32.dll");
  }

  return module ? GetProcAddress(module, func_name) : nullptr;
}


bool InstallHooks() {
  if (MH_Initialize() != MH_OK) {
    return false;
  }

  FARPROC reg_open_key_ex_w = GetOriginalFunction("RegOpenKeyExW");
  FARPROC reg_open_key = GetOriginalFunction("RegOpenKeyW");
  FARPROC reg_query_value_ex_w = GetOriginalFunction("RegQueryValueExW");
  FARPROC reg_close_key = GetOriginalFunction("RegCloseKey");
  FARPROC create_file_w = GetOriginalFunction("CreateFileW");
  FARPROC nt_query_attributes_file =
      GetOriginalFunction("NtQueryAttributesFile");
  FARPROC get_file_attributes_ex_w =
      GetOriginalFunction("GetFileAttributesExW");
  FARPROC close_handle = GetOriginalFunction("CloseHandle");
  FARPROC create_file2 = GetOriginalFunction("CreateFile2");
  FARPROC get_file_info_by_handle =
      GetOriginalFunction("GetFileInformationByHandleEx");
  FARPROC nt_query_directory_file = GetOriginalFunction("NtQueryDirectoryFile");

  if (MH_CreateHook(reg_open_key_ex_w, &HookedRegOpenKeyExW,
                    reinterpret_cast<LPVOID*>(&original_reg_open_key_ex_w)) !=
      MH_OK) {
    return false;
  }

  if (MH_CreateHook(
          reg_query_value_ex_w, &HookedRegQueryValueExW,
          reinterpret_cast<LPVOID*>(&original_reg_query_value_ex_w)) != MH_OK) {
    return false;
  }

  if (MH_CreateHook(reg_close_key, &HookedRegCloseKey,
                    reinterpret_cast<LPVOID*>(&original_reg_close_key)) !=
      MH_OK) {
    return false;
  }

  if (MH_CreateHook(create_file_w, &HookedCreateFileW,
                    reinterpret_cast<LPVOID*>(&original_create_file_w)) !=
      MH_OK) {
    return false;
  }

  if (nt_query_attributes_file &&
      MH_CreateHook(nt_query_attributes_file, &HookedNtQueryAttributesFile,
                    reinterpret_cast<LPVOID*>(
                        &original_nt_query_attributes_file)) != MH_OK) {
  }

  if (get_file_attributes_ex_w &&
      MH_CreateHook(get_file_attributes_ex_w, &HookedGetFileAttributesExW,
                    reinterpret_cast<LPVOID*>(
                        &original_get_file_attributes_ex_w)) != MH_OK) {
  }

  if (close_handle && MH_CreateHook(close_handle, &HookedCloseHandle,
                                    reinterpret_cast<LPVOID*>(
                                        &original_close_handle)) != MH_OK) {
  }

  if (create_file2 && MH_CreateHook(create_file2, &HookedCreateFile2,
                                    reinterpret_cast<LPVOID*>(
                                        &original_create_file2)) != MH_OK) {
  }

  if (get_file_info_by_handle &&
      MH_CreateHook(
          get_file_info_by_handle, &HookedGetFileInformationByHandleEx,
          reinterpret_cast<LPVOID*>(
              &original_get_file_information_by_handle_ex)) != MH_OK) {
  }

  if (nt_query_directory_file &&
      MH_CreateHook(nt_query_directory_file, &HookedNtQueryDirectoryFile,
                    reinterpret_cast<LPVOID*>(
                        &original_nt_query_directory_file)) != MH_OK) {
  }

  if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
    return false;
  }

  return true;
}

void RemoveHooks() {
  MH_DisableHook(MH_ALL_HOOKS);
  MH_Uninitialize();
}

void ChangeWindowTitleWorker() {
  HWND window = nullptr;
  while ((window = FindWindowW(nullptr, L"SPT.Launcher")) == nullptr) {
    Sleep(200);
  }
  SetWindowTextW(window, L"SPT.Fuyu.Launcher");
}

void ChangeWindowTitle() {
  std::thread(ChangeWindowTitleWorker).detach();
}
void InitializeWorker() {
  if (InstallHooks()) {
    ChangeWindowTitle();
  }
}

void Initialize() { 
    std::thread(InitializeWorker).detach();
}
}  // namespace spt_fuyu

#ifdef NDEBUG
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
      char path[MAX_PATH];
      GetWindowsDirectoryA(path, sizeof(path));

      strcat_s(path, "\\System32\\user32.dll");
      user32.dll = LoadLibraryA(path);
      setupFunctions();
      DisableThreadLibraryCalls(hModule);
      spt_fuyu::Initialize();
      break;
    case DLL_PROCESS_DETACH:
      spt_fuyu::RemoveHooks();
      FreeLibrary(user32.dll);
      break;
  }
  return 1;
}
#else
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
      DisableThreadLibraryCalls(hModule);
      if (spt_fuyu::InstallHooks()) {
        spt_fuyu::ChangeWindowTitle();
      }
      break;
    case DLL_PROCESS_DETACH:
      spt_fuyu::RemoveHooks();
      break;
  }
  return 1;
}
#endif  // NDEBUG
