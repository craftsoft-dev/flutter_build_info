// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';
import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/build_info_platform_interface.dart';

const MethodChannel _channel = MethodChannel('dev.craftsoft/build_info_linux');

/// An implementation of [BuildInfoPlatform] for Linux.
class BuildInfoLinux extends BuildInfoPlatform {
  /// Registers this class as the default instance of [BuildInfoPlatform].
  static void registerWith() {
    BuildInfoPlatform.instance = BuildInfoLinux();
  }

  @override
  Future<BuildInfoData> fromPlatform() async {
    final data = await _channel.invokeMethod<Int64List>('fromPlatform');

    final dataLen = data?.length ?? 0;
    final buildDateInt = dataLen >= 1 ? data?.elementAt(0) : null;
    final installDateInt = dataLen >= 2 ? data?.elementAt(1) : null;

    return BuildInfoData.fromMillisecondsSinceEpoch(
      buildDate: buildDateInt != -1 ? buildDateInt : null,
      installDate: installDateInt != -1 ? installDateInt : null,
      isUtc: true,
    );
  }
}
