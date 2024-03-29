// swift-tools-version:5.0
import PackageDescription

var targetIncludes: [Target] = []
var dependencies: [Target.Dependency] = []

#if os(Linux)
targetIncludes += [
    .systemLibrary(name:"lbsd", path:"./Sources/linux-lbsd", pkgConfig:"libbsd")
]
dependencies += [
    "lbsd"
]
#endif

let package = Package(
        name: "Arcana",
        products: [
            // Products define the executables and libraries a package produces, and make them visible to other packages.
            .executable(
                    name: "ArcanaDriver",
                    targets:["ArcanaDriver"]
            ),
            .library(
                    name: "Arcana",
                    targets: ["Arcana"]
            )
        ],
        dependencies: [
            // Dependencies declare other packages that this package depends on.
            // .package(url: /* package url */, from: "1.0.0"),
        ],
        targets: targetIncludes + [
            // Targets are the basic building blocks of a package. A target can define a module or a test suite.
            // Targets can depend on other targets in this package, and on products in packages this package depends on.
            .target(
                    name: "Arcana",
                    dependencies: [ ] + dependencies,
                    publicHeadersPath: "./"
            ),
            .target(
                    name: "ArcanaDriver",
                    dependencies: [
                        "Arcana"
                    ]),
            .testTarget(
                    name: "ArcanaTests",
                    dependencies: [
                        "Arcana"
                    ]),
        ]
)
