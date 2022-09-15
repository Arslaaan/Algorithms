#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, test1) {
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node2 = new Node(2);
    Node *node4 = new Node(4);
    Node *node3 = new Node(3, {node5, node6});
    Node *node1 = new Node(1, {node2, node3, node4});

    Solution1 solution;
    ASSERT_THAT(solution.levelOrder(node1), ElementsAre(ElementsAre(1), ElementsAre(2, 3, 4), ElementsAre(5, 6)));
}

TEST(DEFAULT, test2) {
    Node *node2 = new Node(2);
    Node *node13 = new Node(13);
    Node *node10 = new Node(10);
    Node *node9 = new Node(9, {node13});
    Node *node5 = new Node(5, {node9, node10});

    Node *node12 = new Node(12);
    Node *node8 = new Node(8, {node12});
    Node *node4 = new Node(4, {node8});

    Node *node6 = new Node(6);
    Node *node14 = new Node(14);
    Node *node11 = new Node(11, {node14});
    Node *node7 = new Node(7, {node11});

    Node *node3 = new Node(3, {node6, node7});
    Node *node1 = new Node(1, {node2, node3, node4, node5});

    Solution1 solution;
    ASSERT_THAT(solution.levelOrder(node1), ElementsAre(
            ElementsAre(1),
            ElementsAre(2, 3, 4, 5),
            ElementsAre(6, 7, 8, 9, 10),
            ElementsAre(11, 12, 13),
            ElementsAre(14)
    ));
}

TEST(SMALLTREE, test1) {
    Node *node2 = new Node(2);
    Node *node1 = new Node(1, {node2});

    Solution1 solution;
    ASSERT_THAT(solution.levelOrder(node1), ElementsAre(
            ElementsAre(1),
            ElementsAre(2)
    ));
}

TEST(SMALLTREE, test2) {
    Solution1 solution;
    ASSERT_THAT(solution.levelOrder(nullptr), ElementsAre(
    ));
}