## How to run integration tests

1. Download chromedriver from the https://googlechromelabs.github.io/chrome-for-testing/ page.
2. Extract the downloaded chromedriver ZIP.
3. Run the chromedriver command with `chromedriver --port=4444`.
4. Move to the `example` directory and run the following Flutter command.

```sh
flutter -d chrome drive --driver=test_driver/integration_test.dart --target=integration_test/plugin_integration_test.dart
```
