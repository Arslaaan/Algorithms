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
        int verticesInPath;

        Cost() {
            weight = numeric_limits<int>::max();
            verticesInPath = numeric_limits<int>::max();
        }

        Cost(int weight_, int vertices_) {
            weight = weight_;
            verticesInPath = vertices_;
        }
    };

    static int compare(int x, int y) {
        if (x == y) {
            return 0;
        }
        if (x < y) {
            return 1;
        } else {
            return -1;
        }
    }

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<vector<Cost>> costs(n); // vertice -> cost1, cost2 ... because we minimize 2 measurements
        for (auto &v: costs) {
            v.emplace_back();
        }
        vector<vector<pair<int, int>>> adjacencyList(n); // adjacencyList[i] == (neighbourIndex, edgeWeightToNeighbour)
        for (const auto &flight: flights) {
            adjacencyList[flight.at(0)].emplace_back(flight.at(1), flight.at(2));
        }
        deque<int> queue;
        int maxVerticesInPath = k + 2;

        costs[src].at(0).weight = 0;
        costs[src].at(0).verticesInPath = 1;
        queue.push_back(src);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop_front();

            for (const auto &neighbour: adjacencyList[current]) {
                for (const auto &currentCost: costs[current]) {
                    int newWeight = currentCost.weight + neighbour.second;
                    int newVerticesInPath = currentCost.verticesInPath + 1;

                    if (newVerticesInPath <= maxVerticesInPath) {
                        vector<Cost> newCostsForNeighbour;
                        vector<Cost> &currentCostsForNeighbour = costs[neighbour.first];
                        bool hasRelaxation = false;
                        for (auto &currentCostOfNeighbour: currentCostsForNeighbour) {
                            int weightCompare = compare(newWeight, currentCostOfNeighbour.weight);
                            int lengthCompare = compare(newVerticesInPath, currentCostOfNeighbour.verticesInPath);
                            if (weightCompare > 0 && lengthCompare > 0 ||
                                weightCompare == 0 && lengthCompare > 0 ||
                                weightCompare > 0 && lengthCompare == 0) {
                                //1 происходит изменение стоимости
                                currentCostOfNeighbour.weight = newWeight;
                                currentCostOfNeighbour.verticesInPath = newVerticesInPath;
                                hasRelaxation = true;
                            } else if (weightCompare < 0 && lengthCompare > 0 ||
                                       weightCompare > 0 && lengthCompare < 0) {
                                //2 происходит добавление нового варианта
                                newCostsForNeighbour.emplace_back(newWeight, newVerticesInPath);
                                hasRelaxation = true;
                            }   //3 релаксация не произошла
                        }
                        if (!currentCostsForNeighbour.empty()) {
                            currentCostsForNeighbour.insert(currentCostsForNeighbour.end(),
                                                            newCostsForNeighbour.begin(), newCostsForNeighbour.end());
                        }
                        if (hasRelaxation && find(queue.begin(), queue.end(), neighbour.first) == queue.end()) {
                            queue.push_back(neighbour.first);
                        }
                    }
                }
            }
        }

        int result = numeric_limits<int>::max();
        for (const auto &cost: costs[dst]) {
            result = min(cost.weight, result);
        }
        if (result == numeric_limits<int>::max()) {
            result = -1;
        }
        return result;
    }
};
