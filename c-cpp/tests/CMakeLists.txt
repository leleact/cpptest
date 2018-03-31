#add_subdirectory(${GTEST_SOURCE_DIR} ${CMAKE_BINARY_DIR}/googletest)

add_test(NAME unittests COMMAND unittests)
add_test(NAME hello2 COMMAND hello2)
#add_test(NAME gtest COMMAND gunittest)
ADD_EXECUTABLE(unittests HelloWorldTests.cpp)
ADD_EXECUTABLE(hello2 HelloWorldTests2.cpp)
#ADD_EXECUTABLE(gunittest GTests.cpp GTestCase.cpp)
