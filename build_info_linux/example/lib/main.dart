// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:build_info_platform_interface/build_info_data.dart';
import 'package:build_info_linux/build_info_linux.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  BuildInfoData? _buildInfoData;
  final _buildInfoLinuxPlugin = BuildInfoLinux();

  @override
  void initState() {
    super.initState();
    initPlatformState();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initPlatformState() async {
    BuildInfoData? buildInfoData;
    // Platform messages may fail, so we use a try/catch PlatformException.
    // We also handle the message potentially returning null.
    try {
      buildInfoData = await _buildInfoLinuxPlugin.fromPlatform();
    } on PlatformException catch (e, stackTrace) {
      debugPrint(e.message);
      debugPrintStack(stackTrace: stackTrace);
    }

    // If the widget was removed from the tree while the asynchronous platform
    // message was in flight, we want to discard the reply rather than calling
    // setState to update our non-existent appearance.
    if (!mounted) return;

    setState(() {
      _buildInfoData = buildInfoData;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text('BuildDate: ${_buildInfoData?.buildDate}'),
              Text('InstallDate: ${_buildInfoData?.installDate}'),
            ],
          ),
        ),
      ),
    );
  }
}
