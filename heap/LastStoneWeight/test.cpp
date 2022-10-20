#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<int> points = {
            2, 7, 4, 1, 8, 1
    };
    Solution solution;
    ASSERT_THAT(solution.lastStoneWeight(points), 1);
}

TEST(DEFAULT, test1) {
    vector<int> points = {
            1
    };
    Solution solution;
    ASSERT_THAT(solution.lastStoneWeight(points), 1);
}
