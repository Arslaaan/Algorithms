#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, 0) {
    int k = 8;
    vector<vector<int>> points = {
            {1,  5,  9},
            {10, 11, 13},
            {12, 13, 15},
    };
    Solution solution;
    ASSERT_THAT(solution.kthSmallest(points, k), 13);
}

TEST(DEFAULT, 1) {
    int k = 1;
    vector<vector<int>> points = {
            {-5}
    };
    Solution solution;
    ASSERT_THAT(solution.kthSmallest(points, k), -5);
}

TEST(DEFAULT, 2) {
    int k = 2;
    vector<vector<int>> points = {
            {1, 2},
            {1, 3},
    };
    int expected = 1;

    Solution solution;
    ASSERT_THAT(solution.kthSmallest(points, k), expected);
}
