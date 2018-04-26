cmake_minimum_required(VERSION 3.0.2)

# CMake policies
cmake_policy(SET CMP0022 NEW)

if(POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif()

# Project
project(cpptest C CXX)

# Options
option(CPP_TEST_BUILD_TESTS "Build tests" ON)
option(CPP_TEST_VERBOSE "Build on verbose mode" ON)

if(CPP_TEST_VERBOSE)
    message(STATUS "CPP TEST build print out verbose...")
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

if (CPP_TEST_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()
