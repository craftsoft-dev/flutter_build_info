// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

package dev.craftsoft.buildinfo

import androidx.annotation.NonNull
import androidx.annotation.Nullable

import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.embedding.engine.plugins.activity.ActivityAware
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result

/** BuildInfoPlugin */
class BuildInfoPlugin: FlutterPlugin, ActivityAware {
  /// The MethodChannel that will the communication between Flutter and native Android
  ///
  /// This local reference serves to register the plugin with the Flutter Engine and unregister it
  /// when the Flutter Engine is detached from the Activity
  private lateinit var channel : MethodChannel

  private var buildInfo: BuildInfo? = null

  override fun onAttachedToEngine(flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
    // channel = MethodChannel(flutterPluginBinding.binaryMessenger, "buildinfo")
    // channel.setMethodCallHandler(this)
    buildInfo = BuildInfo()
    BuildInfoHostApi.setUp(flutterPluginBinding.binaryMessenger, buildInfo)
  }

  // override fun onMethodCall(call: MethodCall, result: Result) {
  //   if (call.method == "getPlatformVersion") {
  //     result.success("Android ${android.os.Build.VERSION.RELEASE}")
  //   } else {
  //     result.notImplemented()
  //   }
  // }

  override fun onDetachedFromEngine(binding: FlutterPlugin.FlutterPluginBinding) {
    // channel.setMethodCallHandler(null)
    if (buildInfo == null) {
      return
    }

    BuildInfoHostApi.setUp(binding.binaryMessenger, null)
    buildInfo = null
  }

  // Implement ActivityAware
  override fun onAttachedToActivity(binding: ActivityPluginBinding) {
    buildInfo?.setActivity(binding.activity)
  }

  override fun onDetachedFromActivity() {
    buildInfo?.setActivity(null)
  }

  override fun onDetachedFromActivityForConfigChanges() {
    onDetachedFromActivity()
  }

  override fun onReattachedToActivityForConfigChanges(binding: ActivityPluginBinding) {
    onAttachedToActivity(binding)
  }
}
