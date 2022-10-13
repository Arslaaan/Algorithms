#pragma once

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <limits>

using namespace std;

class Solution {

    class Node {
        int row;
        int col;
        int weight;
    public:
        Node(int r, int c) {
            row = r;
            col = c;
            weight = numeric_limits<int>::max();
        }

        bool operator>(const Node &other) const {
            return weight > other.weight;
        }

        int getWeight() const {
            return weight;
        }

        void setWeight(int w) {
            Node::weight = w;
        }

        int getRow() const {
            return row;
        }

        int getCol() const {
            return col;
        }
    };

    static bool edgeRelaxed(const Node &current,
                            const vector<vector<int>> &heights,
                            vector<vector<Node>> &nodes,
                            int neighbourRow,
                            int neighbourCol) {
        if (neighbourRow >= 0 && neighbourCol >= 0 && neighbourRow < heights.size() &&
            neighbourCol < heights.at(neighbourRow).size()) {
            int effort = max(
                    current.getWeight(),
                    abs(
                            heights[current.getRow()][current.getCol()] -
                            heights[neighbourRow][neighbourCol]
                    ));
            Node &neighbour = nodes[neighbourRow][neighbourCol];
            if (effort < neighbour.getWeight()) {
                neighbour.setWeight(effort);
                return true;
            }
        }
        return false;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        vector<vector<Node>> nodes;
        nodes.reserve(heights.size());
        for (int i = 0; i < heights.size(); ++i) {
            vector<Node> row;
            row.reserve(heights.at(i).size());
            for (int j = 0; j < heights.at(i).size(); ++j) {
                row.emplace_back(i, j);
            }
            nodes.push_back(row);
        }
        nodes[0][0].setWeight(0);

        priority_queue<Node, vector<Node>, greater<>> pqueue;
        pqueue.push(nodes[0][0]);

        while (!pqueue.empty()) {
            Node current = pqueue.top();
            pqueue.pop();

            int neighbourRow = current.getRow() - 1;
            int neighbourCol = current.getCol();
            if (edgeRelaxed(current, heights, nodes, neighbourRow, neighbourCol)) {
                pqueue.push(nodes[neighbourRow][neighbourCol]);
            }

            neighbourRow = current.getRow() + 1;
            neighbourCol = current.getCol();
            if (edgeRelaxed(current, heights, nodes, neighbourRow, neighbourCol)) {
                pqueue.push(nodes[neighbourRow][neighbourCol]);
            }

            neighbourRow = current.getRow();
            neighbourCol = current.getCol() - 1;
            if (edgeRelaxed(current, heights, nodes, neighbourRow, neighbourCol)) {
                pqueue.push(nodes[neighbourRow][neighbourCol]);
            }

            neighbourRow = current.getRow();
            neighbourCol = current.getCol() + 1;
            if (edgeRelaxed(current, heights, nodes, neighbourRow, neighbourCol)) {
                pqueue.push(nodes[neighbourRow][neighbourCol]);
            }
        }

        return nodes[heights.size() - 1][heights.back().size() - 1].getWeight();
    }
};
