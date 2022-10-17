#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<int> points = {
            3,
            2,
            1,
            5,
            6,
            4
    };
    Solution solution;
    ASSERT_THAT(solution.findKthLargest(points, 2), 5);
}

TEST(DEFAULT, test1) {
    vector<int> points = {
            3, 2, 3, 1, 2, 4, 5, 5, 6
    };
    Solution solution;
    ASSERT_THAT(solution.findKthLargest(points, 4), 4);
}
