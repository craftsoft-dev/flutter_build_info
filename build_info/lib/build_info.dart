// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/build_info_platform_interface.dart';

export 'package:build_info_platform_interface/build_info_data.dart'
    show BuildInfoData;

/// BuildInfo class
class BuildInfo {
  /// Get the [BuildInfoPlatform] instance.
  static BuildInfoPlatform get platform => BuildInfoPlatform.instance;

  /// Get [BuildInfoData] from the platform.
  static Future<BuildInfoData?> fromPlatform() {
    return platform.fromPlatform();
  }
}
