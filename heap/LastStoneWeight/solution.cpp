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
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int, vector<int>, less<>> priorityQueue(stones.begin(), stones.end());

        while (priorityQueue.size() > 1) {
            int x = priorityQueue.top();
            priorityQueue.pop();
            int y = priorityQueue.top();
            priorityQueue.pop();

            if (x == y) {
                continue;
            } else {
                priorityQueue.push(abs(x - y));
            }
        }
        if (priorityQueue.empty()) {
            return 0;
        }
        return priorityQueue.top();
    }
};
