#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    vector<int> points = {
            1, 1, 1, 2, 2, 3
    };
    Solution solution;
    ASSERT_THAT(solution.topKFrequent(points, 2), UnorderedElementsAre(1, 2)); // порядок не важен в этой задаче
}

TEST(DEFAULT, test1) {
    vector<int> points = {
            1
    };
    Solution solution;
    ASSERT_THAT(solution.topKFrequent(points, 1), UnorderedElementsAre(1));
}

TEST(DEFAULT, test2) {
    vector<int> points = {
            4, 1, -1, 2, -1, 2, 3
    };
    Solution solution;
    ASSERT_THAT(solution.topKFrequent(points, 2), UnorderedElementsAre(-1, 2));
}

TEST(DEFAULT, test3) {
    vector<int> points = {
            5, 2, 5, 3, 5, 3, 1, 1, 3
    };
    Solution solution;
    ASSERT_THAT(solution.topKFrequent(points, 2), UnorderedElementsAre(3, 5));
}
