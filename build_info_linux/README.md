# build_info_linux

The Linux implementation of [`build_info`][1].

## Usage

This package is [endorsed][2], which means you can simply use `build_info` normally. This package will be automatically included in your app when you do, so you do not need to add it to your `pubspec.yaml`.

However, if you `import` this package to use any of its APIs directly, you should add it to your `pubspec.yaml` as usual.

## About implementation of Linux version

The Linux version of build_info works as follows.

1. At build time, linux/CMakeLists.txt defines the BUILD_INFO_TIMESTAMP constant and sets the build time in milliseconds.
2. Call the BuildInfo.fromPlatform method from Flutter.
3. The value of the BUILD_INFO_TIMESTAMP constant is set as the build date and time.

In the Linux version, the installation date and time is always null.

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
