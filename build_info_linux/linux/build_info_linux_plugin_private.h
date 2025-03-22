// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <flutter_linux/flutter_linux.h>

#include "include/build_info_linux/build_info_linux_plugin.h"
#include "messages.g.h"

// This file exposes some plugin internals for unit testing. See
// https://github.com/flutter/flutter/issues/88724 for current limitations
// in the unit-testable API.

// Handles the fromPlatform method call.
// FlMethodResponse *from_platform();
BuildInfoLinuxBuildInfoHostApiFromPlatformResponse* handle_from_platform(gpointer user_data);
