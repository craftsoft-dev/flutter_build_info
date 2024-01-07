// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/method_channel_build_info.dart';
import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';

const kBuildDateMills = 123000;
const kInstallDateMills = 456000;

void main() {
  TestWidgetsFlutterBinding.ensureInitialized();

  MethodChannelBuildInfo platform = MethodChannelBuildInfo();
  const MethodChannel channel = MethodChannel('dev.craftsoft/build_info');

  setUp(() {
    TestDefaultBinaryMessengerBinding.instance.defaultBinaryMessenger.setMockMethodCallHandler(
      channel,
      (MethodCall methodCall) async {
        return {'buildDate': kBuildDateMills, 'installDate': kInstallDateMills};
      },
    );
  });

  tearDown(() {
    TestDefaultBinaryMessengerBinding.instance.defaultBinaryMessenger.setMockMethodCallHandler(channel, null);
  });

  test('fromPlatform', () async {
    expect(
      await platform.fromPlatform(),
      BuildInfoData.fromMillisecondsSinceEpoch(
        buildDate: kBuildDateMills,
        installDate: kInstallDateMills,
      ),
    );
  });
}
