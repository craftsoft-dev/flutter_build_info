// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import Flutter
import UIKit

public class BuildInfoPlugin: NSObject, FlutterPlugin, BuildInfoHostApi {
    public static func register(with registrar: FlutterPluginRegistrar) {
        let plugin = BuildInfoPlugin()
        BuildInfoHostApiSetup.setUp(binaryMessenger: registrar.messenger(), api: plugin)
        registrar.publish(plugin)
    }
    
    func fromPlatform() -> BuildInfoDataPigeon{
        let fileManager = FileManager.default
        
        var buildDateInt: Int64?
        let bundle = Bundle.main
        if let path = bundle.path(forResource: "Info.plist", ofType: nil) {
            do {
                let attr = try FileManager.default.attributesOfItem(atPath: path)
                let modificationDate = attr[.modificationDate] as? Date
                
                buildDateInt = Int64((modificationDate?.timeIntervalSince1970 ?? 0.0) * 1000.0)
            } catch {
            }
        }
        
        // Document folder creation date
        var installDateInt: Int64?
        if let urlDocument = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).last {
            do {
                let attr = try fileManager.attributesOfItem(atPath: urlDocument.path)
                let creationDate = attr[.creationDate] as? Date
                
                installDateInt = Int64((creationDate?.timeIntervalSince1970 ?? 0.0) * 1000.0)
            } catch {
            }
        }
        
        return BuildInfoDataPigeon(
            buildDate: buildDateInt,
            installDate: installDateInt
        )
    }
}
