# build_info_ios

The iOS implementation of [`build_info`][1].

## Usage

This package is [endorsed][2], which means you can simply use `build_info` normally. This package will be automatically included in your app when you do, so you do not need to add it to your `pubspec.yaml`.

However, if you `import` this package to use any of its APIs directly, you should add it to your `pubspec.yaml` as usual.

## About implementation of iOS version

The iOS version of build_info works as follows.

1. Call the BuildInfo.fromPlatform method from Flutter.
2. Use [`path(forResource:ofType:)`][apple-1] to get the last modification date and time of the bundled Info.plist file and use it as the build date and time.
3. Get the creation date and time of [Document Directory][apple-2] as the installation date and time.
4. Returns the value obtained in "2." and "3.".

If each date and time cannot be obtained, it will be null.

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
[apple-1]: https://developer.apple.com/documentation/foundation/bundle/1410989-path
[apple-2]: https://developer.apple.com/documentation/foundation/filemanager/searchpathdirectory/documentdirectory
