add_library(add SHARED add.cpp)
target_include_directories(add PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>)
