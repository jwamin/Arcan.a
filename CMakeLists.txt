cmake_minimum_required(VERSION 3.19)
project(Arcan_a C)

set(CMAKE_C_STANDARD 99)

add_library(Arcan_a arcana.c arcana.h)


add_executable(Arcan_a_driver main.c)
target_link_libraries(Arcan_a_driver Arcan_a)
