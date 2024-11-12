enable_testing()

add_subdirectory(googletest)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)

set(TEST_SOURCE
    test_main.cpp
    test_quadEq.cpp
)

add_executable(QuadEq_Tests
    ${TEST_SOURCE}
)

target_link_libraries(QuadEq_Tests LINK_PUBLIC
    GTest::gtest_main
    QuadEqlib
)
