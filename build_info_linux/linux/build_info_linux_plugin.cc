// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "include/build_info_linux/build_info_linux_plugin.h"

#include <flutter_linux/flutter_linux.h>

#include "build_info_linux_plugin_private.h"
#include "messages.g.h"

struct _BuildInfoLinuxPlugin {
  GObject parent_instance;

  FlPluginRegistrar* registrar;
};

G_DEFINE_TYPE(BuildInfoLinuxPlugin, build_info_linux_plugin, g_object_get_type())

BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* handle_from_platform(gpointer user_data) {
#ifdef BUILD_INFO_TIMESTAMP
  int64_t build_date = BUILD_INFO_TIMESTAMP;
#else
  int64_t build_date = -1;
#endif

  BuildInfoLinuxBuildInfoDataPigeon* data = build_info_linux_build_info_data_pigeon_new(
    build_date > -1 ? &build_date : nullptr,
    nullptr
  );

  return build_info_linux_build_info_host_api_from_platform_response_new(data);
}

static void build_info_linux_plugin_dispose(GObject* object) {
  BuildInfoLinuxPlugin* self = BUILD_INFO_LINUX_PLUGIN(object);

  build_info_linux_build_info_host_api_clear_method_handlers(
    fl_plugin_registrar_get_messenger(self->registrar),
    nullptr
  );
  g_clear_object(&self->registrar);

  G_OBJECT_CLASS(build_info_linux_plugin_parent_class)->dispose(object);
}

static void build_info_linux_plugin_class_init(BuildInfoLinuxPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = build_info_linux_plugin_dispose;
}

BuildInfoLinuxPlugin* build_info_linux_plugin_new(FlPluginRegistrar* registrar) {
  BuildInfoLinuxPlugin* self = BUILD_INFO_LINUX_PLUGIN(
    g_object_new(build_info_linux_plugin_get_type(), nullptr)
  );

  self->registrar = FL_PLUGIN_REGISTRAR(g_object_ref(registrar));

  static BuildInfoLinuxBuildInfoHostApiVTable api_vtable = {
    .from_platform = handle_from_platform
  };

  build_info_linux_build_info_host_api_set_method_handlers(
    fl_plugin_registrar_get_messenger(registrar),
    nullptr,
    &api_vtable,
    g_object_ref(self),
    g_object_unref
  );

  return self;
}

static void build_info_linux_plugin_init(BuildInfoLinuxPlugin* self) {}

void build_info_linux_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  BuildInfoLinuxPlugin* plugin = build_info_linux_plugin_new(registrar);
  g_object_unref(plugin);
}
