/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10672.cc
#  Description:     UVa Online Judge - 10672
=============================================================================*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void compute_sum(int node, vector<vector<int> > &V, vector<int> &sum_val,
                 vector<int> &n_nodes) {
    for (auto v : V[node]) {
        compute_sum(v, V, sum_val, n_nodes);
        sum_val[node] += sum_val[v];
        n_nodes[node] += n_nodes[v];
    }
}

int find_ans(int node, vector<vector<int> > &V, vector<int> &sum_val,
             vector<int> &n_nodes) {
    if (V[node].size() == 0) {
        return abs(sum_val[node] - n_nodes[node]);
    }

    int total = 0;
    for (auto v : V[node]) {
        total += find_ans(v, V, sum_val, n_nodes);
    }
    total += abs(sum_val[node] - n_nodes[node]);
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        if (N == 0) break;
        vector<vector<int> > V(N + 1);
        vector<int> val(N + 1), sum_val(N + 1), n_nodes(N + 1);
        vector<int> isRoot(N + 1, 1);

        for (int i = 1; i <= N; i++) {
            int u, k;
            cin >> u;
            cin >> val[u];
            cin >> k;
            sum_val[u] = val[u];
            n_nodes[u] = 1;
            for (int j = 1; j <= k; j++) {
                int tmp;
                cin >> tmp;
                V[u].push_back(tmp);
                isRoot[tmp] = false;
            }
        }

        int root = -1;
        for (int i = 1; i <= N; i++) {
            if (isRoot[i]) {
                root = i;
                break;
            }
        }

        compute_sum(root, V, sum_val, n_nodes);
        int ans = find_ans(root, V, sum_val, n_nodes);
        cout << ans << endl;
    }
    return 0;
}