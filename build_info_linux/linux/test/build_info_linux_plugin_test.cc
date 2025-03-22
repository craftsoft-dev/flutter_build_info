// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <flutter_linux/flutter_linux.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "include/build_info_linux/build_info_linux_plugin.h"
#include "build_info_linux_plugin_private.h"

// Re-declare the opaque struct as a temporary workaround for the lack of
// APIs for reading host API response objects.
// TODO(stuartmorgan): Remove this once the following is fixed:
// https://github.com/flutter/flutter/issues/152166.
struct _BuildInfoLinuxBuildInfoHostApiFromPlatformResponse {
  GObject parent_instance;

  FlValue* value;
};

struct _BuildInfoLinuxBuildInfoDataPigeon {
  GObject parent_instance;

  int64_t* build_date;
  int64_t* install_date;
};

// TODO(stuartmorgan): Remove this once
// https://github.com/flutter/flutter/issues/156100 is fixed. For now, this may
// need to be updated to make unit tests pass again any time the
// Pigeon-generated files are updated.
static const int platform_type_group_object_id = 129;

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
  g_autoptr(BuildInfoLinuxBuildInfoHostApiFromPlatformResponse) response = handle_from_platform(nullptr);

  ASSERT_NE(response, nullptr);
  ASSERT_TRUE(fl_value_get_type(response->value) == FL_VALUE_TYPE_LIST);
  ASSERT_TRUE(fl_value_get_length(response->value) == 1);

  FlValue* result = fl_value_get_list_value(response->value, 0);
  ASSERT_EQ(FL_VALUE_TYPE_CUSTOM, fl_value_get_type(result));

  ASSERT_EQ(platform_type_group_object_id, fl_value_get_custom_type(result));
  _BuildInfoLinuxBuildInfoDataPigeon* obj = reinterpret_cast<_BuildInfoLinuxBuildInfoDataPigeon*>(fl_value_get_custom_value_object(result));
#ifdef BUILD_INFO_TIMESTAMP
  ASSERT_NE(nullptr, obj->build_date);
  ASSERT_EQ(BUILD_INFO_TIMESTAMP, *(obj->build_date));
#else
  ASSERT_EQ(nullptr, obj->build_date);
#endif
  ASSERT_EQ(nullptr, obj->install_date);
}
}  // namespace test
}  // namespace build_info_linux
