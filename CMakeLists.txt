cmake_minimum_required(VERSION 3.0.2)
project(hello_cpp C CXX)

option(VERBOSE_MODE "Build on verbose mode..." ON)
option(BUILD_TEST "Build test..." ON)

if (VERBOSE_MODE)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(spdlog)

if (BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()

add_subdirectory(src)
add_subdirectory(lib)
