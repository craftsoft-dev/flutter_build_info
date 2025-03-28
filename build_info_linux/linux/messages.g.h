// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
// Autogenerated from Pigeon (v25.1.0), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#ifndef PIGEON_MESSAGES_G_H_
#define PIGEON_MESSAGES_G_H_

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

/**
 * BuildInfoLinuxBuildInfoDataPigeon:
 *
 */

G_DECLARE_FINAL_TYPE(BuildInfoLinuxBuildInfoDataPigeon, build_info_linux_build_info_data_pigeon, BUILD_INFO_LINUX, BUILD_INFO_DATA_PIGEON, GObject)

/**
 * build_info_linux_build_info_data_pigeon_new:
 * build_date: field in this object.
 * install_date: field in this object.
 *
 * Creates a new #BuildInfoDataPigeon object.
 *
 * Returns: a new #BuildInfoLinuxBuildInfoDataPigeon
 */
BuildInfoLinuxBuildInfoDataPigeon* build_info_linux_build_info_data_pigeon_new(int64_t* build_date, int64_t* install_date);

/**
 * build_info_linux_build_info_data_pigeon_get_build_date
 * @object: a #BuildInfoLinuxBuildInfoDataPigeon.
 *
 * Gets the value of the buildDate field of @object.
 *
 * Returns: the field value.
 */
int64_t* build_info_linux_build_info_data_pigeon_get_build_date(BuildInfoLinuxBuildInfoDataPigeon* object);

/**
 * build_info_linux_build_info_data_pigeon_get_install_date
 * @object: a #BuildInfoLinuxBuildInfoDataPigeon.
 *
 * Gets the value of the installDate field of @object.
 *
 * Returns: the field value.
 */
int64_t* build_info_linux_build_info_data_pigeon_get_install_date(BuildInfoLinuxBuildInfoDataPigeon* object);

G_DECLARE_FINAL_TYPE(BuildInfoLinuxMessageCodec, build_info_linux_message_codec, BUILD_INFO_LINUX, MESSAGE_CODEC, FlStandardMessageCodec)

G_DECLARE_FINAL_TYPE(BuildInfoLinuxBuildInfoHostApi, build_info_linux_build_info_host_api, BUILD_INFO_LINUX, BUILD_INFO_HOST_API, GObject)

G_DECLARE_FINAL_TYPE(BuildInfoLinuxBuildInfoHostApiFromPlatformResponse, build_info_linux_build_info_host_api_from_platform_response, BUILD_INFO_LINUX, BUILD_INFO_HOST_API_FROM_PLATFORM_RESPONSE, GObject)

/**
 * build_info_linux_build_info_host_api_from_platform_response_new:
 *
 * Creates a new response to BuildInfoHostApi.fromPlatform.
 *
 * Returns: a new #BuildInfoLinuxBuildInfoHostApiFromPlatformResponse
 */
BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* build_info_linux_build_info_host_api_from_platform_response_new(BuildInfoLinuxBuildInfoDataPigeon* return_value);

/**
 * build_info_linux_build_info_host_api_from_platform_response_new_error:
 * @code: error code.
 * @message: error message.
 * @details: (allow-none): error details or %NULL.
 *
 * Creates a new error response to BuildInfoHostApi.fromPlatform.
 *
 * Returns: a new #BuildInfoLinuxBuildInfoHostApiFromPlatformResponse
 */
BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* build_info_linux_build_info_host_api_from_platform_response_new_error(const gchar* code, const gchar* message, FlValue* details);

/**
 * BuildInfoLinuxBuildInfoHostApiVTable:
 *
 * Table of functions exposed by BuildInfoHostApi to be implemented by the API provider.
 */
typedef struct {
  BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* (*from_platform)(gpointer user_data);
} BuildInfoLinuxBuildInfoHostApiVTable;

/**
 * build_info_linux_build_info_host_api_set_method_handlers:
 *
 * @messenger: an #FlBinaryMessenger.
 * @suffix: (allow-none): a suffix to add to the API or %NULL for none.
 * @vtable: implementations of the methods in this API.
 * @user_data: (closure): user data to pass to the functions in @vtable.
 * @user_data_free_func: (allow-none): a function which gets called to free @user_data, or %NULL.
 *
 * Connects the method handlers in the BuildInfoHostApi API.
 */
void build_info_linux_build_info_host_api_set_method_handlers(FlBinaryMessenger* messenger, const gchar* suffix, const BuildInfoLinuxBuildInfoHostApiVTable* vtable, gpointer user_data, GDestroyNotify user_data_free_func);

/**
 * build_info_linux_build_info_host_api_clear_method_handlers:
 *
 * @messenger: an #FlBinaryMessenger.
 * @suffix: (allow-none): a suffix to add to the API or %NULL for none.
 *
 * Clears the method handlers in the BuildInfoHostApi API.
 */
void build_info_linux_build_info_host_api_clear_method_handlers(FlBinaryMessenger* messenger, const gchar* suffix);

G_END_DECLS

#endif  // PIGEON_MESSAGES_G_H_
