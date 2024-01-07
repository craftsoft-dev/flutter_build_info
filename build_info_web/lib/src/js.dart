// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'dart:js';
import 'package:flutter/foundation.dart';

/// Get the document object as an instance of [JsObject].
JsObject? getJsDocument() {
  JsObject? value;

  try {
    value = JsObject.fromBrowserObject(context['document']);
  } catch (e) {
    debugPrint('build_info_web: $e');
  }

  return value;
}

/// Get the property value of the document object specified by [name].
String? getJsDocumentProperty(String name) {
  String? value;

  try {
    final jsDocument = getJsDocument();
    value = jsDocument?[name]?.toString();
  } catch (e) {
    debugPrint('build_info_web: $e');
  }

  return value;
}

/// Get document.lastModified as an instance of DateTime.
DateTime? getJsDocumentLastModified() {
  final lastModified = getJsDocumentProperty('lastModified');
  if (lastModified == null) {
    return null;
  }

  return converStrToDateTimeUseJsDate(lastModified);
}

/// Convert the time string passed as [datetime] to DateTime using
/// the getTime method of the JavaScript Date object.
DateTime? converStrToDateTimeUseJsDate(String datetime) {
  final jsObject = JsObject(context['Date'], [datetime]);
  final num = jsObject.callMethod('getTime');

  if (num.isNaN) {
    return null;
  }

  return DateTime.fromMillisecondsSinceEpoch(num);
}
