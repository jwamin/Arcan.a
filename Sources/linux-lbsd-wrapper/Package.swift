// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "linux-lbsd-wrapper",
        pkgConfig: "libbsd",
        products: [
            .library(name: "linux-lbsd-wrapper", targets: ["linux-lbsd-wrapper"]),
        ],
        targets: [
            .systemLibrary(name:"linux-lbsd-wrapper",  pkgConfig: "libbsd"),
        ]
)
