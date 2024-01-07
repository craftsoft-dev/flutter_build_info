// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'build_info_data.dart';
import 'build_info_platform_interface.dart';

/// An implementation of [BuildInfoPlatform] that uses method channels.
class MethodChannelBuildInfo extends BuildInfoPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('dev.craftsoft/build_info');

  @override
  Future<BuildInfoData> fromPlatform() async {
    final map =
        await methodChannel.invokeMapMethod<String, dynamic>('fromPlatform');

    int? buildDate, installDate;

    if (map?.containsKey('buildDate') == true && map?['buildDate'] is int) {
      buildDate = map!['buildDate'];
    }

    if (map?.containsKey('installDate') == true && map?['installDate'] is int) {
      installDate = map!['installDate'];
    }

    return BuildInfoData.fromMillisecondsSinceEpoch(
      buildDate: buildDate,
      installDate: installDate,
    );
  }
}
