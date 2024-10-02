// SPT Fuyu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <windows.h>
#include <shlwapi.h>
#include <iostream>
#include <fstream>
#include <string>

#pragma comment(lib, "shlwapi.lib")

void CreateRegistryKeyAndFiles(const std::string& installLocation) {
    // 创建注册表项
    HKEY hKey;
    const char* subKey = "Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\EscapeFromTarkov";

    if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "InstallLocation", 0, REG_SZ, (const BYTE*)installLocation.c_str(), installLocation.size() + 1);
        RegCloseKey(hKey);
    }

    // 创建目录和文件
    CreateDirectoryA(installLocation.c_str(), NULL);
    std::ofstream(installLocation + "\\BattlEye\\BEClient_x64.dll").close();
    std::ofstream(installLocation + "\\BattlEye\\BEService_x64.dll").close();
    std::ofstream(installLocation + "\\ConsistencyInfo").close();
    std::ofstream(installLocation + "\\Uninstall.exe").close();
    std::ofstream(installLocation + "\\UnityCrashHandler64.exe").close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "请拖入EscapeFromTarkov.exe文件。" << std::endl;
        system("pause");
        return 1;
    }

    std::string filePath = argv[1];
    std::string fileName = PathFindFileNameA(filePath.c_str());

    if (fileName != "EscapeFromTarkov.exe") {
        std::cerr << "错误：拖入的文件不是EscapeFromTarkov.exe。" << std::endl;
		system("pause");
        return 1;
    }

    std::string installLocation = filePath.substr(0, filePath.find_last_of("\\/"));
    CreateRegistryKeyAndFiles(installLocation);

    std::cout << "验证执行成功." << std::endl;
    system("pause");
    return 0;
}
