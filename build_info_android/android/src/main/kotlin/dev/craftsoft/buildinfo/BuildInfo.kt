// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

package dev.craftsoft.buildinfo

import android.app.Activity
import android.content.pm.PackageManager

class BuildInfo: BuildInfoHostApi {
    private var activity: Activity? = null

    fun setActivity(activity: Activity?) {
        this.activity = activity
    }

    override fun fromPlatform(): BuildInfoDataPigeon {
        val buildDateLong = BuildConfig.BUILDINFO_TIMESTAMP
        var installDateLong: Long? = null

        if (activity != null) {
            val packageName = activity!!.packageName

            val pm: PackageManager? = activity?.packageManager

            val pi = pm?.getPackageInfo(packageName, PackageManager.GET_ACTIVITIES)
            installDateLong = pi?.firstInstallTime
        }

        return BuildInfoDataPigeon(buildDateLong, installDateLong)
    }
}
