cmake_minimum_required(VERSION 3.0.2)

# TODO 增加cmake的详细显示
if(CPP_TEST_VERBOSE)
    message(STATUS "CPP TEST Configuring...")
endif()

# CMake policies
cmake_policy(SET CMP0022 NEW)

if(POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif()

# Project
project(cpptest C CXX)

# Options
#TODO 增加选择编译测试程序
option(CPP_TEST_BUILD_TESTS "Build tests" ON)

#TODO 增加编译动态库的选项
if (BUILD_SHARED_LIBS)
    set(CPP_TEST_BUILD_SHARED_LIBS_DEFAULT ON)
else (BUILD_SHARED_LIBS)
    set(CPP_TEST_BUILD_SHARED_LIBS_DEFAULT OFF)
endif (BUILD_SHARED_LIBS)

set(CMAKE_VERBOSE_MAKEFILE ON)

enable_testing()

add_subdirectory(tests)
