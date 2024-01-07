# build_info_macos

[`build_info`][1]のmacOS実装です。

## 使い方

このパッケージは承認されていて、通常は単に `build_info` を使用するだけです。このパッケージはアプリに自動的に組み込まれるため `pubspec.yaml` に追加する必要はありません。

ただし、このパッケージを `import` してAPIを直接利用する場合は `pubspec.yaml` に追加する必要があります。

## macOS版の実装について

macOS版のbuild_infoの動作は以下の通りです。

1. Flutter から BuildInfo.fromPlatform メソッドを呼び出す。
2. ビルド日時として[`path(forResource:ofType:)`][apple-1]を利用してバンドルされている _CodeSignature/CodeResources ファイルの最終更新日時を取得。
3. インストール日時として[`MDItemCreateWithURL`][apple-3]を利用してバンドルの作成日時を取得。

各日時を取得できなかった場合、 null となります。

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
[apple-1]: https://developer.apple.com/documentation/foundation/bundle/1410989-path
[apple-3]: https://developer.apple.com/documentation/coreservices/1427034-mditemcreatewithurl
