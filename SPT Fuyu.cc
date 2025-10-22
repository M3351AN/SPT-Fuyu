// Copyright (c) 2025 渟雲. All rights reserved.
//
// Licensed under the TOSSRCU 2025.9 License (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  https://raw.githubusercontent.com/M3351AN/M3351AN/9e7630a8511b8306c62952ca1a4f1ce0cc5b784a/LICENSE
//
// -----------------------------------------------------------------------------
// File: SPT Fuyu.cc
// Author: 渟雲(quq[at]outlook.it)
// Date: 2025-10-22
//
// Description:
//   This file includes functions of SPT Fuyu
//
// -----------------------------------------------------------------------------

#include <shlobj.h>
#include <shlwapi.h>
#include <windows.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "Shell32.lib")

bool IsChineseLanguage() {
  LANGID langId = GetUserDefaultUILanguage();
  return (langId == 0x0804 || langId == 0x0404);  // 简体中文或繁体中文
}

void CreateRegistryKeyAndFiles(const std::string& installLocation) {
  // 创建注册表项 Create a registry key
  HKEY hKey;
  const char* subKey =
      "Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\"
      "EscapeFromTarkov";

  if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, NULL, 0, KEY_WRITE, NULL,
                      &hKey, NULL) == ERROR_SUCCESS) {
    RegSetValueExA(hKey, "InstallLocation", 0, REG_SZ,
                   (const BYTE*)installLocation.c_str(),
                   installLocation.size() + 1);
    RegCloseKey(hKey);
  }

  // 创建目录和文件 Creating Directories and Files
  CreateDirectoryA(installLocation.c_str(), NULL);
  CreateDirectoryA((installLocation + "\\BattlEye").c_str(), NULL);
  std::ofstream(installLocation + "\\BattlEye\\BEClient_x64.dll").close();
  // This file isn't needed to be created, as it's not exist in EFT live
  // std::ofstream(installLocation + "\\BattlEye\\BEService_x64.dll").close();
  std::ofstream(installLocation + "\\ConsistencyInfo").close();
  std::ofstream(installLocation + "\\Uninstall.exe").close();
  std::ofstream(installLocation + "\\UnityCrashHandler64.exe").close();
  std::ofstream(installLocation + "\\WinPixEventRuntime.dll").close();
}

bool Validate() {  // copy from SPT Source
  std::wstring registryPath =
      L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\"
      L"EscapeFromTarkov";
  int v0 = 0;

  try {
    HKEY hKey;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, registryPath.c_str(), 0, KEY_READ,
                      &hKey) == ERROR_SUCCESS) {
      wchar_t installLocation[512];
      DWORD bufferSize = sizeof(installLocation);
      if (RegQueryValueExW(hKey, L"InstallLocation", nullptr, nullptr,
                           (LPBYTE)installLocation,
                           &bufferSize) == ERROR_SUCCESS) {
        std::wstring v2 = installLocation;
        std::vector<std::filesystem::path> v4 = {
            v2,
            v2 + L"\\BattlEye\\BEClient_x64.dll",
            v2 + L"\\BattlEye\\BEService_x64.dll",
            v2 + L"\\ConsistencyInfo",
            v2 + L"\\Uninstall.exe",
            v2 + L"\\UnityCrashHandler64.exe"};

        v0 = static_cast<int>(v4.size()) - 1;

        for (const auto& value : v4) {
          if (std::filesystem::exists(value)) {
            --v0;
          }
        }
      }
      RegCloseKey(hKey);
    }
  } catch (...) {
    v0 = -1;
  }

  return v0 == 0;
}

void Exit(int ret = 0) {
  system("pause");
  exit(ret);
}

int main(int argc, char* argv[]) {
  SetConsoleTitle(L"SPT Fuyu");
  // 解决Clang编译导致程序乱码的问题 Fix Clang build console garbled problem
  SetConsoleOutputCP(65001);
  // 判断是否为中文语言 Determine if system language is Chinese
  bool isChinese = IsChineseLanguage();
  if (Validate()) {  // 检查是否已经通过验证 Check if already passed SPT
                     // validation
    std::cout
        << (isChinese
                ? "检测到正版验证已通过，是否重新执行验证？\n("
                  "如果您已经安装在线版逃离塔科夫，请不要运行本程序) (y/n): "
                : "Verification already passed. Do you want to execute "
                  "verification bypass? \n (If you already installed EFT live "
                  "version, do not execute this.) (y/n): ");
    char response;
    std::cin >> response;
    if (response != 'y' && response != 'Y') {
      Exit();
      return 0;
    }
  }
  std::string filePath;

  if (argc != 2) {
    wchar_t filePathLPSTR[MAX_PATH];
    // 获取用户文档的路径 Get the path of Documents folder
    SHGetFolderPathW(NULL, CSIDL_MYDOCUMENTS, NULL, 0, filePathLPSTR);
    filePath = std::filesystem::path(filePathLPSTR).string();
  } else {
    if (!std::filesystem::exists(argv[1])) {
      if (strcmp(argv[1], "-here")) {
        // 获取当前可执行文件的路径 Get the path of the current executable
        wchar_t exePath[MAX_PATH];
        GetModuleFileNameW(NULL, exePath, MAX_PATH);
        filePath = std::filesystem::path(exePath).parent_path().string();
      } else {
        std::cout << (isChinese
                          ? "错误：传入的路径不存在。"
                          : "Error: The path you dragged in does not exist.");
        Exit(1);
      }
    } else {
      filePath = argv[1];
    }
  }

  // 创建名为SPT Fuyu的文件夹 Create a folder named SPT Fuyu
  std::string newFolderPath = filePath + "\\SPT Fuyu";
  if (!std::filesystem::create_directory(newFolderPath) && !Validate()) {
    std::cout << (isChinese ? "错误：无法创建SPT Fuyu文件夹。"
                            : "Error: Unable to create SPT Fuyu folder.")
              << std::endl;
    Exit(1);
  }
  filePath = newFolderPath;

  if (!std::filesystem::is_directory(filePath)) {
    std::cout << (isChinese ? "错误：SPT Fuyu路径指向的不是文件夹。"
                            : "Error: The path of SPT Fuyu is not a folder.");
    Exit(1);
  }

  if (std::filesystem::directory_iterator(filePath) !=
          std::filesystem::end(std::filesystem::directory_iterator()) &&
      !Validate()) {
    std::cout << (isChinese ? "错误：SPT Fuyu文件夹不是空的。"
                            : "Error: SPT Fuyu folder is not empty.");
    Exit(1);
  }

  std::string installLocation = filePath;
  CreateRegistryKeyAndFiles(installLocation);
  if (!Validate()) {
    std::cout << (isChinese ? "验证执行失败，未知错误."
                            : "Validation Bypass Failed. Unknown Error");
    Exit(1);
  }
  std::cout << (isChinese ? "验证执行成功." : "Validation Bypass Succeeded.");
  Exit();
  return 0;
}
