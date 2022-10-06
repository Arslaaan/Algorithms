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

    struct Cost {
        int weight;
        int pathLength;

        Cost() {
            weight = numeric_limits<int>::max();
            pathLength = numeric_limits<int>::max();
        }

        Cost(int weight_, int vertices_) {
            weight = weight_;
            pathLength = vertices_;
        }
    };

    struct Node {
        int number;
        Cost cost;

        explicit Node(int i) {
            number = i;
            cost = Cost();
        }

        explicit Node(int i, int w, int length) {
            number = i;
            cost = Cost(w, length);
        }

        bool operator>(const Node &other) const {
            if (cost.weight == other.cost.weight) {
                return cost.pathLength > other.cost.pathLength;
            }
            return cost.weight > other.cost.weight;
        }
    };

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<Node> vertices;
        vertices.reserve(n);
        for (int i = 0; i < n; ++i) {
            vertices.emplace_back(i);
        }
        vector<vector<pair<int, int>>> adjacencyList(n); // adjacencyList[i] == (neighbourIndex, edgeWeightToNeighbour)
        for (const auto &flight: flights) {
            adjacencyList[flight.at(0)].emplace_back(flight.at(1), flight.at(2));
        }

        priority_queue<Node, vector<Node>, greater<>> queue; // todo проверить что находится минимум
        int maxLength = k + 2;
        vertices[src].cost.weight = 0;
        vertices[src].cost.pathLength = 1;
        queue.push(vertices[src]);

        while (!queue.empty()) {
            Node current = queue.top();
            queue.pop();

            if (current.number == dst) {
                return current.cost.weight;
            }

            for (const auto &neighbour: adjacencyList[current.number]) {
                int newWeight = current.cost.weight + neighbour.second;
                int newLength = current.cost.pathLength + 1;
                Cost &costNeighbour = vertices[neighbour.first].cost;
                if (newLength <= maxLength) {
                    if (newWeight < costNeighbour.weight || newLength < costNeighbour.pathLength) {
                        queue.emplace(neighbour.first, newWeight, newLength);
                        if (newWeight < costNeighbour.weight) {
                            vertices[neighbour.first].cost.weight = newWeight;
                            vertices[neighbour.first].cost.pathLength = newLength;
                        }
                    }
                }
            }
        }

        return -1;
    }
};
