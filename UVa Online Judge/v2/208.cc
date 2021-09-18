/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        208.cc
#  Description:     UVa Online Judge - 208
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
const int START = 1;
const int MAX_NODE = 30;

int target, n_routes, n_cases;
vector<int> V[MAX_NODE];
vector<int> used(MAX_NODE, 0);
vector<int> curr_path;

bool reachable_test() {
    int dp[MAX_NODE][MAX_NODE];
    for (int i = 0; i < MAX_NODE; i++)
        for (int j = 0; j < MAX_NODE; j++) dp[i][j] = INF;
    for (int i = 0; i < MAX_NODE; i++) {
        dp[i][i] = 0;
        for (auto v : V[i]) dp[i][v] = 1;
    }
    for (int k = 0; k < MAX_NODE; k++)
        for (int i = 0; i < MAX_NODE; i++)
            for (int j = 0; j < MAX_NODE; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
    if (dp[START][target] < INF) return true;
    return false;
}

void f(int node) {
    if (node == target) {
        ++n_routes;
        bool space = false;
        for (auto u : curr_path) {
            if (space) cout << " ";
            cout << u;
            space = true;
        }
        cout << endl;
        return;
    }

    for (auto v : V[node]) {
        if (used[v]) continue;
        used[v] = 1;
        curr_path.push_back(v);
        f(v);
        used[v] = 0;
        curr_path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> target) {
        cout << "CASE " << ++n_cases << ":" << endl;
        for (int i = 0; i < MAX_NODE; i++) V[i].clear();

        int u, v;
        while (cin >> u >> v) {
            if (u == 0 and v == 0) break;
            V[u].push_back(v);
            V[v].push_back(u);
        }

        for (int i = 0; i < MAX_NODE; i++) sort(V[i].begin(), V[i].end());

        n_routes = 0;
        fill(used.begin(), used.end(), 0);
        curr_path.clear();
        curr_path.push_back(START);
        used[START] = true;
        if (reachable_test()) {
            f(START);
        }
        cout << "There are " << n_routes
             << " routes from the firestation to streetcorner " << target << "."
             << endl;
    }
    return 0;
}