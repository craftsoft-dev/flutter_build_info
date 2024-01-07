// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:flutter/foundation.dart' show visibleForTesting;
import 'package:build_info_platform_interface/build_info_platform_interface.dart';

import 'src/messages.g.dart';

/// An implementation of [BuildInfoPlatform] for Windows.
class BuildInfoWindows extends BuildInfoPlatform {
  final BuildInfoHostApi _hostApi;

  /// Creates a new plugin implementation instance.
  BuildInfoWindows({
    @visibleForTesting BuildInfoHostApi? api,
  }) : _hostApi = api ?? BuildInfoHostApi();

  /// Registers this class as the default instance of [BuildInfoPlatform].
  static void registerWith() {
    BuildInfoPlatform.instance = BuildInfoWindows();
  }

  @override
  Future<BuildInfoData> fromPlatform() async {
    final data = await _hostApi.fromPlatform();

    return BuildInfoData.fromMillisecondsSinceEpoch(
      buildDate: data.buildDate,
      installDate: data.installDate,
      isUtc: true,
    );
  }
}