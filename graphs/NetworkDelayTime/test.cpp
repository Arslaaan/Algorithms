#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<vector<int>> points = {{2, 1, 1},
                                  {2, 3, 1},
                                  {3, 4, 1},
    };
    Solution solution;
    ASSERT_THAT(solution.networkDelayTime(points, 4, 2), 2);
}

TEST(DEFAULT, test1) {
    vector<vector<int>> points = {{1, 2, 1},
    };
    Solution solution;
    ASSERT_THAT(solution.networkDelayTime(points, 2, 1), 1);
}

TEST(DEFAULT, test2) {
    vector<vector<int>> points = {{1, 2, 1},
    };
    Solution solution;
    ASSERT_THAT(solution.networkDelayTime(points, 2, 2), -1);
}

TEST(DEFAULT, test3) {
    vector<vector<int>> points = {
            {1, 2, 1},
            {2, 3, 5},
            {2, 4, 1},
            {4, 5, 1},
            {5, 7, 1},
            {1, 6, 6},
            {6, 7, 5},
    };
    Solution solution;
    ASSERT_THAT(solution.networkDelayTime(points, 7, 1), 6);
}

TEST(DEFAULT, test4) {
    vector<vector<int>> points = {
            {1, 2, 50},
            {2, 3, 1},
            {3, 4, 1},
            {1, 5, 45},
            {5, 4, 8},
    };
    Solution solution;
    ASSERT_THAT(solution.networkDelayTime(points, 5, 1), 52);
}

TEST(DEFAULT, test5) {
    vector<vector<int>> points = {
            {3, 5, 78},
            {2, 1, 1},
            {1, 3, 0},
            {4, 3, 59},
            {5, 3, 85},
            {5, 2, 22},
            {2, 4, 23},
            {1, 4, 43},
            {4, 5, 75},
            {5, 1, 15},
            {1, 5, 91},
            {4, 1, 16},
            {3, 2, 98},
            {3, 4, 22},
            {5, 4, 31},
            {1, 2, 0},
            {2, 5, 4},
            {4, 2, 51},
            {3, 1, 36},
            {2, 3, 59}
    };
    Solution solution;
    ASSERT_THAT(solution.networkDelayTime(points, 5, 5), 31);
}

TEST(DEFAULT, test6) {
    vector<vector<int>> points = {
            {1, 2, 1},
            {2, 3, 7},
            {1, 3, 4},
            {2, 1, 2}
    };
    Solution solution;
    ASSERT_THAT(solution.networkDelayTime(points, 4, 1), -1);
}
