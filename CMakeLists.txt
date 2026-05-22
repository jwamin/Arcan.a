cmake_minimum_required(VERSION 3.18)
project(Arcan.a C)

include(CheckSymbolExists)

set(CMAKE_C_STANDARD 99)

option(ARCANA_STATIC "Produce a fully static portable executable (Linux only)" OFF)

add_subdirectory(Sources/Arcana)

add_executable(${PROJECT_NAME} main.c)
target_include_directories(${PROJECT_NAME} PRIVATE Sources/Arcana)
target_link_libraries(${PROJECT_NAME} arcan)

CHECK_SYMBOL_EXISTS(arc4random_uniform stdlib.h HAS_ARC4RANDOM)
set_property(GLOBAL PROPERTY HAS_ARC4RANDOM ${HAS_ARC4RANDOM})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    if (ARCANA_STATIC)
        message(WARNING "ARCANA_STATIC is not supported on macOS — Apple does not allow fully static binaries")
    endif()
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    if (NOT HAS_ARC4RANDOM)
        target_link_libraries(${PROJECT_NAME} bsd)
    endif()
    if (ARCANA_STATIC)
        target_link_options(${PROJECT_NAME} PRIVATE -static)
        message(STATUS "Static build enabled — output binary will have no runtime dependencies")
    endif()
endif()
