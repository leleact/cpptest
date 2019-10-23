cmake_minimum_required(VERSION 3.0.2)
project(cpp_test C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(third_party/spdlog/include)
include_directories(third_party/sqlite3/src)
enable_testing()
add_subdirectory(test)
add_subdirectory(third_party/googletest)
#add_subdirectory(third_party/spdlog)
add_subdirectory(third_party/sqlite3)


add_subdirectory(src)
add_subdirectory(lib)
