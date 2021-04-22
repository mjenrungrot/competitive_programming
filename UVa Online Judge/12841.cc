/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12841.cc
#  Description:     UVa Online Judge - 12841
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 18;
const int MAXMASK = 1 << 14;
int N, M;
vector<char> Vs, edges[MAXN];
map<char, int> to_idx;

int dp[MAXN][MAXMASK], next_val[MAXN][MAXMASK];

int f(int curr, int mask) {
    if (mask == 0) {
        if (curr == to_idx[Vs.back()])
            return 1;
        else
            return 0;
    }

    if (dp[curr][mask] != -1) return dp[curr][mask];

    int ans = 0, best_next_val = -1;
    for (auto v : edges[curr]) {
        int v_idx = to_idx[v];
        if (not(mask & (1 << (v_idx - 1)))) continue;
        int val = f(v_idx, mask - (1 << (v_idx - 1)));
        if (val) {
            ans = val;
            best_next_val = v_idx;
            break;
        }
    }
    next_val[curr][mask] = best_next_val;
    return dp[curr][mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while (T--) {
        to_idx.clear();
        cin >> N >> M;

        Vs.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> Vs[i];
            to_idx[Vs[i]] = i;
            edges[i].clear();
        }

        for (int i = 0; i < M; i++) {
            char u, v;
            cin >> u >> v;
            edges[to_idx[u]].push_back(v);
            edges[to_idx[v]].push_back(u);
        }

        for (int i = 0; i < N; i++) {
            sort(edges[i].begin(), edges[i].end());
        }

        memset(dp, -1, sizeof(dp));
        int ans = f(to_idx[Vs[0]], (1 << (N - 1)) - 1);

        cout << "Case " << ++n_case << ": ";
        if (not ans)
            cout << "impossible" << endl;
        else {
            vector<char> ans;
            int curr = to_idx[Vs.front()], curr_mask = (1 << (N - 1)) - 1;
            for (int i = 0; i < N; i++) {
                cout << Vs[curr];
                curr = next_val[curr][curr_mask];
                curr_mask -= (1 << (curr - 1));
            }
            cout << endl;
        }
    }
    return 0;
}