# build_info_windows

The Linux implementation of [`build_info`][1].

## Usage

This package is [endorsed][2], which means you can simply use `build_info` normally. This package will be automatically included in your app when you do, so you do not need to add it to your `pubspec.yaml`.

However, if you `import` this package to use any of its APIs directly, you should add it to your `pubspec.yaml` as usual.

## About implementation of Windows version

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

[1]: https://pub.dev/packages/build_info
[2]: https://flutter.dev/docs/development/packages-and-plugins/developing-packages#endorsed-federated-plugin
[windows-1]: https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers64
[windows-2]: https://learn.microsoft.com/ja-jp/windows/win32/api/winnt/ns-winnt-image_file_header
