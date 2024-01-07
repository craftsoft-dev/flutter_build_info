// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'dart:typed_data';
import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:build_info_linux/build_info_linux.dart';
import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/method_channel_build_info.dart';
import 'package:build_info_platform_interface/build_info_platform_interface.dart';

const kBuildDateMills = 123000;
const kInstallDateMills = 456000;

void main() {
  TestWidgetsFlutterBinding.ensureInitialized();

  const MethodChannel channel = MethodChannel('dev.craftsoft/build_info_linux');

  final BuildInfoPlatform initialPlatform = BuildInfoPlatform.instance;

  test('$MethodChannelBuildInfo is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelBuildInfo>());
  });

  setUp(() {
    BuildInfoLinux.registerWith();

    TestDefaultBinaryMessengerBinding.instance.defaultBinaryMessenger
        .setMockMethodCallHandler(
      channel,
      (MethodCall methodCall) async {
        return Int64List.fromList([kBuildDateMills, kInstallDateMills]);
      },
    );
  });

  tearDown(() {
    TestDefaultBinaryMessengerBinding.instance.defaultBinaryMessenger
        .setMockMethodCallHandler(channel, null);
  });

  test('fromPlatform', () async {
    expect(
      await BuildInfoPlatform.instance.fromPlatform(),
      BuildInfoData.fromMillisecondsSinceEpoch(
        buildDate: kBuildDateMills,
        installDate: kInstallDateMills,
        isUtc: true,
      ),
    );
  });
}
