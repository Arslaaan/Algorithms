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
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> frequents;
        auto cmp = [&frequents](int a, int b) {
            return frequents[a] > frequents[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);
        set<int> distinctElements;

        for (int &num : nums) {
            if (frequents[num]++ == 0);
        }

        int index = 0;
        for (int &num : nums) {
            if (distinctElements.count(num) == 0) {
                minHeap.push(num);
                distinctElements.insert(num);
                if (minHeap.size() == k) {
                    break;
                }
            }
            index++;
        }

        for (int i = index + 1; i < nums.size(); ++i) {
            if ((frequents[nums[i]] > frequents[minHeap.top()]) && distinctElements.count(nums[i]) == 0) {
                distinctElements.erase(minHeap.top());
                minHeap.pop();
                minHeap.push(nums[i]);
                distinctElements.insert(nums[i]);
            }
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};
