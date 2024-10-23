FILE(GLOB TESTS *.cc)

add_executable(test_matrix ${TESTS})
target_link_libraries(test_matrix s21_matrix_oop)
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(test_matrix GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(test_matrix)