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
        int number;
        int weight;
        vector<shared_ptr<Node>> neighbours;
    public:
        Node(int n, int w) {
            number = n;
            weight = w;
        }

        void add(const shared_ptr<Node> &neighbour) {
            neighbours.push_back(neighbour);
        }

        bool operator<(const Node &node) const {
            return weight < node.weight;
        }

        void setWeight(int nweight) {
            Node::weight = nweight;
        }

        int getNumber() const {
            return number;
        }

        int getWeight() const {
            return weight;
        }

        const vector<shared_ptr<Node>> &getNeighbours() const {
            return neighbours;
        }
    };

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        map<int, shared_ptr<Node>> graph;
        map<pair<int, int>, int> edges;
        for (const vector<int> &time : times) {
            if (graph.count(time.at(0)) == 0) {
                graph[time.at(0)] = make_shared<Node>(time.at(0), numeric_limits<int>::max());
            }
            if (graph.count(time.at(1)) == 0) {
                graph[time.at(1)] = make_shared<Node>(time.at(1), numeric_limits<int>::max());
            }
            graph[time.at(0)]->add(graph[time.at(1)]);
            edges[make_pair(time.at(0), time.at(1))] = time.at(2);
        }

        auto comparePtr = [](const shared_ptr<Node> &p1, const shared_ptr<Node> &p2) {
            return p1->getWeight() > p2->getWeight();
        };
        priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, decltype(comparePtr)> queue(comparePtr);
        set<shared_ptr<Node>> visited;
        shared_ptr<Node> &root = graph[k];
        root->setWeight(0);
        queue.push(root);

        while (!queue.empty()) {
            shared_ptr<Node> top = queue.top();
            queue.pop();

            if (visited.count(top) == 1) {
                continue;
            }

            for (const auto &neighbour: top->getNeighbours()) {
                int possiblePath = top->getWeight() + edges[make_pair(top->getNumber(), neighbour->getNumber())];
                if (possiblePath < neighbour->getWeight()) {
                    neighbour->setWeight(possiblePath);
                }
                queue.push(neighbour);
            }
            visited.insert(top);
        }

        int result = 0;
        if (visited.size() == n) {
            for (const auto &node: visited) {
                result = max(result, node->getWeight());
            }
            return result;
        }
        return -1;
    }
};
