// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_PLUGIN_BUILD_INFO_LINUX_PLUGIN_H_
#define FLUTTER_PLUGIN_BUILD_INFO_LINUX_PLUGIN_H_

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

typedef struct _BuildInfoLinuxPlugin BuildInfoLinuxPlugin;
typedef struct {
  GObjectClass parent_class;
} BuildInfoLinuxPluginClass;

FLUTTER_PLUGIN_EXPORT GType build_info_linux_plugin_get_type();

FLUTTER_PLUGIN_EXPORT void build_info_linux_plugin_register_with_registrar(
    FlPluginRegistrar* registrar);

G_END_DECLS

#endif  // FLUTTER_PLUGIN_BUILD_INFO_LINUX_PLUGIN_H_
