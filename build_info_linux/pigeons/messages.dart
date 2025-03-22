// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:pigeon/pigeon.dart';

@ConfigurePigeon(PigeonOptions(
  dartOut: 'lib/src/messages.g.dart',
  gobjectHeaderOut: 'linux/messages.g.h',
  gobjectSourceOut: 'linux/messages.g.cc',
  gobjectOptions: GObjectOptions(),
  copyrightHeader: 'pigeons/copyright.txt',
  dartPackageName: 'build_info_linux',
))

class BuildInfoDataPigeon {
  late int? buildDate;
  late int? installDate;
}

@HostApi()
abstract class BuildInfoHostApi {
  BuildInfoDataPigeon fromPlatform();
}
