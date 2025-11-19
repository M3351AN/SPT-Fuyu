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
constexpr wchar_t kTargetRegistryKey[] =
    L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\"
    L"EscapeFromTarkov";
constexpr wchar_t kTargetRegistryValue[] = L"InstallLocation";

static const std::vector<std::wstring> kVirtualFiles = {
    L"BattlEye\\BEClient_x64.dll", L"ConsistencyInfo", L"Uninstall.exe",
    L"UnityCrashHandler64.exe", L"WinPixEventRuntime.dll"};
}  // namespace build

namespace spt_fuyu {

constexpr wchar_t kVirtualPath[] = L"A:\\SPTFuyuVirturalPath";

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

typedef LSTATUS(WINAPI* RegOpenKeyExWFunc)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY);
typedef LSTATUS(WINAPI* RegOpenKeyFunc)(HKEY, LPCWSTR, PHKEY);
typedef LSTATUS(WINAPI* RegQueryValueExWFunc)(HKEY, LPCWSTR, LPDWORD, LPDWORD,
                                              LPBYTE, LPDWORD);
typedef LSTATUS(WINAPI* RegCloseKeyFunc)(HKEY);
typedef HANDLE(WINAPI* CreateFileWFunc)(LPCWSTR, DWORD, DWORD,
                                        LPSECURITY_ATTRIBUTES, DWORD, DWORD,
                                        HANDLE);
typedef DWORD(WINAPI* GetFileAttributesWFunc)(LPCWSTR file_name);
typedef BOOL(WINAPI* GetFileAttributesExWFunc)(
    LPCWSTR file_name, GET_FILEEX_INFO_LEVELS info_level_id,
    LPVOID file_information);
typedef NTSTATUS(WINAPI* NtQueryAttributesFileFunc)(POBJECT_ATTRIBUTES,
                                                    PFILE_BASIC_INFORMATION);

static RegOpenKeyExWFunc original_reg_open_key_ex_w = nullptr;
static RegOpenKeyFunc original_reg_open_key = nullptr;
static RegQueryValueExWFunc original_reg_query_value_ex_w = nullptr;
static RegCloseKeyFunc original_reg_close_key = nullptr;
static CreateFileWFunc original_create_file_w = nullptr;
static GetFileAttributesWFunc original_get_file_attributes_w = nullptr;
static GetFileAttributesExWFunc original_get_file_attributes_ex_w = nullptr;
static NtQueryAttributesFileFunc original_nt_query_attributes_file = nullptr;

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
  if (result.length() > 3 && result.back() == L'\\') {
    result.pop_back();
  }
  std::replace(result.begin(), result.end(), L'/', L'\\');
  return result;
}

bool IsVirtualPath(LPCWSTR path) {
  if (!path) return false;
  std::wstring file_path(path);
  std::wstring lower_path = file_path;
  std::transform(lower_path.begin(), lower_path.end(), lower_path.begin(),
                 ::towlower);
  std::wstring virtual_path_lower = kVirtualPath;
  std::transform(virtual_path_lower.begin(), virtual_path_lower.end(),
                 virtual_path_lower.begin(), ::towlower);
  return lower_path.find(virtual_path_lower) != std::wstring::npos;
}

bool IsVirtualDirectory(LPCWSTR path) {
  if (!path) return false;
  std::wstring normalized_path = NormalizePath(path);
  std::wstring virtual_path_lower = NormalizePath(kVirtualPath);
  return normalized_path == virtual_path_lower;
}

bool IsVirtualFile(LPCWSTR file_name) {
  if (!file_name) return false;

  std::wstring normalized_path = NormalizePath(file_name);
  std::wstring virtual_path_lower = NormalizePath(kVirtualPath);

  if (normalized_path == virtual_path_lower) {
    return true;
  }

  for (const auto& virtual_file : build::kVirtualFiles) {
    std::wstring virtual_full_path =
        virtual_path_lower + L"\\" + NormalizePath(virtual_file.c_str());
    if (normalized_path == virtual_full_path) {
      return true;
    }
  }

  return false;
}

LSTATUS WINAPI HookedRegOpenKey(HKEY key, LPCWSTR sub_key, PHKEY result) {
  if (IsTargetRegistryKey(key, sub_key)) {
    *result = g_virtual_key;
    return ERROR_SUCCESS;
  }
  return original_reg_open_key(key, sub_key, result);
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
        *data_size >= (wcslen(kVirtualPath) + 1) * sizeof(wchar_t)) {
      wcscpy_s(reinterpret_cast<wchar_t*>(data), *data_size / sizeof(wchar_t),
               kVirtualPath);
      if (type) *type = REG_SZ;
      *data_size = (wcslen(kVirtualPath) + 1) * sizeof(wchar_t);
      return ERROR_SUCCESS;
    } else if (data_size) {
      *data_size = (wcslen(kVirtualPath) + 1) * sizeof(wchar_t);
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
                                DWORD share_mode,
                                LPSECURITY_ATTRIBUTES security_attributes,
                                DWORD creation_disposition,
                                DWORD flags_and_attributes,
                                HANDLE template_file) {
  if (IsVirtualPath(file_name)) {
    bool is_existence_check = false;

    if (creation_disposition == OPEN_EXISTING ||
        creation_disposition == CREATE_NEW ||
        creation_disposition == TRUNCATE_EXISTING) {
      is_existence_check = true;
    }

    if (is_existence_check) {
      if (IsVirtualFile(file_name)) {
        if ((desired_access &
             (GENERIC_WRITE | FILE_WRITE_DATA | FILE_WRITE_ATTRIBUTES)) == 0) {
          static HANDLE dummy_file = reinterpret_cast<HANDLE>(0xCAFE1337);
          SetLastError(ERROR_SUCCESS);
          return dummy_file;
        }
      } else {
        SetLastError(ERROR_FILE_NOT_FOUND);
        return INVALID_HANDLE_VALUE;
      }
    }
  }

  return original_create_file_w(file_name, desired_access, share_mode,
                                security_attributes, creation_disposition,
                                flags_and_attributes, template_file);
}

DWORD WINAPI HookedGetFileAttributesW(LPCWSTR file_name) {
  if (IsVirtualPath(file_name)) {
    if (IsVirtualFile(file_name)) {
      if (IsVirtualDirectory(file_name)) {
        return FILE_ATTRIBUTE_DIRECTORY;
      } else {
        return FILE_ATTRIBUTE_NORMAL;
      }
    } else {
      SetLastError(ERROR_FILE_NOT_FOUND);
      return INVALID_FILE_ATTRIBUTES;
    }
  }
  return original_get_file_attributes_w(file_name);
}

BOOL WINAPI HookedGetFileAttributesExW(LPCWSTR file_name,
                                       GET_FILEEX_INFO_LEVELS info_level_id,
                                       LPVOID file_information) {
  if (IsVirtualPath(file_name)) {
    if (IsVirtualFile(file_name)) {
      if (info_level_id == GetFileExInfoStandard && file_information) {
        WIN32_FILE_ATTRIBUTE_DATA* attr_data =
            reinterpret_cast<WIN32_FILE_ATTRIBUTE_DATA*>(file_information);

        if (IsVirtualDirectory(file_name)) {
          attr_data->dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
        } else {
          attr_data->dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
        }

        FILETIME file_time;
        GetSystemTimeAsFileTime(&file_time);
        attr_data->ftCreationTime = file_time;
        attr_data->ftLastAccessTime = file_time;
        attr_data->ftLastWriteTime = file_time;
        attr_data->nFileSizeLow = 1024;
        attr_data->nFileSizeHigh = 0;

        return TRUE;
      }
    } else {
      SetLastError(ERROR_FILE_NOT_FOUND);
      return FALSE;
    }
  }
  return original_get_file_attributes_ex_w(file_name, info_level_id,
                                           file_information);
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

FARPROC GetOriginalFunction(const char* func_name) {
  HMODULE module;

  if (strstr(func_name, "RegOpenKey")) {
    module = GetModuleHandleA("advapi32.dll");
  } else if (strstr(func_name, "RegQueryValue")) {
    module = GetModuleHandleA("advapi32.dll");
  } else if (strstr(func_name, "RegCloseKey")) {
    module = GetModuleHandleA("advapi32.dll");
  } else if (strstr(func_name, "CreateFile")) {
    module = GetModuleHandleA("kernel32.dll");
  } else if (strstr(func_name, "GetFileAttributes")) {
    module = GetModuleHandleA("kernel32.dll");
  } else if (strstr(func_name, "NtQueryAttributesFile")) {
    module = GetModuleHandleA("ntdll.dll");
  } else {
    module = GetModuleHandleA("kernel32.dll");
  }

  return GetProcAddress(module, func_name);
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
  FARPROC get_file_attributes_w = GetOriginalFunction("GetFileAttributesW");
  FARPROC get_file_attributes_ex_w =
      GetOriginalFunction("GetFileAttributesExW");

  if (MH_CreateHook(reg_open_key_ex_w, &HookedRegOpenKeyExW,
                    reinterpret_cast<LPVOID*>(&original_reg_open_key_ex_w)) !=
      MH_OK) {
    return false;
  }

  if (reg_open_key && MH_CreateHook(reg_open_key, &HookedRegOpenKey,
                                    reinterpret_cast<LPVOID*>(
                                        &original_reg_open_key)) != MH_OK) {
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

  if (get_file_attributes_w &&
      MH_CreateHook(get_file_attributes_w, &HookedGetFileAttributesW,
                    reinterpret_cast<LPVOID*>(
                        &original_get_file_attributes_w)) != MH_OK) {
  }

  if (get_file_attributes_ex_w &&
      MH_CreateHook(get_file_attributes_ex_w, &HookedGetFileAttributesExW,
                    reinterpret_cast<LPVOID*>(
                        &original_get_file_attributes_ex_w)) != MH_OK) {
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
void Initialize() { std::thread(InitializeWorker).detach(); }
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
