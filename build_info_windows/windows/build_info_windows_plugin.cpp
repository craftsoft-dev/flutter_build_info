// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "build_info_windows_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

#include "messages.g.h"

#include <libloaderapi.h>

namespace build_info_windows {

// static
void BuildInfoWindowsPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {

  std::unique_ptr<BuildInfoWindowsPlugin> plugin =
      std::make_unique<BuildInfoWindowsPlugin>();
  BuildInfoHostApi::SetUp(registrar->messenger(), plugin.get());
  registrar->AddPlugin(std::move(plugin));
}

BuildInfoWindowsPlugin::BuildInfoWindowsPlugin() {}

BuildInfoWindowsPlugin::~BuildInfoWindowsPlugin() {}

ErrorOr<BuildInfoDataPigeon> BuildInfoWindowsPlugin::FromPlatform() {
  int64_t buildDate = -1L;
  int64_t installDate = -1L;

  TCHAR szModulePath[MAX_PATH];
  DWORD ret = GetModuleFileName(NULL, szModulePath, sizeof(szModulePath) / sizeof(szModulePath[0]));
  if (ret != 0) {
      // Get the file creation time.
      int64_t fileCreationTime = INT64_MAX, dirCreationTime = INT64_MAX;
      WIN32_FILE_ATTRIBUTE_DATA wfad;

      if (GetFileAttributesEx(szModulePath, GetFileExInfoStandard, &wfad)) {
          // FILETIME: 100-nanosecond intervals since 1601-01-01 00:00:00 UTC.
          ULARGE_INTEGER timeValue;
          timeValue.HighPart = wfad.ftCreationTime.dwHighDateTime;
          timeValue.LowPart = wfad.ftCreationTime.dwLowDateTime;
          timeValue.QuadPart -= 116444736000000000LL/* 1601-01-01 00:00 UTC to 1970-01-01 00:00 UTC */;

          fileCreationTime = timeValue.QuadPart / 10000/* 100ns to ms*/;
      }

      // Get the directory creation time.
      TCHAR szModuleDir[MAX_PATH];
      DWORD dirRet = GetFullPathName(szModulePath, sizeof(szModulePath) / sizeof(szModulePath[0]), szModuleDir, NULL);
      if (dirRet > 0) {
          WIN32_FILE_ATTRIBUTE_DATA wfadDir;
          if (GetFileAttributesEx(szModuleDir, GetFileExInfoStandard, &wfadDir)) {
              // FILETIME: 100-nanosecond intervals since 1601-01-01 00:00:00 UTC.
              ULARGE_INTEGER timeValue;
              timeValue.HighPart = wfadDir.ftCreationTime.dwHighDateTime;
              timeValue.LowPart = wfadDir.ftCreationTime.dwLowDateTime;
              timeValue.QuadPart -= 116444736000000000LL/* 1601-01-01 00:00 UTC to 1970-01-01 00:00 UTC */;

              dirCreationTime = timeValue.QuadPart / 10000/* 100ns to ms*/;
          }
      }

      installDate = min(fileCreationTime, dirCreationTime);

      // Get the TimeDateStamp from executable file.
      IMAGE_DOS_HEADER idh;
      IMAGE_NT_HEADERS64 inh;
      FILE* fp = NULL;
      if (_wfopen_s(&fp, szModulePath, L"rb") == 0 && fp != NULL) {
          if (fread(&idh, sizeof(idh), 1, fp) > 0 && idh.e_magic == IMAGE_DOS_SIGNATURE && idh.e_lfanew > 0) {
              fseek(fp, idh.e_lfanew, SEEK_SET);
              if (fread(&inh, sizeof(inh), 1, fp) > 0 && inh.Signature == 0x00004550/* "PE\0\0" */) {
                  int64_t _tmp = inh.FileHeader.TimeDateStamp;
                  if (_tmp < 1704067200/* 2024-01-01 00:00:00 UTC */) {
                      _tmp += 0x100000000;
                  }

                  buildDate = _tmp * 1000/* sec to ms */;
              }
          }
          fclose(fp);
      }
  }

  return BuildInfoDataPigeon(
    buildDate == -1L ? NULL : &buildDate,
    installDate == -1L ? NULL : &installDate
  );
}

}  // namespace build_info_windows
