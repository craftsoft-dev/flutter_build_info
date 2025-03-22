// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/build_info_platform_interface.dart';
import 'package:flutter/foundation.dart' show visibleForTesting;

import 'src/messages.g.dart';

/// An implementation of [BuildInfoPlatform] for Linux.
class BuildInfoLinux extends BuildInfoPlatform {
  final BuildInfoHostApi _hostApi;

  /// Creates a new plugin implementation instance.
  BuildInfoLinux({
    @visibleForTesting BuildInfoHostApi? api,
  }) : _hostApi = api ?? BuildInfoHostApi();

  /// Registers this class as the default instance of [BuildInfoPlatform].
  static void registerWith() {
    BuildInfoPlatform.instance = BuildInfoLinux();
  }

  @override
  Future<BuildInfoData> fromPlatform() async {
    final data = await _hostApi.fromPlatform();

    return BuildInfoData.fromMillisecondsSinceEpoch(
      buildDate: data.buildDate != -1 ? data.buildDate : null,
      installDate: data.installDate != -1 ? data.installDate : null,
      isUtc: true,
    );
  }
}
