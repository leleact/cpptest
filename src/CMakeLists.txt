add_executable(main main.cpp)
link_directories(${CMAKE_BINARY_DIR}/lib)
target_link_libraries(main add spdlog::spdlog_header_only)
