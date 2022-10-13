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
        set<int> verticesToCheck;
        for (int i = 0; i < numCourses; ++i) {
            verticesToCheck.insert(i);
        }

        while (orderedVertices.size() < numCourses) {
            int noParentsVertice = -1;
            for (auto &v : verticesToCheck) {
                const set<int> &parents = adjacencyList[v];
                if (parents.empty() && orderedVertices.count(v) == 0) {
                    orderedVertices.insert(v);
                    for (int j = 0; j < adjacencyList.size(); ++j) {
                        adjacencyList[j].erase(v);
                    }
                    noParentsVertice = v;
                    break;
                }
            }
            if (noParentsVertice == -1) {
                break;
            }
            verticesToCheck.erase(noParentsVertice);
        }

        return orderedVertices.size() == numCourses;
    }
};
