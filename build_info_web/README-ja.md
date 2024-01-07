# build_info_web

[`build_info`][1]のWeb実装です。

## 使い方

このパッケージは承認されていて、通常は単に `build_info` を使用するだけです。このパッケージはアプリに自動的に組み込まれるため `pubspec.yaml` に追加する必要はありません。

ただし、このパッケージを `import` してAPIを直接利用する場合は `pubspec.yaml` に追加する必要があります。

## Web版の実装について

Web版のbuild_infoの動作は以下の通りです。

1. Flutter から BuildInfo.fromPlatform メソッドを呼び出す。
2. ビルド日時として "version.json" をHEADまたはGETメソッドでリクエストし `Last-Modified` または `Date` レスポンスヘッダの値を利用します。
3. "version.json" から日時を取得できない場合 [`document.lastModified`][web-1] の値を利用します。て利用します。

日時を取得できなかった場合、 null となります。  
Web版ではインストール日時は常に null となります。

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
[web-1]: https://developer.mozilla.org/docs/Web/API/Document/lastModified
