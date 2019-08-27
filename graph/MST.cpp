/**
 * LeetCode Similar Problems:
 * https://leetcode.com/problems/optimize-water-distribution-in-a-village
 */
#include <bits/stdc++.h>
using namespace std;

void primMST(unordered_map<int, vector<pair<int, int>>> graph, int n, int &cost) {
    pair<int, int> pii; // cost, no.
    set<int> seen;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, 0));
    cost = 0;
    while (!pq.empty()) {
        auto pa = pq.top();
        pq.pop();
        if (seen.find(pa.second) != seen.end()) continue;
        cost += pa.first;
        seen.insert(pa.second);
        if (seen.size() == n) break;
        for (auto& next : graph[pa.second]) {
            if (seen.find(next.first) != seen.end()) continue;
            pq.push(make_pair(next.second, next.first));
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    unordered_map<int, vector<pair<int, int>>> vmap;
    int n = 5;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (graph[r][c]) {
                vmap[r].push_back(make_pair(c, graph[r][c]));
            }
        }
    }
    int cost = 0;
    primMST(vmap, n, cost);
    cout << "cost:" << cost << endl;

    return 0;
}
