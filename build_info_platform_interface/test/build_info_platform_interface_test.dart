// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/method_channel_build_info.dart';
import 'package:build_info_platform_interface/build_info_platform_interface.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

void main() {
  final BuildInfoPlatform initialPlatform = BuildInfoPlatform.instance;

  tearDown(() {
    BuildInfoPlatform.instance = initialPlatform;
  });

  test('$MethodChannelBuildInfo is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelBuildInfo>());
  });

  test('Cannot be implemented with `implements`', () {
    expect(() {
      BuildInfoPlatform.instance = ImplementsBuildInfoPlatform();
    }, throwsAssertionError);
  });

  test('Can be extended.', () {
    BuildInfoPlatform.instance = ExtendsBuildInfoPlatform();
  });

  test('Can be mocked with `implements`.', () async {
    final mock = MockBuildInfoPlatform();
    BuildInfoPlatform.instance = mock;
  });
}

class ImplementsBuildInfoPlatform implements BuildInfoPlatform {
  @override
  dynamic noSuchMethod(Invocation invocation) => super.noSuchMethod(invocation);
}

class MockBuildInfoPlatform
    with MockPlatformInterfaceMixin
    implements BuildInfoPlatform {
  @override
  Future<BuildInfoData> fromPlatform() => Future.value(BuildInfoData());
}

class ExtendsBuildInfoPlatform extends BuildInfoPlatform {}
