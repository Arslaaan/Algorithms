#pragma once

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    static int distance(const pair<int, int> &p1, const pair<int, int> &p2) {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }

    class QuickUnion {
        map<pair<int, int>, pair<int, int>> root;
        map<pair<int, int>, int> rank;
    public:
        explicit QuickUnion(vector<vector<int>> &points) {
            for (auto &point : points) {
                pair<int, int> p = make_pair(point.at(0), point.at(1));
                root[p] = p;
                rank[p] = 1;
            }
        }

        const pair<int, int> &find(const pair<int, int> &x) {
            if (x == root[x]) {
                return x;
            }
            return root[x] = find(root[x]);
        }

        void unionPoints(const pair<int, int> &x, const pair<int, int> &y, bool &connectionCreated) {
            const pair<int, int> &rootX = find(x);
            const pair<int, int> &rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    root[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    root[rootY] = rootX;
                } else {
                    root[rootX] = rootY;
                    rank[rootX] += 1;
                }
                connectionCreated = true;
                return;
            }
            connectionCreated = false;
        }
    };

    class Edge {
        pair<int, int> point1;
        pair<int, int> point2;
        int weight;
    public:
        Edge(const pair<int, int> &p1, const pair<int, int> &p2) {
            point1 = p1;
            point2 = p2;
            weight = distance(p1, p2);
        }

        bool operator<(const Edge &other) const {
            return weight < other.getWeight();
        }

        bool operator==(const Edge &other) const {
            return point1 == other.point1 && point2 == other.point2 ||
                   point1 == other.point2 && point2 == other.point1;
        }

        int getWeight() const {
            return weight;
        }

        const pair<int, int> &getPoint1() const {
            return point1;
        }

        const pair<int, int> &getPoint2() const {
            return point2;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        vector<Edge> edges;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                edges.emplace_back(make_pair(points.at(i).at(0), points.at(i).at(1)),
                                   make_pair(points.at(j).at(0), points.at(j).at(1)));
            }
        }

        int result = 0;
        QuickUnion quickUnion(points);
        if (!edges.empty()) {
            sort(edges.begin(), edges.end());
            int index = 0;
            int addedEdges = 0;
            while (addedEdges != points.size() - 1) {
                const Edge &edge = edges.at(index);
                bool connectionCreated;
                quickUnion.unionPoints(edge.getPoint1(), edge.getPoint2(), connectionCreated);
                if (connectionCreated) {
                    result += edge.getWeight();
                    addedEdges++;
                }
                index++;
            }
        }
        return result;
    }
};
