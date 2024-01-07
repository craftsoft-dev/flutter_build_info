# build_info_web

The Web implementation of [`build_info`][1].

## Usage

This package is [endorsed][2], which means you can simply use `build_info` normally. This package will be automatically included in your app when you do, so you do not need to add it to your `pubspec.yaml`.

However, if you `import` this package to use any of its APIs directly, you should add it to your `pubspec.yaml` as usual.

## About implementation of Web version

The Web version of build_info works as follows.

1. Call the BuildInfo.fromPlatform method from Flutter.
2. Request "version.json" as the build date and time using the HEAD or GET method and use the `Last-Modified` or `Date` response header value.
3. If the date and time cannot be obtained from "version.json", use the value of [`document.lastModified`][web-1].

If the date and time could not be obtained, it will be null.  
In the Web version, the installation date and time is always null.

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
[web-1]: https://developer.mozilla.org/docs/Web/API/Document/lastModified
