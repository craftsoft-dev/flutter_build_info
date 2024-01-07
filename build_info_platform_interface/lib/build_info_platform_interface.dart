// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'build_info_data.dart';
import 'method_channel_build_info.dart';

/// The interface that implementations of build_info must implement.
///
/// Platform implementations should extend this class rather than implement it as `build_info`
/// does not consider newly added methods to be breaking changes. Extending this class
/// (using `extends`) ensures that the subclass will get the default implementation, while
/// platform implementations that `implements` this interface will be broken by newly added
/// [BuildInfoPlatform] methods.
abstract class BuildInfoPlatform extends PlatformInterface {
  /// Constructs a BuildInfoPlatform.
  BuildInfoPlatform() : super(token: _token);

  static final Object _token = Object();

  static BuildInfoPlatform _instance = MethodChannelBuildInfo();

  /// The default instance of [BuildInfoPlatform] to use.
  ///
  /// Defaults to [MethodChannelBuildInfo].
  static BuildInfoPlatform get instance => _instance;

  /// Platform-specific plugins should set this with their own platform-specific
  /// class that extends [BuildInfoPlatform] when they register themselves.
  static set instance(BuildInfoPlatform instance) {
    PlatformInterface.verify(instance, _token);
    _instance = instance;
  }

  /// Get [BuildInfoData] from the platform.
  Future<BuildInfoData> fromPlatform() {
    throw UnimplementedError('fromPlatform() has not been implemented.');
  }
}
