// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_PLUGIN_BUILD_INFO_WINDOWS_PLUGIN_H_
#define FLUTTER_PLUGIN_BUILD_INFO_WINDOWS_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

#include "messages.g.h"

namespace build_info_windows {

class BuildInfoWindowsPlugin : public flutter::Plugin, public BuildInfoHostApi {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  BuildInfoWindowsPlugin();

  virtual ~BuildInfoWindowsPlugin();

  // Disallow copy and assign.
  BuildInfoWindowsPlugin(const BuildInfoWindowsPlugin&) = delete;
  BuildInfoWindowsPlugin& operator=(const BuildInfoWindowsPlugin&) = delete;

  // BuildInfoHostApi
  ErrorOr<BuildInfoDataPigeon> FromPlatform() override;
};

}  // namespace build_info_windows

#endif  // FLUTTER_PLUGIN_BUILD_INFO_WINDOWS_PLUGIN_H_
