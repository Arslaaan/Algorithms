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

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<set<int>> adjacencyList(numCourses); // todo подумать насчет нескольких ребер
        for (auto &prerequisite : prerequisites) {
            adjacencyList[prerequisite[1]].insert(prerequisite[0]);
        }
        set<int> orderedVertices;

        while (orderedVertices.size() < numCourses) {
            int foundVertice = -1;
            for (int i = 0; i < adjacencyList.size(); ++i) {
                const set<int> &parents = adjacencyList[i];
                if (parents.empty() && orderedVertices.count(i) == 0) {
                    orderedVertices.insert(i);
                    foundVertice = i;
                }
            }
            if (foundVertice > -1) {
                for (int i = 0; i < adjacencyList.size() && i != foundVertice; ++i) {
                    adjacencyList[i].erase(foundVertice);
                }
            } else {
                break;
            }
        }

        return orderedVertices.size() == numCourses;
    }
};
