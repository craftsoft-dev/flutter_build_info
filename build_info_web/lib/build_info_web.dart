// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:http/http.dart' as http;
import 'package:flutter_web_plugins/flutter_web_plugins.dart' show Registrar;
import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_platform_interface/build_info_platform_interface.dart';

import 'src/js.dart';

/// An implementation of [BuildInfoPlatform] for Web.
class BuildInfoWeb extends BuildInfoPlatform {
  /// Registers this class as the default instance of [BuildInfoPlatform].
  static void registerWith(Registrar? registrar) {
    BuildInfoPlatform.instance = BuildInfoWeb();
  }

  /// Obtained build date and time
  DateTime? _buildDate;

  @override
  Future<BuildInfoData> fromPlatform() async {
    if (_buildDate == null) {
      // version.json
      _buildDate = await _getVersionJsonLastModifiedAt();

      // Document last modified.
      _buildDate ??= getJsDocumentLastModified();
    }

    return BuildInfoData(
      buildDate: _buildDate,
      installDate: null,
    );
  }

  /// Get the modification date and time of "version.json".
  Future<DateTime?> _getVersionJsonLastModifiedAt() async {
    final baseUri = getJsDocumentProperty('baseURI');
    if (baseUri == null) {
      return null;
    }

    final url = _createVersionJsonUrl(baseUri);
    http.Response response = await http.head(url);

    if (response.statusCode < 200 || response.statusCode > 299) {
      // If HEAD request fails, perform GET request.
      response = await http.get(url);
    }

    if (response.statusCode < 200 || response.statusCode > 299) {
      return null;
    }

    final headers = response.headers;
    String? value;

    if (headers.containsKey('last-modified')) {
      value = headers['last-modified'];
    } else if (headers.containsKey('date')) {
      value = headers['date'];
    }

    if (value == null) {
      return null;
    }

    return converStrToDateTimeUseJsDate(value);
  }

  /// Create a URL to version.json from the URL passed in [baseUrl].
  Uri _createVersionJsonUrl(String baseUrl) {
    final baseUri = Uri.parse(baseUrl);
    final regExp = RegExp(r'[^/]+\.html.*');
    final path = '${baseUri.origin}${baseUri.path.replaceAll(regExp, '')}';

    Uri uri = Uri.parse(path).removeFragment().replace(query: null);

    if (uri.path.length > 1 &&
        !uri.path.endsWith('/') &&
        (uri.isScheme('http') || uri.isScheme('https'))) {
      uri = uri.replace(path: uri.path.substring(0, uri.path.lastIndexOf('/')));
    }

    final segments = [...uri.pathSegments]..removeWhere((elem) => elem == '');

    return uri.replace(
      pathSegments: [...segments, 'version.json'],
    );
  }
}
