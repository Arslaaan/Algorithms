#pragma once

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <limits>
#include <cmath>

using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, less<>> maxHeap; // left part
    priority_queue<int, vector<int>, greater<>> minHeap; // right part
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (!maxHeap.empty() && num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        balanceHeaps();
    }

    void balanceHeaps() {
        if (maxHeap.size() != minHeap.size()) {
            // если разница между кучами строго больше 1, то их нужно балансировать
            // но надо не забыть, правильно посчитать разницу тк это unsigned числа
            bool isLeftHeapGreater = max(minHeap.size(), maxHeap.size()) == maxHeap.size();
            size_t diffSize = isLeftHeapGreater ? maxHeap.size() - minHeap.size() : minHeap.size() - maxHeap.size();
            if (diffSize > 1) {
                if (isLeftHeapGreater) {
                    // pop from left to right
                    int top = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(top);
                } else {
                    // pop from right to left
                    int top = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(top);
                }
            }
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size() && !maxHeap.empty()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            if (maxHeap.size() > minHeap.size()) {
                return maxHeap.top();
            } else {
                return minHeap.top();
            }
        }
    }
};