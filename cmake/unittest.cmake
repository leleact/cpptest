function(cpp_add_test)
    if (ARGC LESS 2)
        message(FATAL_ERROR "No arguments supplied to cpp_add_test()")
    endif()

    set(options "")
    set(oneValueArgs TEST_NAME SOURCE_FILE)
    set(multiValueArgs "")
    cmake_parse_arguments(cpp_add_test "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    message(STATUS "cpp_add_test_TEST_NAME: ${cpp_add_test_TEST_NAME}")
    message(STATUS "cpp_add_test_SOURCE_FILE: ${cpp_add_test_SOURCE_FILE}")

    add_executable(${cpp_add_test_TEST_NAME} ${cpp_add_test_SOURCE_FILE})
    set_property(TARGET ${cpp_add_test_TEST_NAME} PROPERTY CXX_STANDARD 14)
    target_link_libraries(${cpp_add_test_TEST_NAME} gtest_main)
    add_test(NAME ${cpp_add_test_TEST_NAME} COMMAND ${cpp_add_test_TEST_NAME})
endfunction()

