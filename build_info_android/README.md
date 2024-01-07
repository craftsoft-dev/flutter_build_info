# build_info_android

The Android implementation of [`build_info`][1].

## Usage

This package is [endorsed][2], which means you can simply use `build_info` normally. This package will be automatically included in your app when you do, so you do not need to add it to your `pubspec.yaml`.

However, if you `import` this package to use any of its APIs directly, you should add it to your `pubspec.yaml` as usual.

## About implementation of Android version

The Android version of build_info works as follows.

1. When building, android/build.gradle included in this package adds a field called BUILDINFO_TIMESTAMP to the BuildConfig class and sets the build time in milliseconds.
2. Calling the BuildInfo.fromPlatform method from Flutter returns the value of BuildConfig.BUILDINFO_TIMESTAMP and the value of [`firstInstallTime`][android-1] obtained from PackageInfo.

If firstInstallTime cannot be obtained, the installation date and time will be null.

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
[android-1]: https://developer.android.com/reference/android/content/pm/PackageInfo#firstInstallTime
