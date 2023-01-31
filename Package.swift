// swift-tools-version: 5.5
import PackageDescription

let package = Package(
  name: "hexfiend",
  platforms: [
    .macOS(.v10_13)
  ],
  products: [
    .library(name: "HexFiend", targets: ["HexFiend"])
  ],
  targets: [
    .target(
      name: "HexFiend",
      path: "framework/sources",
      exclude: [
        "HFPrivilegedHelperConnection.h",
        "HFPrivilegedHelperConnection.m",
        "HFTestRepresenter.h",
        "HFTestRepresenter.m",
        "BTree/BTree_Testing/BTree_Test.m"
      ],
      // sources: [],
      cSettings: [
        .define("HFUNIT_TESTS", to: "0"),
        .define("HF_NO_PRIVILEGED_FILE_OPERATIONS", to: "1"),
        // .headerSearchPath("include"),
        .headerSearchPath("BTree"),
        .unsafeFlags(["-w"])
      ]
    ),
    .testTarget(
      name: "HexFiendTests",
      dependencies: ["HexFiend"],
      path: "spm/tests"
    ),
    // .testTarget(
    //   name: "OGHexFiendTests",
    //   dependencies: ["HexFiend"],
    //   path: "framework/tests",
    //   cSettings: [
    //     .headerSearchPath("../sources/include"),
    //     .headerSearchPath("../sources/include/HexFiend")
    //   ]
    // )
  ]
)
