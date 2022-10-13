#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test0) {
    set<pair<int, int>> s;
    pair<int, int> p = make_pair(1, 1);

    s.insert(p);

    ASSERT_TRUE(s.count(make_pair(1, 1)) == 1);
    ASSERT_TRUE(s.count(p) == 1);
}

TEST(DEFAULT, test1) {
    vector<vector<int>> grid;
    grid.push_back({2, 1, 1});
    grid.push_back({1, 1, 0});
    grid.push_back({0, 1, 1});

    Solution solution;
    ASSERT_THAT(solution.orangesRotting(grid), 4);
}

TEST(DEFAULT, test2) {
    vector<vector<int>> grid;
    grid.push_back({2, 1, 1});
    grid.push_back({0, 1, 1});
    grid.push_back({1, 0, 1});

    Solution solution;
    ASSERT_THAT(solution.orangesRotting(grid), -1);
}

TEST(DEFAULT, test3) {
    vector<vector<int>> grid;
    grid.push_back({0, 2});

    Solution solution;
    ASSERT_THAT(solution.orangesRotting(grid), 0);
}

TEST(DEFAULT, test4) {
    vector<vector<int>> grid;
    grid.push_back({0});

    Solution solution;
    ASSERT_THAT(solution.orangesRotting(grid), 0);
}

TEST(DEFAULT, test5) {
    vector<vector<int>> grid;
    grid.push_back({0, 2, 2});

    Solution solution;
    ASSERT_THAT(solution.orangesRotting(grid), 0);
}

TEST(DEFAULT, test6) {
    vector<vector<int>> grid;
    grid.push_back({1});

    Solution solution;
    ASSERT_THAT(solution.orangesRotting(grid), -1);
}

TEST(DEFAULT, test7) {
    vector<vector<int>> grid;
    grid.push_back({2});

    Solution solution;
    ASSERT_THAT(solution.orangesRotting(grid), 0);
}

TEST(DEFAULT, test8) {
    vector<vector<int>> grid;
    grid.push_back({2, 2});
    grid.push_back({1, 1});
    grid.push_back({0, 0});
    grid.push_back({2, 0});

    Solution solution;
    ASSERT_THAT(solution.orangesRotting(grid), 1);
}