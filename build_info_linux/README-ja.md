# build_info_linux

[`build_info`][1]のLinux実装です。

## 使い方

このパッケージは承認されていて、通常は単に `build_info` を使用するだけです。このパッケージはアプリに自動的に組み込まれるため `pubspec.yaml` に追加する必要はありません。

ただし、このパッケージを `import` してAPIを直接利用する場合は `pubspec.yaml` に追加する必要があります。

## Linux版の実装について

Linux版のbuild_infoの動作は以下の通りです。

1. ビルド時に linux/CMakeLists.txt により BUILD_INFO_TIMESTAMP 定数が定義されビルド時のミリ秒が設定されます。
2. Flutter から BuildInfo.fromPlatform メソッドを呼び出す。
3. ビルド日時として BUILD_INFO_TIMESTAMP 定数の値が設定されます。

Linux版ではインストール日時は常に null となります。

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
