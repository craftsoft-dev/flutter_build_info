# build_info_windows

[`build_info`][1]のWindows実装です。

## 使い方

このパッケージは承認されていて、通常は単に `build_info` を使用するだけです。このパッケージはアプリに自動的に組み込まれるため `pubspec.yaml` に追加する必要はありません。

ただし、このパッケージを `import` してAPIを直接利用する場合は `pubspec.yaml` に追加する必要があります。

## Windows版の実装について

Windows版のbuild_infoの動作は以下の通りです。

1. Flutter から BuildInfo.fromPlatform メソッドを呼び出す。
2. ビルド日時として [`IMAGE_NT_HEADERS64`][windows-1] 構造体を取得し [`IMAGE_FILE_HEADER`][windows-2] 構造体の TimeDateStamp の値を利用します。
3. インストール日時として実行ファイルの作成日時または実行ファイルが存在するディレクトリの作成日時のうち、より過去の日付をインストール日時として利用します。

各日時を取得できなかった場合、 null となります。

ビルド日時に利用する [`IMAGE_FILE_HEADER`][windows-2] 構造体の TimeDateStamp は DWORD 型のため 2106年2月7日06:28:15 UTC 以降にオーバーフローするため、2024年1月1日 00:00:00 UTC 以前のタイムスタンプを受け取った場合 0x100000000 を加算する処理を加えています。

```c
int64_t _tmp = inh.FileHeader.TimeDateStamp;
if (_tmp < 1704067200/* 2024-01-01 00:00:00 UTC */) {
    _tmp += 0x100000000;
}
```

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
[windows-1]: https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers64
[windows-2]: https://learn.microsoft.com/ja-jp/windows/win32/api/winnt/ns-winnt-image_file_header
