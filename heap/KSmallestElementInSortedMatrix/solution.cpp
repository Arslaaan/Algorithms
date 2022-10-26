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
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        priority_queue<int, vector<int>, less<>> maxHeap;

        int maxMatrixSize = min((size_t) k, matrix.size());
        bool full = false;
        for (int i = 0; i < maxMatrixSize; ++i) {
            for (int j = 0; j < maxMatrixSize; ++j) {
                if (!full) {
                    maxHeap.push(matrix.at(i).at(j));
                    if (maxHeap.size() == k) {
                        full = true;
                    }
                } else {
                    if ((i + 1) * (j + 1) > k) {
                        continue;
                    }
                    if (matrix.at(i).at(j) < maxHeap.top()) {
                        maxHeap.pop();
                        maxHeap.push(matrix.at(i).at(j));
                    }
                }
            }
        }
        return maxHeap.top();
    }
};
