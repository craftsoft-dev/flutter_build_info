// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:pigeon/pigeon.dart';

@ConfigurePigeon(PigeonOptions(
  dartOut: 'lib/src/messages.g.dart',
  swiftOptions: SwiftOptions(),
  swiftOut: 'ios/Classes/messages.g.swift',
  copyrightHeader: 'pigeons/copyright.txt',
  dartPackageName: 'build_info_ios',
))

class BuildInfoDataPigeon {
  late int? buildDate;
  late int? installDate;
}

@HostApi()
abstract class BuildInfoHostApi {
  BuildInfoDataPigeon fromPlatform();
}
