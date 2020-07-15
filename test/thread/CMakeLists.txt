unset(SOURCE_FILE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILE)
cpp_add_test(TEST_NAME thread_test SOURCE_FILE ${SOURCE_FILE})