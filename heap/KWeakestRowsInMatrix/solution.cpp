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
    struct RowInfo {
        int row;
        int soldiers;

        RowInfo(int row_, int soldiers_) {
            row = row_;
            soldiers = soldiers_;
        }

        bool operator>(const RowInfo &other) const {
            if (other.soldiers == soldiers) {
                return row > other.row;
            }
            return soldiers > other.soldiers;
        }

        bool operator<(const RowInfo &other) const {
            if (other.soldiers == soldiers) {
                return row < other.row;
            }
            return soldiers < other.soldiers;
        }
    };

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<RowInfo> rowInfos;
        for (int i = 0; i < mat.size(); ++i) {
            int count = 0;
            for (int x: mat.at(i)) {
                if (x == 1) {
                    count++;
                } else {
                    break;
                }
            }
            rowInfos.emplace_back(i, count);
        }
        priority_queue<RowInfo, vector<RowInfo>, less<>> maxHeap(rowInfos.begin(), rowInfos.begin() + k);
        auto it = rowInfos.begin() + k;
        while (it != rowInfos.end()) {
            if (*it < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(*it);
            }
            it++;
        }

        vector<int> result(k);
        int i = 0;
        while (!maxHeap.empty()) {
            result[k - i - 1] = maxHeap.top().row;
            maxHeap.pop();
            i++;
        }
        return result;
    }
};
