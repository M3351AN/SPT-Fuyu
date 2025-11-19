// Copyright (c) 2025 渟雲. All rights reserved.
//
// Licensed under the TOSSRCU 2025.9 License (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  https://raw.githubusercontent.com/M3351AN/M3351AN/9e7630a8511b8306c62952ca1a4f1ce0cc5b784a/LICENSE
//
// -----------------------------------------------------------------------------
// File: spt_fuyu_patcher.cc
// Author: 渟雲(quq[at]outlook.it)
// Date: 2025-11-19
//
// Description:
//   This file includes functions of SPT Fuyu Patcher
//
// -----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <span>
#include <expected>
#include <format>
#include <filesystem>
#include <array>
#include <execution>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace build {
static constexpr std::string_view kFilename = "SPT.Launcher.exe";
static constexpr std::string_view kExpectedProductName = "SPT.Launcher";

static constexpr std::string_view kSig1 = "26 15 0B DE 00 07 16 FE 01 2A";
static constexpr std::string_view kRep1 = "26 15 0B DE 00 16 16 FE 01 2A";

static constexpr std::string_view kSig2 = "DE 00 11 04 16 FE 01 2A";
static constexpr std::string_view kRep2 = "DE 00 00 16 16 FE 01 2A";

static constexpr std::string_view kSig3 = "DE 00 7E ?? ?? ?? ?? 16 FE 01 2A";
static constexpr std::string_view kRep3 = "DE 00 7E ?? ?? ?? ?? 25 FE 01 2A";
}  // namespace build

enum class FileError {
  FileNotFound,
  PermissionDenied,
  ReadError,
  WriteError,
  PatternNotFound,
  PatchedPatternFound,
  NotExecutable
};

std::vector<std::optional<uint8_t>> ParseBytePattern(std::string_view pattern) {
  std::vector<std::optional<uint8_t>> bytes;

  for (size_t i = 0; i < pattern.length(); ) {
    if (pattern[i] == ' ') {
      i++;
      continue;
    }

    if (i + 1 < pattern.length() && pattern[i] == '?' && pattern[i + 1] == '?') {
      bytes.push_back(std::nullopt);
      i += 2;
    } else if (i + 1 < pattern.length() &&
               std::isxdigit(pattern[i]) &&
               std::isxdigit(pattern[i + 1])) {
      std::string byteStr = std::string{pattern[i]} + std::string{pattern[i + 1]};
      bytes.push_back(static_cast<uint8_t>(std::stoi(byteStr, nullptr, 16)));
      i += 2;
    } else {
      i++;
    }
  }

  return bytes;
}

template<typename Iter>
Iter SearchPattern(Iter begin, Iter end,
                   const std::vector<std::optional<uint8_t>>& pattern) {
  if (pattern.empty()) return end;

  const size_t pattern_size = pattern.size();
  const size_t data_size = std::distance(begin, end);

  if (pattern_size > data_size) return end;

  for (size_t i = 0; i <= data_size - pattern_size; ++i) {
    bool found = true;

    for (size_t j = 0; j < pattern_size; ++j) {
      if (pattern[j].has_value() && *(begin + i + j) != pattern[j].value()) {
        found = false;
        break;
      }
    }

    if (found) {
      return begin + i;
    }
  }

  return end;
}

void ApplyPatch(std::span<unsigned char> data,
                size_t offset,
                const std::vector<std::optional<uint8_t>>& original_pattern,
                const std::vector<std::optional<uint8_t>>& replacement_pattern) {
  for (size_t i = 0; i < replacement_pattern.size() && (offset + i) < data.size(); ++i) {
    if (replacement_pattern[i].has_value()) {
      data[offset + i] = replacement_pattern[i].value();
    }
  }
}

std::expected<std::vector<unsigned char>, FileError>
ReadFile(const std::string& filename) {
  const HANDLE file_handle = CreateFileA(filename.c_str(), GENERIC_READ,
                              FILE_SHARE_READ, NULL, OPEN_EXISTING,
                              FILE_ATTRIBUTE_NORMAL, NULL);
  if (file_handle == INVALID_HANDLE_VALUE) {
    return std::unexpected(FileError::FileNotFound);
  }

  const DWORD file_size = GetFileSize(file_handle, NULL);
  if (file_size == INVALID_FILE_SIZE) {
    CloseHandle(file_handle);
    return std::unexpected(FileError::ReadError);
  }

  const HANDLE mapping_handle = CreateFileMapping(file_handle, NULL,
                                  PAGE_READONLY, 0, 0, NULL);
  if (!mapping_handle) {
    CloseHandle(file_handle);
    return std::unexpected(FileError::ReadError);
  }

  const LPVOID file_data = MapViewOfFile(mapping_handle, FILE_MAP_READ,
                            0, 0, 0);
  if (!file_data) {
    CloseHandle(mapping_handle);
    CloseHandle(file_handle);
    return std::unexpected(FileError::ReadError);
  }

  std::vector<unsigned char> buffer(file_size);
  memcpy(buffer.data(), file_data, file_size);

  UnmapViewOfFile(file_data);
  CloseHandle(mapping_handle);
  CloseHandle(file_handle);

  return buffer;
}

bool WriteFile(const std::string& filename,
               const std::span<const unsigned char> data) {
  const HANDLE file_handle = CreateFileA(filename.c_str(),
                            GENERIC_WRITE, 0, NULL,
                            CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  if (file_handle == INVALID_HANDLE_VALUE) return false;

  DWORD bytes_written;
  const BOOL result = WriteFile(file_handle, data.data(),
                         static_cast<DWORD>(data.size()),
                         &bytes_written, NULL);

  CloseHandle(file_handle);
  return result && (bytes_written == data.size());
}

std::expected<void, FileError> ModifyFile(const std::string& filename) {
  auto buffer = ReadFile(filename);
  if (!buffer) {
    return std::unexpected(buffer.error());
  }

  if (buffer->size() < 2 || (*buffer)[0] != 0x4D || (*buffer)[1] != 0x5A) {
    return std::unexpected(FileError::NotExecutable);
  }

  auto data_span = std::span{*buffer};

  auto sig1_pattern = ParseBytePattern(build::kSig1);
  auto rep1_pattern = ParseBytePattern(build::kRep1);
  auto sig2_pattern = ParseBytePattern(build::kSig2);
  auto rep2_pattern = ParseBytePattern(build::kRep2);
  auto sig3_pattern = ParseBytePattern(build::kSig3);
  auto rep3_pattern = ParseBytePattern(build::kRep3);

  auto check_patched1 = SearchPattern(data_span.begin(), data_span.end(), rep1_pattern);
  auto check_patched2 = SearchPattern(data_span.begin(), data_span.end(), rep2_pattern);
  auto check_patched3 = SearchPattern(data_span.begin(), data_span.end(), rep3_pattern);

  if (check_patched1 != data_span.end() ||
      check_patched2 != data_span.end() ||
      check_patched3 != data_span.end()) {
    return std::unexpected(FileError::PatchedPatternFound);
  }

  auto it = SearchPattern(data_span.begin(), data_span.end(), sig1_pattern);
  if (it != data_span.end()) {
    ApplyPatch(data_span, std::distance(data_span.begin(), it), sig1_pattern, rep1_pattern);
  } else {
    it = SearchPattern(data_span.begin(), data_span.end(), sig2_pattern);
    if (it != data_span.end()) {
      ApplyPatch(data_span, std::distance(data_span.begin(), it), sig2_pattern, rep2_pattern);
    } else {
      it = SearchPattern(data_span.begin(), data_span.end(), sig3_pattern);
      if (it != data_span.end()) {
        ApplyPatch(data_span, std::distance(data_span.begin(), it), sig3_pattern, rep3_pattern);
      } else {
        return std::unexpected(FileError::PatternNotFound);
      }
    }
  }

  if (!WriteFile(filename, data_span)) {
    return std::unexpected(FileError::WriteError);
  }

  return {};
}

bool IsChineseLanguage() {
  const LANGID langId = GetUserDefaultUILanguage();
  return (langId == 0x0804 || langId == 0x0404);  // 简体中文或繁体中文
}

int main(int argc, char* argv[]) {
  SetConsoleTitleW(L"SPT Fuyu");
  // 解决Clang编译导致程序乱码的问题 Fix Clang build console garbled problem
  SetConsoleOutputCP(65001);
  // 判断是否为中文语言 Determine if system language is Chinese
  bool isChinese = false;
  isChinese = IsChineseLanguage();
  std::string target_filename;

  if (argc != 2) {
    target_filename = build::kFilename;
  } else {
    if (!std::filesystem::exists(argv[1])) {
        std::cout << (isChinese
                          ? "错误：传入的路径不存在。 \n"
                          : "Error: "
                          "The path you dragged in does not exist. \n");
      system("pause");
      return 1;
    }
    target_filename = argv[1];
  }

  std::expected<void, FileError> result = ModifyFile(target_filename);

  if (result) {
    std::cout << (isChinese
                ? "已成功修补SPT启动器 \n"
                : "SPT launcher patched successfully \n");
    system("pause");
    return 0;
  } else {
    switch (result.error()) {
      case FileError::FileNotFound: {
          std::cout << std::vformat((isChinese
              ? "错误: 未找到 '{}' 文件 \n"
              : "Error: File '{}' not found \n"),
            std::make_format_args(target_filename));
          break;
        }
      case FileError::ReadError: {
          std::cout << (isChinese
                  ? "错误: 无法读取文件 \n"
                  : "Error: Cannot read file \n");
          break;
        }
      case FileError::WriteError: {
          std::cout << (isChinese
                ? "错误: 无法写入文件 \n"
                : "Error: Cannot write file \n");
          break;
        }
      case FileError::PatternNotFound: {
          std::cout << (isChinese
                ? "错误: 未找到目标字节序列 \n"
                  "修补程序可能已经过时 \n"
                : "Error: Target byte pattern not found. \n"
                  "Patcher might outdated. \n");
          break;
        }
      case FileError::PatchedPatternFound: {
          std::cout << (isChinese
                ? "错误: 未找到目标字节序列 \n"
                  "您可能已经修补过启动器 \n"
                : "Error: Target byte pattern not found. \n"
                  "You might have already patched the launcher. \n");
          break;
        }
      case FileError::NotExecutable: {
          std::cout << (isChinese
                ? "错误: 目标文件不是有效的可执行文件 \n"
                : "Error: Target file is not a valid executable \n");
          break;
        }
      default: {
          std::cout << (isChinese
              ? "错误: 未知错误发生 \n"
              : "Error: Unknown error occurred \n");
          break;
        }
    }
    system("pause");
    return 1;
  }
}
