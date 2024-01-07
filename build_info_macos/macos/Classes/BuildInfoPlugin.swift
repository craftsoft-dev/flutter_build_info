// Copyright 2024 Craftsoft LLC. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

import Cocoa
import FlutterMacOS

public class BuildInfoPlugin: NSObject, FlutterPlugin, BuildInfoHostApi {
    public static func register(with registrar: FlutterPluginRegistrar) {
        let plugin = BuildInfoPlugin()
        BuildInfoHostApiSetup.setUp(binaryMessenger: registrar.messenger, api: plugin)
    }
    
    func fromPlatform() -> BuildInfoDataPigeon{
        let fileManager = FileManager.default
        
        var buildDateInt: Int64?
        let bundle = Bundle.main
        if let path = bundle.path(forResource: "../_CodeSignature/CodeResources", ofType: nil) {
            do {
                let attr = try fileManager.attributesOfItem(atPath: path)
                let modificationDate = attr[.modificationDate] as? Date
                
                buildDateInt = Int64((modificationDate?.timeIntervalSince1970 ?? 0.0) * 1000.0)
            } catch {
            }
        }
        
        // app date added
        var installDateInt: Int64?
        let bundlePath = bundle.bundlePath
        let urlBundle = URL.init(fileURLWithPath: bundlePath)
        if let itemRef = MDItemCreateWithURL(kCFAllocatorDefault, urlBundle as CFURL) {
            if let typeRef = MDItemCopyAttribute(itemRef, kMDItemDateAdded) {
                if (CFGetTypeID(typeRef) == CFDateGetTypeID()) {
                    let dateAdded = typeRef as? Date
                    installDateInt = Int64((dateAdded?.timeIntervalSince1970 ?? 0.0) * 1000.0)
                }
            }
        }
        
        return BuildInfoDataPigeon(
            buildDate: buildDateInt,
            installDate: installDateInt
        )
    }
}
