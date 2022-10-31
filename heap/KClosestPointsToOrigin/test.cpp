#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, 0) {
    vector<vector<int>> points = {
            {1,  3},
            {-2, 2},
    };
    Solution solution;
    ASSERT_THAT(solution.kClosest(points, 1), UnorderedElementsAre(ElementsAre(-2, 2)));
}

TEST(DEFAULT, 1) {
    vector<vector<int>> points = {
            {3,  3},
            {5,  -1},
            {-2, 4},
    };
    Solution solution;
    ASSERT_THAT(solution.kClosest(points, 2), UnorderedElementsAre(ElementsAre(3, 3), ElementsAre(-2, 4)));
}

TEST(DEFAULT, 2) {
    vector<vector<int>> points = {
            {-5, 4},
            {-6, -5},
            {4,  6}
    };
    Solution solution;
    ASSERT_THAT(solution.kClosest(points, 2), UnorderedElementsAre(ElementsAre(-5, 4), ElementsAre(4, 6)));
}
