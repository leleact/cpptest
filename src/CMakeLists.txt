add_executable(main main.cpp)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)
TARGET_LINK_LIBRARIES(main add)
