/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11749.cc
#  Description:     UVa Online Judge - 11749
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

const int MAXN = 505;

int N, M;
int n_comp, max_edge = -1;
vii V[MAXN];
vi dfs_state, comp_sizes;

void dfs(int u) {
    if (dfs_state[u]) return;
    dfs_state[u] = n_comp;

    for (auto v : V[u]) {
        if (dfs_state[v.first]) continue;
        if (v.second != max_edge) continue;
        dfs(v.first);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;

        for (int i = 1; i <= N; i++) {
            V[i].clear();
        }

        for (int i = 1; i <= M; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            V[u].push_back(ii(v, cost));
            V[v].push_back(ii(u, cost));
            if (i == 1)
                max_edge = cost;
            else
                max_edge = max(max_edge, cost);
        }

        n_comp = 0;
        dfs_state.clear();
        dfs_state.resize(N + 1);
        comp_sizes.clear();
        comp_sizes.resize(N + 1);

        for (int i = 1; i <= N; i++) {
            ++n_comp;
            if (not dfs_state[i]) dfs(i);
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            comp_sizes[dfs_state[i]]++;
            ans = max(ans, comp_sizes[dfs_state[i]]);
        }
        cout << ans << endl;
    }
    return 0;
}