#pragma once

#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
    class Graph {
        map<pair<int, int>, vector<pair<int, int>>> data;
        vector<pair<int, int>> startingVertices;
        size_t size;

        static void checkAndAddNeighbour(
                vector<pair<int, int>> &neighbours,
                const vector<vector<int>> &grid,
                int i,
                int j) {
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid.at(0).size()) {
                if (grid[i][j] == 1) {
                    neighbours.emplace_back(i, j);
                }
            }
        }

    public:
        Graph(const vector<vector<int>> &grid) {
            size = 0;
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid.at(0).size(); ++j) {
                    vector<pair<int, int>> &neighbours = data[make_pair(i, j)];
                    int value = grid[i][j];
                    if (value == 2) {
                        startingVertices.emplace_back(i, j);
                    }
                    if (value > 0) {
                        size++;
                        checkAndAddNeighbour(neighbours, grid, i - 1, j);
                        checkAndAddNeighbour(neighbours, grid, i + 1, j);
                        checkAndAddNeighbour(neighbours, grid, i, j - 1);
                        checkAndAddNeighbour(neighbours, grid, i, j + 1);
                    }
                }
            }
        }

        size_t getSize() const {
            return size;
        }

        const vector<pair<int, int>> &getNeighbours(const pair<int, int> &p) const {
            return data.at(p);
        }

        void updateQueueByStartingPoints(queue<pair<int, int>> &queue) {
            for (pair<int, int> &p: startingVertices) {
                queue.push(p); // todo check
            }
        }
    };

    set<pair<int, int>> visited;

public:
    int orangesRotting(vector<vector<int>> &grid) {
        Graph graph(grid);
        queue<pair<int, int>> queue;

        graph.updateQueueByStartingPoints(queue);
        if (graph.getSize() == 0) {
            return 0;
        }

        int result = -1;
        while (!queue.empty()) {
            bool corruptedAtLeastOne = false;
            size_t currentSize = queue.size();
            for (size_t i = 0; i < currentSize; ++i) {
                pair<int, int> p = move(queue.front());
                queue.pop();

                auto insertInfo = visited.insert(p);
                if (insertInfo.second) {
                    corruptedAtLeastOne = true;
                    for (const auto &e: graph.getNeighbours(p)) {
                        if (visited.count(e) == 0) {
                            queue.push(e);
                        }
                    }
                }
            }
            if (corruptedAtLeastOne) {
                result++;
            }
        }
        if (visited.size() != graph.getSize()) {
            return -1;
        }
        return result;
    }
};
