#include <bits/stdc++.h>
using namespace std;

namespace bellman_ford {
int N;                              // number of vertices
int start;                          // start node
vector<vector<pair<int, int>>> AL;  // adjacency list
const int INF = 1e9 + 7;            // infinity value
vector<int> dist;                   // distance vector
int has_negative;                   // has negative cycle?

void bellman_ford_moore() {
    has_negative = -1;

    dist = vector<int>(N, INF);
    dist[start] = 0;

    queue<int> Q;
    Q.push(start);
    vector<int> in_queue(N, 0);
    in_queue[start] = 1;

    while (not Q.empty()) {
        int u = Q.front();
        Q.pop();
        in_queue[start] = 0;
        for (auto &x : AL[u]) {
            auto v = x.first;
            auto w = x.second;
            if (dist[u] + w >= dist[v]) continue;  // not improving, skip
            dist[v] = dist[u] + w;                 // relax op
            if (not in_queue[v]) {  // add to the queue only if v is not already
                                    // in the queue
                Q.push(v);
                in_queue[v] = 1;
            }
        }
    }

    has_negative = -1;
    for (int u = 0; u < N; u++) {
        cout << "SSSP(" << start << "," << u << ") = " << dist[u] << endl;
    }
}

void bellman_ford() {
    dist = vector<int>(N, INF);
    dist[start] = 0;

    for (int i = 0; i < N - 1; i++) {
        bool modified = false;  // optimization
        for (int u = 0; u < N; u++) {
            if (dist[u] != INF) {
                for (auto &x : AL[u]) {
                    auto v = x.first;
                    auto w = x.second;
                    if (dist[u] + w >= dist[v])
                        continue;           // not improving, skip
                    dist[v] = dist[u] + w;  // relax op
                    modified = true;        // optimization
                }
            }
        }
        if (not modified) break;  // optimization
    }

    has_negative = false;
    for (int u = 0; u < N; u++) {
        if (dist[u] != INF) {
            for (auto &x : AL[u]) {
                auto v = x.first;
                auto w = x.second;
                if (dist[v] > dist[u] + w) {
                    has_negative = true;
                    cout << "has negative cycle" << endl;
                }
            }
        }
    }

    if (not has_negative) {
        for (int u = 0; u < N; u++) {
            cout << "SSSP(" << start << "," << u << ") = " << dist[u] << endl;
        }
    }
}

}  // namespace bellman_ford

int main() {
    // Example 1: No negative cycle
    // N = 5
    // start = 0
    // 0 1 1
    // 0 2 10
    // 1 3 2
    // 2 3 -10
    // 3 4 3
    bellman_ford::N = 5;
    bellman_ford::start = 0;
    bellman_ford::AL = {{{1, 1}, {2, 10}}, {{3, 2}}, {{3, -10}}, {{4, 3}}, {}};
    cout << endl << endl;
    cout << "bellman ford" << endl;
    bellman_ford::bellman_ford();
    cout << "bellman ford moore" << endl;
    bellman_ford::bellman_ford_moore();

    // Example 2: negative cycle
    // N = 6
    // start = 0
    // 0 1 1
    // 0 2 10
    // 1 3 2
    // 2 3 -10
    // 3 4 3
    bellman_ford::N = 6;
    bellman_ford::start = 0;
    bellman_ford::AL = {
        {{1, 99}, {5, -99}}, {{2, 15}}, {{3, 0}}, {{1, -42}, {4, 2}}, {}};
    cout << endl << endl;
    cout << "bellman ford" << endl;
    bellman_ford::bellman_ford();
    cout << "bellman ford moore" << endl;
    bellman_ford::bellman_ford_moore();

    return 0;
}