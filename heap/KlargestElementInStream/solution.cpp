#pragma once

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <limits>

using namespace std;

class KthLargest {
    int maxHeapSize;
    priority_queue<int, vector<int>, greater<>> minHeap;
public:
    KthLargest(int k, vector<int> &nums) {
        maxHeapSize = k;
        for (int i = 0; i < k && i < nums.size(); ++i) {
            minHeap.push(nums[i]);
        }

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if (minHeap.size() < maxHeapSize) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
    }
};