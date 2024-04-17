#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<vector<int>> points = {{0, 1, 100},
                                  {1, 2, 100},
                                  {2, 0, 100},
                                  {1, 3, 600},
                                  {2, 3, 200},
    };
    Solution solution;
    ASSERT_THAT(solution.findCheapestPrice(4, points, 0, 3, 1), 700);
}

TEST(DEFAULT, test1) {
    vector<vector<int>> points = {{0, 1, 100},
                                  {1, 2, 100},
                                  {0, 2, 500},
    };
    Solution solution;
    ASSERT_THAT(solution.findCheapestPrice(3, points, 0, 2, 1), 200);
}

TEST(DEFAULT, test2) {
    vector<vector<int>> points = {{0, 1, 100},
                                  {1, 2, 100},
                                  {0, 2, 500},
    };
    Solution solution;
    ASSERT_THAT(solution.findCheapestPrice(3, points, 0, 2, 0), 500);
}