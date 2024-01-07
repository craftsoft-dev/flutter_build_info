# build_info_android

[`build_info`][1]のAndroid実装です。

## 使い方

このパッケージは承認されていて、通常は単に `build_info` を使用するだけです。このパッケージはアプリに自動的に組み込まれるため `pubspec.yaml` に追加する必要はありません。

ただし、このパッケージを `import` してAPIを直接利用する場合は `pubspec.yaml` に追加する必要があります。

## Android版の実装について

Android版のbuild_infoの動作は以下の通りです。

1. ビルド時にこのパッケージに含まれる android/build.gradle により BuildConfig クラスに BUILDINFO_TIMESTAMP というフィールドが追加されビルド時の時刻がミリ秒単位で設定されます。
2. Flutter から BuildInfo.fromPlatform メソッドを呼び出すと BuildConfig.BUILDINFO_TIMESTAMP の値および PackageInfo から取得した [`firstInstallTime`][android-1] の値を返します。

firstInstallTime が取得できなかった場合、インストール日時は null となります。


[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
[android-1]: https://developer.android.com/reference/android/content/pm/PackageInfo#firstInstallTime
