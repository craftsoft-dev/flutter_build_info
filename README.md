# Add new platform

```console
% flutter create -t plugin --org dev.craftsoft build_info_PLATFORM
% cd build_info_PLATFORM
% flutter create -t plugin --platform PLATFORM --org dev.craftsoft --project-name buildinfo
```

or

```console
% flutter create -t plugin --org dev.craftsoft --platform PLATFORM build_info_PLATFORM
```


# Pigeon

```console
% cd build_info_PLATFORM
% flutter pub run pigeon --input pigeons/messages.dart
```