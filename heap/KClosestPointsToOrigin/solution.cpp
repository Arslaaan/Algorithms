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

class Solution {

    class Point {
        int x;
        int y;
        double distance;
    public:
        Point(int x_, int y_) {
            x = x_;
            y = y_;
            distance = sqrt(1.0 * x * x + y * y);
        }

        bool operator<(const Point &other) const {
            return distance < other.distance;
        }

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<Point, vector<Point>, less<>> maxHeap;
        for (auto &i : points) {
            Point point = Point(i[0], i[1]);
            if (maxHeap.size() < k) {
                maxHeap.push(point);
            } else if (point < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(point);
            }
        }

        vector<vector<int>> result;
        result.reserve(k);
        while (!maxHeap.empty()) {
            result.push_back({maxHeap.top().getX(), maxHeap.top().getY()});
            maxHeap.pop();
        }
        return result;
    }
};