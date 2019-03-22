cmake_minimum_required(VERSION 3.0.2)
project(hello_cpp C CXX)

option(VERBOSE_MODE "Build on verbose mode..." ON)
option(BUILD_TEST "build test..." ON)

if (VERBOSE_MODE)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

if (BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()
add_subdirectory(src)
add_subdirectory(lib)
