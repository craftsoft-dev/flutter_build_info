// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:integration_test/integration_test.dart';
import 'package:build_info_android/build_info_android.dart';

void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized();

  testWidgets('fromPlatform test', (WidgetTester tester) async {
    final BuildInfoAndroid plugin = BuildInfoAndroid();
    final BuildInfoData buildInfoData = await plugin.fromPlatform();
    
    expect(buildInfoData.buildDate != null, true);
  });
}
