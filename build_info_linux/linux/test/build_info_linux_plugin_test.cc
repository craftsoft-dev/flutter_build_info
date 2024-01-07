// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <flutter_linux/flutter_linux.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "include/build_info_linux/build_info_linux_plugin.h"
#include "build_info_linux_plugin_private.h"

// This demonstrates a simple unit test of the C portion of this plugin's
// implementation.
//
// Once you have built the plugin's example app, you can run these tests
// from the command line. For instance, for a plugin called my_plugin
// built for x64 debug, run:
// $ build/linux/x64/debug/plugins/my_plugin/my_plugin_test

namespace build_info_linux {
namespace test {
TEST(BuildInfoLinuxPlugin, FromPlatform) {
  g_autoptr(FlMethodResponse) response = from_platform();
  ASSERT_NE(response, nullptr);
  ASSERT_TRUE(FL_IS_METHOD_SUCCESS_RESPONSE(response));
  FlValue* result = fl_method_success_response_get_result(
      FL_METHOD_SUCCESS_RESPONSE(response));

  ASSERT_EQ(FL_VALUE_TYPE_INT64_LIST, fl_value_get_type(result));

  ASSERT_EQ(2, fl_value_get_length(result));
  const int64_t* val = fl_value_get_int64_list(result);

#ifdef BUILD_INFO_TIMESTAMP
  ASSERT_EQ(BUILD_INFO_TIMESTAMP, val[0]);
#else
  ASSERT_EQ(-1L, val[0]);
#endif
  ASSERT_EQ(-1L, val[1]);
}
}  // namespace test
}  // namespace build_info_linux
