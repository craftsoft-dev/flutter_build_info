// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "include/build_info_linux/build_info_linux_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>
#include <locale.h>
#include <time.h>
#include <sys/stat.h>

#include "build_info_linux_plugin_private.h"

#define BUILD_INFO_LINUX_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), build_info_linux_plugin_get_type(), \
                              BuildInfoLinuxPlugin))

struct _BuildInfoLinuxPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(BuildInfoLinuxPlugin, build_info_linux_plugin, g_object_get_type())

// Called when a method call is received from Flutter.
static void build_info_linux_plugin_handle_method_call(
    BuildInfoLinuxPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);

  if (strcmp(method, "fromPlatform") == 0) {
    response = from_platform();
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}

FlMethodResponse* from_platform() {
  int64_t data[2] = {-1, -1};

#ifdef BUILD_INFO_TIMESTAMP
  data[0] = BUILD_INFO_TIMESTAMP;
#endif

  g_autoptr(FlValue) result = fl_value_new_int64_list(data, 2);
  
  return FL_METHOD_RESPONSE(fl_method_success_response_new(result));
}


static void build_info_linux_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(build_info_linux_plugin_parent_class)->dispose(object);
}

static void build_info_linux_plugin_class_init(BuildInfoLinuxPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = build_info_linux_plugin_dispose;
}

static void build_info_linux_plugin_init(BuildInfoLinuxPlugin* self) {}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  BuildInfoLinuxPlugin* plugin = BUILD_INFO_LINUX_PLUGIN(user_data);
  build_info_linux_plugin_handle_method_call(plugin, method_call);
}

void build_info_linux_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  BuildInfoLinuxPlugin* plugin = BUILD_INFO_LINUX_PLUGIN(
      g_object_new(build_info_linux_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            "dev.craftsoft/build_info_linux",
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}
