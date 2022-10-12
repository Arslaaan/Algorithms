#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<vector<int>> points = {{1, 0}};
    Solution solution;
    ASSERT_THAT(solution.canFinish(2, points), true);
}

TEST(DEFAULT, test1) {
    vector<vector<int>> points = {
            {1, 0},
            {0, 1}
    };
    Solution solution;
    ASSERT_THAT(solution.canFinish(2, points), false);
}

TEST(DEFAULT, test4) {
    vector<vector<int>> points = {
            {0, 1},
    };
    Solution solution;
    ASSERT_THAT(solution.canFinish(2, points), true);
}

TEST(DEFAULT, test2) {
    vector<vector<int>> points = {
            {6,  10},
            {4,  10},
            {10, 1},
            {10, 8},
            {10, 9},
            {6,  7},
            {7,  8},
            {2,  7},
            {2,  9},
    };
    Solution solution;
    ASSERT_THAT(solution.canFinish(11, points), true);
}

TEST(DEFAULT, test3) {
    vector<vector<int>> points = {
            {6,  10},
            {4,  10},
            {10, 1},
            {10, 8},
            {10, 9},
            {6,  7},
            {7,  8},
            {2,  7},
            {2,  9},
            {11, 12},
    };
    Solution solution;
    ASSERT_THAT(solution.canFinish(13, points), false);
}