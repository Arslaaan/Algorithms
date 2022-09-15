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

        bool operator>(const Edge &other) const {
            return weight > other.getWeight();
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
        map<pair<int, int>, vector<Edge>> graph;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                auto p1 = make_pair(points.at(i).at(0), points.at(i).at(1));
                auto p2 = make_pair(points.at(j).at(0), points.at(j).at(1));
                graph[p1].emplace_back(p1, p2);
                graph[p2].emplace_back(p2, p1);
            }
        }

        int result = 0;

        if (points.size() > 1) {
            set<pair<int, int>> visited;
            pair<int, int> firstPoint = make_pair(points.at(0).at(0), points.at(0).at(1));
            priority_queue<Edge, vector<Edge>, greater<>> heap(graph.at(firstPoint).begin(),
                                                               graph.at(firstPoint).end());
            visited.insert(firstPoint);

            while (visited.size() != points.size()) {
                Edge top = heap.top();
                heap.pop();
                if (visited.count(top.getPoint1()) + visited.count(top.getPoint2()) == 1) {
                    result += top.getWeight();
                    visited.insert(top.getPoint1());
                    visited.insert(top.getPoint2());
                    for (const Edge &edge: graph.at(top.getPoint2())) {
                        if (visited.count(edge.getPoint2()) == 0) {
                            heap.push(edge);
                        }
                    }
                }
            }
        }
        return result;
    }
};
