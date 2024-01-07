// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'dart:js_interop';
import 'dart:js_util';

import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:integration_test/integration_test.dart';

import 'package:build_info_web/build_info_web.dart';

void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized();

  testWidgets('fromPlatform test', (WidgetTester tester) async {
    final BuildInfoWeb plugin = BuildInfoWeb();
    final BuildInfoData buildInfoData = await plugin.fromPlatform();
    
    expect(buildInfoData.buildDate != null, true);
  });
}
