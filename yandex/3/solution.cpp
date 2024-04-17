#pragma once
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
void printVector(std::ofstream& cout, const std::vector<T>& v) {
    cout << "[";
    for (int i = 0; i < v.size() - 1; ++i) {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << std::endl;
};

void findMinMax(const std::vector<int>& v, int begin, int end,
                std::unordered_map<std::string, std::pair<int, int>>& data) {
    int minV = v[begin];
    int maxV = v[begin];
    for (int i = begin; i <= end; ++i) {
        minV = std::min(minV, v[i]);
        maxV = std::max(maxV, v[i]);
    }
    data[std::to_string(begin) + std::to_string(end)] = {minV, maxV};
}

bool between(int a, int b, int x) {
    return x >= a && x <= b;
}

void readTask3(std::ifstream& cin, std::ofstream& cout) {
    int N;
    cin >> N;

    int num;
    std::vector<int> temperatures;
    temperatures.reserve(2 * N + 1);
    for (int i = 0; i < (2 * N + 1); ++i) {
        cin >> num;
        temperatures.push_back(num);
    }

    int B;
    cin >> B;
    std::vector<std::vector<int>> targets;
    int minIndex = 0, maxIndex = temperatures.size() - 1;
    for (int i = 0; i < B; ++i) {
        std::vector<int> target;
        for (int j = 0; j < 2; ++j) {  // temp
            cin >> num;
            target.push_back(num);
        }
        for (int j = 0; j < 2; ++j) {  // days
            cin >> num;
            target.push_back(num + N);
            minIndex = std::min(minIndex, num + N);
            maxIndex = std::max(maxIndex, num + N);
        }
        targets.push_back(move(target));
    }

    // cout << minIndex << " " << maxIndex << std::endl;
    std::unordered_map<std::string, std::pair<int, int>> data;

    for (int l = minIndex; l <= maxIndex; ++l) {
        for (int r = l; r <= maxIndex; ++r) {
            findMinMax(temperatures, l, r, data);
        }
    }

    for (int i = 0; i < B; ++i) {
        const auto& target = targets[i];
        std::string key = std::to_string(target[2]) + std::to_string(target[3]);
        std::pair<int, int>& val = data[key];
        if (between(val.first, val.second, target[0]) || 
            between(val.first, val.second, target[1]) ||
            between(target[0], target[1], val.first) ||
            between(target[0], target[1], val.second)
        ) {
            cout << "yes" << std::endl;
        } else {
            cout << "no" << std::endl;
        }
    }
};
