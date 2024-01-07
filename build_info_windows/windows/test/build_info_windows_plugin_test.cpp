// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <flutter/method_call.h>
#include <flutter/method_result_functions.h>
#include <flutter/standard_method_codec.h>
#include <gtest/gtest.h>
#include <windows.h>

#include <memory>
#include <string>
#include <variant>

#include "build_info_windows_plugin.h"

namespace build_info_windows {
namespace test {

namespace {

using flutter::EncodableMap;
using flutter::EncodableValue;
using flutter::MethodCall;
using flutter::MethodResultFunctions;

}  // namespace

TEST(BuildInfoWindowsPlugin, GetPlatformVersion) {
  BuildInfoWindowsPlugin plugin;

  ErrorOr<BuildInfoDataPigeon> result = plugin.FromPlatform();
  ASSERT_FALSE(result.has_error());
  
  const int64_t* buildDate = result.value().build_date();
  const int64_t* installDate = result.value().install_date();
  if (buildDate) {
    EXPECT_LT(-1L, *buildDate);
  }
  if (installDate) {
    EXPECT_LT(-1L, *installDate);
  }
}

}  // namespace test
}  // namespace build_info_windows
