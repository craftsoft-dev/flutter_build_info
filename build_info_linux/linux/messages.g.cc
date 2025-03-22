// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
// Autogenerated from Pigeon (v25.1.0), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#include "messages.g.h"

struct _BuildInfoLinuxBuildInfoDataPigeon {
  GObject parent_instance;

  int64_t* build_date;
  int64_t* install_date;
};

G_DEFINE_TYPE(BuildInfoLinuxBuildInfoDataPigeon, build_info_linux_build_info_data_pigeon, G_TYPE_OBJECT)

static void build_info_linux_build_info_data_pigeon_dispose(GObject* object) {
  BuildInfoLinuxBuildInfoDataPigeon* self = BUILD_INFO_LINUX_BUILD_INFO_DATA_PIGEON(object);
  g_clear_pointer(&self->build_date, g_free);
  g_clear_pointer(&self->install_date, g_free);
  G_OBJECT_CLASS(build_info_linux_build_info_data_pigeon_parent_class)->dispose(object);
}

static void build_info_linux_build_info_data_pigeon_init(BuildInfoLinuxBuildInfoDataPigeon* self) {
}

static void build_info_linux_build_info_data_pigeon_class_init(BuildInfoLinuxBuildInfoDataPigeonClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = build_info_linux_build_info_data_pigeon_dispose;
}

BuildInfoLinuxBuildInfoDataPigeon* build_info_linux_build_info_data_pigeon_new(int64_t* build_date, int64_t* install_date) {
  BuildInfoLinuxBuildInfoDataPigeon* self = BUILD_INFO_LINUX_BUILD_INFO_DATA_PIGEON(g_object_new(build_info_linux_build_info_data_pigeon_get_type(), nullptr));
  if (build_date != nullptr) {
    self->build_date = static_cast<int64_t*>(malloc(sizeof(int64_t)));
    *self->build_date = *build_date;
  }
  else {
    self->build_date = nullptr;
  }
  if (install_date != nullptr) {
    self->install_date = static_cast<int64_t*>(malloc(sizeof(int64_t)));
    *self->install_date = *install_date;
  }
  else {
    self->install_date = nullptr;
  }
  return self;
}

int64_t* build_info_linux_build_info_data_pigeon_get_build_date(BuildInfoLinuxBuildInfoDataPigeon* self) {
  g_return_val_if_fail(BUILD_INFO_LINUX_IS_BUILD_INFO_DATA_PIGEON(self), nullptr);
  return self->build_date;
}

int64_t* build_info_linux_build_info_data_pigeon_get_install_date(BuildInfoLinuxBuildInfoDataPigeon* self) {
  g_return_val_if_fail(BUILD_INFO_LINUX_IS_BUILD_INFO_DATA_PIGEON(self), nullptr);
  return self->install_date;
}

static FlValue* build_info_linux_build_info_data_pigeon_to_list(BuildInfoLinuxBuildInfoDataPigeon* self) {
  FlValue* values = fl_value_new_list();
  fl_value_append_take(values, self->build_date != nullptr ? fl_value_new_int(*self->build_date) : fl_value_new_null());
  fl_value_append_take(values, self->install_date != nullptr ? fl_value_new_int(*self->install_date) : fl_value_new_null());
  return values;
}

static BuildInfoLinuxBuildInfoDataPigeon* build_info_linux_build_info_data_pigeon_new_from_list(FlValue* values) {
  FlValue* value0 = fl_value_get_list_value(values, 0);
  int64_t* build_date = nullptr;
  int64_t build_date_value;
  if (fl_value_get_type(value0) != FL_VALUE_TYPE_NULL) {
    build_date_value = fl_value_get_int(value0);
    build_date = &build_date_value;
  }
  FlValue* value1 = fl_value_get_list_value(values, 1);
  int64_t* install_date = nullptr;
  int64_t install_date_value;
  if (fl_value_get_type(value1) != FL_VALUE_TYPE_NULL) {
    install_date_value = fl_value_get_int(value1);
    install_date = &install_date_value;
  }
  return build_info_linux_build_info_data_pigeon_new(build_date, install_date);
}

struct _BuildInfoLinuxMessageCodec {
  FlStandardMessageCodec parent_instance;

};

G_DEFINE_TYPE(BuildInfoLinuxMessageCodec, build_info_linux_message_codec, fl_standard_message_codec_get_type())

static gboolean build_info_linux_message_codec_write_build_info_linux_build_info_data_pigeon(FlStandardMessageCodec* codec, GByteArray* buffer, BuildInfoLinuxBuildInfoDataPigeon* value, GError** error) {
  uint8_t type = 129;
  g_byte_array_append(buffer, &type, sizeof(uint8_t));
  g_autoptr(FlValue) values = build_info_linux_build_info_data_pigeon_to_list(value);
  return fl_standard_message_codec_write_value(codec, buffer, values, error);
}

static gboolean build_info_linux_message_codec_write_value(FlStandardMessageCodec* codec, GByteArray* buffer, FlValue* value, GError** error) {
  if (fl_value_get_type(value) == FL_VALUE_TYPE_CUSTOM) {
    switch (fl_value_get_custom_type(value)) {
      case 129:
        return build_info_linux_message_codec_write_build_info_linux_build_info_data_pigeon(codec, buffer, BUILD_INFO_LINUX_BUILD_INFO_DATA_PIGEON(fl_value_get_custom_value_object(value)), error);
    }
  }

  return FL_STANDARD_MESSAGE_CODEC_CLASS(build_info_linux_message_codec_parent_class)->write_value(codec, buffer, value, error);
}

static FlValue* build_info_linux_message_codec_read_build_info_linux_build_info_data_pigeon(FlStandardMessageCodec* codec, GBytes* buffer, size_t* offset, GError** error) {
  g_autoptr(FlValue) values = fl_standard_message_codec_read_value(codec, buffer, offset, error);
  if (values == nullptr) {
    return nullptr;
  }

  g_autoptr(BuildInfoLinuxBuildInfoDataPigeon) value = build_info_linux_build_info_data_pigeon_new_from_list(values);
  if (value == nullptr) {
    g_set_error(error, FL_MESSAGE_CODEC_ERROR, FL_MESSAGE_CODEC_ERROR_FAILED, "Invalid data received for MessageData");
    return nullptr;
  }

  return fl_value_new_custom_object(129, G_OBJECT(value));
}

static FlValue* build_info_linux_message_codec_read_value_of_type(FlStandardMessageCodec* codec, GBytes* buffer, size_t* offset, int type, GError** error) {
  switch (type) {
    case 129:
      return build_info_linux_message_codec_read_build_info_linux_build_info_data_pigeon(codec, buffer, offset, error);
    default:
      return FL_STANDARD_MESSAGE_CODEC_CLASS(build_info_linux_message_codec_parent_class)->read_value_of_type(codec, buffer, offset, type, error);
  }
}

static void build_info_linux_message_codec_init(BuildInfoLinuxMessageCodec* self) {
}

static void build_info_linux_message_codec_class_init(BuildInfoLinuxMessageCodecClass* klass) {
  FL_STANDARD_MESSAGE_CODEC_CLASS(klass)->write_value = build_info_linux_message_codec_write_value;
  FL_STANDARD_MESSAGE_CODEC_CLASS(klass)->read_value_of_type = build_info_linux_message_codec_read_value_of_type;
}

static BuildInfoLinuxMessageCodec* build_info_linux_message_codec_new() {
  BuildInfoLinuxMessageCodec* self = BUILD_INFO_LINUX_MESSAGE_CODEC(g_object_new(build_info_linux_message_codec_get_type(), nullptr));
  return self;
}

struct _BuildInfoLinuxBuildInfoHostApiFromPlatformResponse {
  GObject parent_instance;

  FlValue* value;
};

G_DEFINE_TYPE(BuildInfoLinuxBuildInfoHostApiFromPlatformResponse, build_info_linux_build_info_host_api_from_platform_response, G_TYPE_OBJECT)

static void build_info_linux_build_info_host_api_from_platform_response_dispose(GObject* object) {
  BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* self = BUILD_INFO_LINUX_BUILD_INFO_HOST_API_FROM_PLATFORM_RESPONSE(object);
  g_clear_pointer(&self->value, fl_value_unref);
  G_OBJECT_CLASS(build_info_linux_build_info_host_api_from_platform_response_parent_class)->dispose(object);
}

static void build_info_linux_build_info_host_api_from_platform_response_init(BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* self) {
}

static void build_info_linux_build_info_host_api_from_platform_response_class_init(BuildInfoLinuxBuildInfoHostApiFromPlatformResponseClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = build_info_linux_build_info_host_api_from_platform_response_dispose;
}

BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* build_info_linux_build_info_host_api_from_platform_response_new(BuildInfoLinuxBuildInfoDataPigeon* return_value) {
  BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* self = BUILD_INFO_LINUX_BUILD_INFO_HOST_API_FROM_PLATFORM_RESPONSE(g_object_new(build_info_linux_build_info_host_api_from_platform_response_get_type(), nullptr));
  self->value = fl_value_new_list();
  fl_value_append_take(self->value, fl_value_new_custom_object(129, G_OBJECT(return_value)));
  return self;
}

BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* build_info_linux_build_info_host_api_from_platform_response_new_error(const gchar* code, const gchar* message, FlValue* details) {
  BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* self = BUILD_INFO_LINUX_BUILD_INFO_HOST_API_FROM_PLATFORM_RESPONSE(g_object_new(build_info_linux_build_info_host_api_from_platform_response_get_type(), nullptr));
  self->value = fl_value_new_list();
  fl_value_append_take(self->value, fl_value_new_string(code));
  fl_value_append_take(self->value, fl_value_new_string(message != nullptr ? message : ""));
  fl_value_append_take(self->value, details != nullptr ? fl_value_ref(details) : fl_value_new_null());
  return self;
}

struct _BuildInfoLinuxBuildInfoHostApi {
  GObject parent_instance;

  const BuildInfoLinuxBuildInfoHostApiVTable* vtable;
  gpointer user_data;
  GDestroyNotify user_data_free_func;
};

G_DEFINE_TYPE(BuildInfoLinuxBuildInfoHostApi, build_info_linux_build_info_host_api, G_TYPE_OBJECT)

static void build_info_linux_build_info_host_api_dispose(GObject* object) {
  BuildInfoLinuxBuildInfoHostApi* self = BUILD_INFO_LINUX_BUILD_INFO_HOST_API(object);
  if (self->user_data != nullptr) {
    self->user_data_free_func(self->user_data);
  }
  self->user_data = nullptr;
  G_OBJECT_CLASS(build_info_linux_build_info_host_api_parent_class)->dispose(object);
}

static void build_info_linux_build_info_host_api_init(BuildInfoLinuxBuildInfoHostApi* self) {
}

static void build_info_linux_build_info_host_api_class_init(BuildInfoLinuxBuildInfoHostApiClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = build_info_linux_build_info_host_api_dispose;
}

static BuildInfoLinuxBuildInfoHostApi* build_info_linux_build_info_host_api_new(const BuildInfoLinuxBuildInfoHostApiVTable* vtable, gpointer user_data, GDestroyNotify user_data_free_func) {
  BuildInfoLinuxBuildInfoHostApi* self = BUILD_INFO_LINUX_BUILD_INFO_HOST_API(g_object_new(build_info_linux_build_info_host_api_get_type(), nullptr));
  self->vtable = vtable;
  self->user_data = user_data;
  self->user_data_free_func = user_data_free_func;
  return self;
}

static void build_info_linux_build_info_host_api_from_platform_cb(FlBasicMessageChannel* channel, FlValue* message_, FlBasicMessageChannelResponseHandle* response_handle, gpointer user_data) {
  BuildInfoLinuxBuildInfoHostApi* self = BUILD_INFO_LINUX_BUILD_INFO_HOST_API(user_data);

  if (self->vtable == nullptr || self->vtable->from_platform == nullptr) {
    return;
  }

  g_autoptr(BuildInfoLinuxBuildInfoHostApiFromPlatformResponse) response = self->vtable->from_platform(self->user_data);
  if (response == nullptr) {
    g_warning("No response returned to %s.%s", "BuildInfoHostApi", "fromPlatform");
    return;
  }

  g_autoptr(GError) error = NULL;
  if (!fl_basic_message_channel_respond(channel, response_handle, response->value, &error)) {
    g_warning("Failed to send response to %s.%s: %s", "BuildInfoHostApi", "fromPlatform", error->message);
  }
}

void build_info_linux_build_info_host_api_set_method_handlers(FlBinaryMessenger* messenger, const gchar* suffix, const BuildInfoLinuxBuildInfoHostApiVTable* vtable, gpointer user_data, GDestroyNotify user_data_free_func) {
  g_autofree gchar* dot_suffix = suffix != nullptr ? g_strdup_printf(".%s", suffix) : g_strdup("");
  g_autoptr(BuildInfoLinuxBuildInfoHostApi) api_data = build_info_linux_build_info_host_api_new(vtable, user_data, user_data_free_func);

  g_autoptr(BuildInfoLinuxMessageCodec) codec = build_info_linux_message_codec_new();
  g_autofree gchar* from_platform_channel_name = g_strdup_printf("dev.flutter.pigeon.build_info_linux.BuildInfoHostApi.fromPlatform%s", dot_suffix);
  g_autoptr(FlBasicMessageChannel) from_platform_channel = fl_basic_message_channel_new(messenger, from_platform_channel_name, FL_MESSAGE_CODEC(codec));
  fl_basic_message_channel_set_message_handler(from_platform_channel, build_info_linux_build_info_host_api_from_platform_cb, g_object_ref(api_data), g_object_unref);
}

void build_info_linux_build_info_host_api_clear_method_handlers(FlBinaryMessenger* messenger, const gchar* suffix) {
  g_autofree gchar* dot_suffix = suffix != nullptr ? g_strdup_printf(".%s", suffix) : g_strdup("");

  g_autoptr(BuildInfoLinuxMessageCodec) codec = build_info_linux_message_codec_new();
  g_autofree gchar* from_platform_channel_name = g_strdup_printf("dev.flutter.pigeon.build_info_linux.BuildInfoHostApi.fromPlatform%s", dot_suffix);
  g_autoptr(FlBasicMessageChannel) from_platform_channel = fl_basic_message_channel_new(messenger, from_platform_channel_name, FL_MESSAGE_CODEC(codec));
  fl_basic_message_channel_set_message_handler(from_platform_channel, nullptr, nullptr, nullptr);
}
