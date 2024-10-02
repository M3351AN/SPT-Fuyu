// SPT Fuyu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <windows.h>
#include <shlwapi.h>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#pragma comment(lib, "shlwapi.lib")

bool IsChineseLanguage() {
    LANGID langId = GetUserDefaultUILanguage();
    return (langId == 0x0804 || langId == 0x0404); // 简体中文或繁体中文
}

void CreateRegistryKeyAndFiles(const std::string& installLocation) {
    // 创建注册表项 Create a registry key
    HKEY hKey;
    const char* subKey = "Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\EscapeFromTarkov";

    if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "InstallLocation", 0, REG_SZ, (const BYTE*)installLocation.c_str(), installLocation.size() + 1);
        RegCloseKey(hKey);
    }

    // 创建目录和文件 Creating Directories and Files
    CreateDirectoryA(installLocation.c_str(), NULL);
    CreateDirectoryA((installLocation+ "\\BattlEye").c_str(), NULL);
    std::ofstream(installLocation + "\\BattlEye\\BEClient_x64.dll").close();
    //std::ofstream(installLocation + "\\BattlEye\\BEService_x64.dll").close();
    std::ofstream(installLocation + "\\ConsistencyInfo").close();
    std::ofstream(installLocation + "\\Uninstall.exe").close();
    std::ofstream(installLocation + "\\UnityCrashHandler64.exe").close();
    std::ofstream(installLocation + "\\WinPixEventRuntime.dll").close();
}

int main(int argc, char* argv[]) {
    SetConsoleTitle(L"SPT Fuyu");

    // 判断是否为中文语言 Determine if system language is Chinese
    bool isChinese = IsChineseLanguage();

    if (argc != 2) {
        std::cerr << (isChinese ? "请拖入验证文件存放文件夹。" : "Please drag and drop the folder that you want verification files storage at." )<< std::endl;
        system("pause");
        return 1;
    }

    std::string filePath = argv[1];

    if (!std::filesystem::is_directory(filePath)) {
        std::cerr << (isChinese ? "错误：拖入的不是文件夹。" : "Error: The item dragged in is not a folder.") << std::endl;
		system("pause");
        return 1;
    }
    if (std::filesystem::directory_iterator(filePath) != std::filesystem::end(std::filesystem::directory_iterator())) {
        std::cerr << (isChinese ? "错误：拖入的文件夹不是空的。" : "Error: The folder dragged in is not empty.") << std::endl;
        system("pause");
        return 1;
    }

    std::string installLocation = filePath;
    CreateRegistryKeyAndFiles(installLocation);

    std::cout << (isChinese ? "验证执行成功." : "Validation Bypass Succeeded.") << std::endl;
    system("pause");
    return 0;
}
