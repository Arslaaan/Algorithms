#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<int> points = {
            4, 5, 8, 2
    };
    KthLargest solution(3, points);
    ASSERT_THAT(solution.add(3), 4);
    ASSERT_THAT(solution.add(5), 5);
    ASSERT_THAT(solution.add(10), 5);
    ASSERT_THAT(solution.add(9), 8);
    ASSERT_THAT(solution.add(4), 8);
}