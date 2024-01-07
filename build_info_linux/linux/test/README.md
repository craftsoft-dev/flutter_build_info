## How to run linux tests

To run the test, go to the plugin's `example` directory and run the following command:

```sh
% cd {PLUGIN_ROOT}/example
% flutter build linux --debug
% ./build/linux/{ARCH}/debug/plugins/build_info_linux/build_info_linux_test
```

See: [Testing plugins | Flutter ( https://docs.flutter.dev/testing/testing-plugins )](https://docs.flutter.dev/testing/testing-plugins)