enable_testing()

add_executable(
    AllTests
    test_main.cpp
    test_HashTable.cpp
)
target_link_libraries(
    AllTests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(AllTests)