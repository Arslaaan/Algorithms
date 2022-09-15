#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<vector<int>> points = {{0, 0},
                                  {2, 2},
                                  {3, 10},
                                  {5, 2},
                                  {7, 0}};
    Solution solution;
    ASSERT_THAT(solution.minCostConnectPoints(points), 20);
}

TEST(DEFAULT, test1) {
    vector<vector<int>> points = {{3,  12},
                                  {-2, 5},
                                  {-4, 1}};
    Solution solution;
    ASSERT_THAT(solution.minCostConnectPoints(points), 18);
}

TEST(DEFAULT, test2) {
    vector<vector<int>> points = {{0, 0}};
    Solution solution;
    ASSERT_THAT(solution.minCostConnectPoints(points), 0);
}

TEST(DEFAULT, test3) {
    vector<vector<int>> points = {{0, 0},
                                  {1, 1}};
    Solution solution;
    ASSERT_THAT(solution.minCostConnectPoints(points), 2);
}

TEST(DEFAULT, test4) {
    vector<vector<int>> points = {{2,   -3},
                                  {-17, -8},
                                  {13,  8},
                                  {-17, -15}};
    Solution solution;
    ASSERT_THAT(solution.minCostConnectPoints(points), 53);
}