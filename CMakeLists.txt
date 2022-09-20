cmake_minimum_required(VERSION 3.16)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Algorithms
        NetworkDelayTime/solution.cpp
        )

enable_testing()

add_executable(
        Tests
        NetworkDelayTime/test.cpp
)

target_link_libraries(
        Tests
        GTest::gtest_main
        GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(Tests)

