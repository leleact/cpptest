add_executable(crtp_test crtp_test.cpp)
target_link_libraries(crtp_test gtest_main)
add_test(NAME crtp_test COMMAND crtp_test)
