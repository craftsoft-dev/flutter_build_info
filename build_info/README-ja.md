# build_info

Flutter アプリのビルドした日時とインストールした日時を取得するプラグインです。

## 始め方

`pubspec.yaml` ファイルに以下を追加します。

```yaml
dependencies:
  build_info: ^1.0.0
```

## 使い方

BuildInfo をインポートします。

```dart
import 'package:build_info/build_info.dart';
```

情報を取得するには `fromPlatform` メソッドを呼び出します。

```dart
final buildInfoData = await BuildInfo.fromPlatform();
debugPrint('$buildInfoData');
```

## プラットフォーム対応

| Platform                            | Build date | Install date |
| ----------------------------------- | :--------: | :----------: |
| [Android](#Android版の実装について) |    YES     |     YES      |
| [iOS](#iOS版の実装について)         |    YES     |     YES      |
| [Linux](#Linux版の実装について)     |    YES     |      NO      |
| [macOS](#macOS版の実装について)     |    YES     |     YES      |
| [Web](#Web版の実装について)         |    YES     |      NO      |
| [Windows](#Windows版の実装について) |    YES     |     YES      |

### Android版の実装について

Android版のbuild_infoの動作は以下の通りです。

1. ビルド時にこのパッケージに含まれる android/build.gradle により BuildConfig クラスに BUILDINFO_TIMESTAMP というフィールドが追加されビルド時の時刻がミリ秒単位で設定されます。
2. Flutter から BuildInfo.fromPlatform メソッドを呼び出すと BuildConfig.BUILDINFO_TIMESTAMP の値および PackageInfo から取得した [`firstInstallTime`][android-1] の値を返します。

firstInstallTime が取得できなかった場合、インストール日時は null となります。


### iOS版の実装について

iOS版のbuild_infoの動作は以下の通りです。

1. Flutter から BuildInfo.fromPlatform メソッドを呼び出す。
2. ビルド日時として[`path(forResource:ofType:)`][apple-1]を利用してバンドルされている Info.plist ファイルの最終更新日時を取得。
3. インストール日時として[ドキュメントディレクトリ][apple-2]の作成日時を取得。
4. 上記「2.」「3.」で取得した値を返す。

各日時を取得できなかった場合、 null となります。



### Linux版の実装について

Linux版のbuild_infoの動作は以下の通りです。

1. ビルド時に linux/CMakeLists.txt により BUILD_INFO_TIMESTAMP 定数が定義されビルド時のミリ秒が設定されます。
2. Flutter から BuildInfo.fromPlatform メソッドを呼び出す。
3. ビルド日時として BUILD_INFO_TIMESTAMP 定数の値が設定されます。

Linux版ではインストール日時は常に null となります。


### macOS版の実装について

macOS版のbuild_infoの動作は以下の通りです。

1. Flutter から BuildInfo.fromPlatform メソッドを呼び出す。
2. ビルド日時として[`path(forResource:ofType:)`][apple-1]を利用してバンドルされている _CodeSignature/CodeResources ファイルの最終更新日時を取得。
3. インストール日時として[`MDItemCreateWithURL`][apple-3]を利用してバンドルの作成日時を取得。

各日時を取得できなかった場合、 null となります。


### Web版の実装について

Web版のbuild_infoの動作は以下の通りです。

1. Flutter から BuildInfo.fromPlatform メソッドを呼び出す。
2. ビルド日時として "version.json" をHEADまたはGETメソッドでリクエストし `Last-Modified` または `Date` レスポンスヘッダの値を利用します。
3. "version.json" から日時を取得できない場合 [`document.lastModified`][web-1] の値を利用します。て利用します。

日時を取得できなかった場合、 null となります。  
Web版ではインストール日時は常に null となります。


### Windows版の実装について

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


[android-1]: https://developer.android.com/reference/android/content/pm/PackageInfo#firstInstallTime
[apple-1]: https://developer.apple.com/documentation/foundation/bundle/1410989-path
[apple-2]: https://developer.apple.com/documentation/foundation/filemanager/searchpathdirectory/documentdirectory
[apple-3]: https://developer.apple.com/documentation/coreservices/1427034-mditemcreatewithurl
[web-1]: https://developer.mozilla.org/docs/Web/API/Document/lastModified
[windows-1]: https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers64
[windows-2]: https://learn.microsoft.com/ja-jp/windows/win32/api/winnt/ns-winnt-image_file_header
