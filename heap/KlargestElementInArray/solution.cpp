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
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int i = 0; i < k; ++i) {
            minHeap.push(nums[i]);
        }

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};
