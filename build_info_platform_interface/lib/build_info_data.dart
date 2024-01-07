// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

/// A class that holds build date and time and installation date and time.
class BuildInfoData {
  /// Build date and time.
  final DateTime? buildDate;

  /// Installation date and time.
  final DateTime? installDate;

  /// Constructs with a DateTime.
  BuildInfoData({this.buildDate, this.installDate});

  /// Constructs a new [BuildInfoData] instance with the given millisecondsSinceEpoch.
  ///
  /// If [isUtc] is false then the date is in the local time zone.
  factory BuildInfoData.fromMillisecondsSinceEpoch({
    int? buildDate,
    int? installDate,
    bool isUtc = false,
  }) {
    final buildDateTime = buildDate == null
        ? null
        : DateTime.fromMillisecondsSinceEpoch(
            buildDate,
            isUtc: isUtc,
          );

    final installDateTime = installDate == null
        ? null
        : DateTime.fromMillisecondsSinceEpoch(
            installDate,
            isUtc: isUtc,
          );

    return BuildInfoData(
      buildDate: buildDateTime,
      installDate: installDateTime,
    );
  }

  @override
  int get hashCode => Object.hash(buildDate, installDate);

  @override
  bool operator ==(Object other) {
    if (identical(this, other)) {
      return true;
    }

    if (other.runtimeType != runtimeType) {
      return false;
    }

    return other is BuildInfoData &&
        other.buildDate == buildDate &&
        other.installDate == installDate;
  }

  @override
  String toString() {
    return '{buildDate:$buildDate, installDate:$installDate}';
  }
}
