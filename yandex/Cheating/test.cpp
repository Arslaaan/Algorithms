#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "solution.cpp"

using namespace testing;

TEST(DEFAULT, test1) {
    solution(1);
}

int main(int argc, char** argv) {
    // ::testing::GTEST_FLAG(filter) = "*test5*";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
