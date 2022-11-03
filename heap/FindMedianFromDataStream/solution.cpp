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
    priority_queue<int, vector<int>, less<>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
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
        // если разница между кучами строго больше 1, то их нужно балансировать
        // но надо не забыть, правильно посчитать разницу тк это unsigned числа
        bool isLeftHeapGreater = max(minHeap.size(), maxHeap.size()) == maxHeap.size();

        if (isLeftHeapGreater) {
            // pop from left to right
        }
    }

    double findMedian() {
    }
};