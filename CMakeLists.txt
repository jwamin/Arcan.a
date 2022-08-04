cmake_minimum_required(VERSION 3.18)
project(Arcana_drive_program C)

include(CheckSymbolExists)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Sources/Arcana)

add_executable(${PROJECT_NAME} main.c)
target_include_directories(${PROJECT_NAME} PUBLIC Sources/Arcana)
target_link_directories(${PROJECT_NAME} PRIVATE Sources/Arcana)
target_link_libraries(${PROJECT_NAME} arcan)

CHECK_SYMBOL_EXISTS(arc4random_uniform stdlib.h HAS_ARC4RANDOM)
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("no arc4random")
    target_link_libraries(${PROJECT_NAME} bsd)
else()
    message("arc4random present")
endif ()