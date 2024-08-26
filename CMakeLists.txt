cmake_minimum_required(VERSION 3.18)
project(Arcan.a C)

include(CheckSymbolExists)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Sources/Arcana)

add_executable(${PROJECT_NAME} main.c)
target_include_directories(${PROJECT_NAME} PRIVATE Sources/Arcana)
target_link_libraries(${PROJECT_NAME} arcan)

CHECK_SYMBOL_EXISTS(arc4random_uniform stdlib.h HAS_ARC4RANDOM)

message("hasarc4random:${HAS_ARC4RANDOM}")

set_property(GLOBAL PROPERTY HAS_ARC4RANDOM ${HAS_ARC4RANDOM}) 

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND NOT ${HAS_ARC4RANDOM})
    message("no arc4random")
    CHECK_SYMBOL_EXISTS(md5 bsd.h HAS_MD5)
    message("hasMD5:${HAS_MD5} hasarc4random:${HAS_ARC4RANDOM}")
    target_link_libraries(${PROJECT_NAME} bsd ssl)
else()
    message("arc4random present")
endif ()
