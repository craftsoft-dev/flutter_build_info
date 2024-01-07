// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/build_info_platform_interface.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:build_info/build_info.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

const kBuildDateMills = 123000;
const kInstallDateMills = 456000;

void main() {
  setUp(() {
    final mock = MockBuildInfoPlatform();
    BuildInfoPlatform.instance = mock;
  });

  test('fromPlatform', () async {
    expect(
      await BuildInfo.fromPlatform(),
      BuildInfoData.fromMillisecondsSinceEpoch(
        buildDate: kBuildDateMills,
        installDate: kInstallDateMills,
      ),
    );
  });
}

class MockBuildInfoPlatform
    with MockPlatformInterfaceMixin
    implements BuildInfoPlatform {
  @override
  Future<BuildInfoData> fromPlatform() => Future.value(
    BuildInfoData.fromMillisecondsSinceEpoch(buildDate: kBuildDateMills, installDate: kInstallDateMills)
  );
}
