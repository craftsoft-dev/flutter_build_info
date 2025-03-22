// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:build_info_macos/src/messages.g.dart';
import 'package:build_info_macos/build_info_macos.dart';
import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/build_info_platform_interface.dart';
import 'package:flutter_test/flutter_test.dart';

const kBuildDateMills = 123000;
const kInstallDateMills = 456000;

void main() {
  late _FakeBuildInfoHostApi api;

  setUp(() {
    api = _FakeBuildInfoHostApi();
  });

  test('registers instance', () {
    BuildInfoMacOS.registerWith();
    expect(BuildInfoPlatform.instance, isA<BuildInfoMacOS>());
  });

  test('fromPlatform', () async {
    final platform = BuildInfoMacOS(api: api);
    final data = await platform.fromPlatform();

    expect(data, BuildInfoData.fromMillisecondsSinceEpoch(
      buildDate: kBuildDateMills,
      installDate: kInstallDateMills,
      isUtc: true,
    ));
  });
}


class _FakeBuildInfoHostApi extends BuildInfoHostApi {
  @override
  Future<BuildInfoDataPigeon> fromPlatform() async {
    return BuildInfoDataPigeon(buildDate: kBuildDateMills, installDate: kInstallDateMills);
  }
}
