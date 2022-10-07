#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<vector<int>> points = {{1, 2, 2},
                                  {3, 8, 2},
                                  {5, 3, 5}
    };
    Solution solution;
    ASSERT_THAT(solution.minimumEffortPath(points), 2);
}

TEST(DEFAULT, test1) {
    vector<vector<int>> points = {{1, 2, 3},
                                  {3, 8, 4},
                                  {5, 3, 5}
    };
    Solution solution;
    ASSERT_THAT(solution.minimumEffortPath(points), 1);
}

TEST(DEFAULT, 2) {
    vector<vector<int>> points = {{1, 2, 1, 1, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 2, 1, 2, 1},
                                  {1, 1, 1, 2, 1}
    };
    Solution solution;
    ASSERT_THAT(solution.minimumEffortPath(points), 0);
}