#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 1) bfs чз рекурсию оказался невозможен сохраняя асимптотику
// 2) не учитывал разные компоненты связности. 
// написал на это тест, но он был плохим - если во второй компоненте был цикл, то ответ все равно yes
int solution(int inputIndex) {
    std::ifstream cin("../yandex/Cheating/input" + to_string(inputIndex) +
                      ".txt");
    std::ofstream cout("../yandex/Cheating/output" + to_string(inputIndex) +
                       ".txt");
    int N, M;
    cin >> N >> M;
    vector<unordered_set<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].insert(v2);
        graph[v2].insert(v1);
    }

    unordered_set<int> notVisited, gr1, gr2;
    for (int i = 1;i < N + 1; ++i) {
        notVisited.insert(i);
    }

    queue<int> q;
    q.push(1);
    gr1.insert(1);
    bool result = true;
    while (!q.empty() || !notVisited.empty()) {
        int current;
        if (!q.empty()) {
            current = q.front();
            q.pop();
        } else {
            current = *notVisited.begin();
        }
        notVisited.erase(current);
        bool isFirst = gr1.count(current) == 1;
        for (int near : graph[current]) {
            if (isFirst) {
                if (gr1.count(near)) {
                    result = false;
                    break;
                }
                gr2.insert(near);
            } else {
                if (gr2.count(near)) {
                    result = false;
                    break;
                }
                gr1.insert(near);
            }
            if (notVisited.count(near)) {
                q.push(near);
            }
        }
    }

    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}