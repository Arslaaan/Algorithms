#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, 0) {
    vector<vector<int>> points = {
            {1, 1, 0, 0, 0},
            {1, 1, 1, 1, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 1, 1, 1},
    };
    Solution solution;
    ASSERT_THAT(solution.kWeakestRowsInMatrix(points, 3), ElementsAre(2, 0, 3));
}

TEST(DEFAULT, 1) {
    vector<vector<int>> points = {
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0},

    };
    Solution solution;
    ASSERT_THAT(solution.kWeakestRowsInMatrix(points, 2), ElementsAre(0, 2));
}
