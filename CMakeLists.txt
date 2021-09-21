cmake_minimum_required(VERSION 3.18)
project(Arcan_a C)

include(CheckSymbolExists)

set(CMAKE_C_STANDARD 99)

add_library(Arcan_a Sources/Arcana/arcana.c Sources/Arcana/include/arcana.h)


add_executable(Arcan_a_driver main.c)
target_link_libraries(Arcan_a_driver Arcan_a)

CHECK_SYMBOL_EXISTS(arc4random_uniform stdlib.h HAS_ARC4RANDOMU)
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("no arc4random")
    target_link_libraries(Arcan_a_driver bsd)
else()
    message("arc4random present")
endif ()