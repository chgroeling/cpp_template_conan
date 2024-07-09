
find_package(GTest REQUIRED COMPONENTS gtest gmock gtest_main gmock_main)


set(TEST_SOURCES
    test_basic.cpp
    sample_lib/test_sample_lib.cpp
    sample_lib/internal/internal_class_tests.cpp
)


add_executable(ptest ${TEST_SOURCES})
target_include_directories(ptest PRIVATE ../src)
target_link_libraries(ptest
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
    GTest::gmock_main
    sample_lib
)