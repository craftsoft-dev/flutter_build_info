# build_info

This plugin retrieves build date and time and installation date and time.

## Getting Started

Add this to your package's `pubspec.yaml` file:

```yaml
dependencies:
  build_info: ^1.1.0
```

## Usage

Import BuildInfo.

```dart
import 'package:build_info/build_info.dart';
```

Call the `fromPlatform` method to get the information.

```dart
final buildInfoData = await BuildInfo.fromPlatform();
debugInfo('$buildInfoData');
```

## Platform support

| Platform                                            | Build date | Install date |
| --------------------------------------------------- | :--------: | :----------: |
| [Android](#about-implementation-of-android-version) |    YES     |     YES      |
| [iOS](#about-implementation-of-ios-version)         |    YES     |     YES      |
| [Linux](#about-implementation-of-linux-version)     |    YES     |      NO      |
| [macOS](#about-implementation-of-macos-version)     |    YES     |     YES      |
| [Web](#about-implementation-of-web-version)         |    YES     |      NO      |
| [Windows](#about-implementation-of-windows-version) |    YES     |     YES      |

### About implementation of Android version

The Android version of build_info works as follows.

1. When building, android/build.gradle included in this package adds a field called BUILDINFO_TIMESTAMP to the BuildConfig class and sets the build time in milliseconds.
2. Calling the BuildInfo.fromPlatform method from Flutter returns the value of BuildConfig.BUILDINFO_TIMESTAMP and the value of [`firstInstallTime`][android-1] obtained from PackageInfo.

If firstInstallTime cannot be obtained, the installation date and time will be null.


## About implementation of iOS version

The iOS version of build_info works as follows.

1. Call the BuildInfo.fromPlatform method from Flutter.
2. Use [`path(forResource:ofType:)`][apple-1] to get the last modification date and time of the bundled Info.plist file and use it as the build date and time.
3. Get the creation date and time of [Document Directory][apple-2] as the installation date and time.
4. Returns the value obtained in "2." and "3.".

If each date and time cannot be obtained, it will be null.


### About implementation of Linux version

The Linux version of build_info works as follows.

1. At build time, linux/CMakeLists.txt defines the BUILD_INFO_TIMESTAMP constant and sets the build time in milliseconds.
2. Call the BuildInfo.fromPlatform method from Flutter.
3. The value of the BUILD_INFO_TIMESTAMP constant is set as the build date and time.

In the Linux version, the installation date and time is always null.


### About implementation of macOS version

The macOS version of build_info works as follows.

1. Call the BuildInfo.fromPlatform method from Flutter.
2. Use [`path(forResource:ofType:)`][apple-1] to get the last modification date and time of the bundled _CodeSignature/CodeResources file and use it as the build date and time.
3. Get the bundle creation date and time using [`MDItemCreateWithURL`][apple-3] as the installation date and time.

If each date and time cannot be obtained, it will be null.


### About implementation of Web version

The Web version of build_info works as follows.

1. Call the BuildInfo.fromPlatform method from Flutter.
2. Request "version.json" as the build date and time using the HEAD or GET method and use the `Last-Modified` or `Date` response header value.
3. If the date and time cannot be obtained from "version.json", use the value of [`document.lastModified`][web-1].

If the date and time could not be obtained, it will be null.  
In the Web version, the installation date and time is always null.


### About implementation of Windows version

The Windows version of build_info works as follows.

1. Call the BuildInfo.fromPlatform method from Flutter.
2. Get the [`IMAGE_NT_HEADERS64`][windows-1] structure and use the TimeDateStamp value of the [`IMAGE_FILE_HEADER`][windows-2] structure as the build date and time.
3. The earlier date and time of the creation date and time of the executable file or the creation date and time of the directory where the executable file exists is used as the installation date and time.

If each date and time cannot be obtained, it will be null.

TimeDateStamp of the [`IMAGE_FILE_HEADER`][windows-2] structure used for build date and time is of DWORD type, so it will overflow after 2106/02/07 06:28:15 UTC, so if a timestamp before 2024/01/01 00:00:00 UTC is received, 0x100000000 will be added.(Date format yyyy/mm/dd)

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
