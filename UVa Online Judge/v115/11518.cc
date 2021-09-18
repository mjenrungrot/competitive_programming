/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11518.cc
#  Description:     UVa Online Judge - 11518
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

vvi V;
vi dfs_state;

void dfs(int u) {
    if (dfs_state[u]) return;
    dfs_state[u] = 1;

    for (auto v : V[u]) {
        if (dfs_state[v]) continue;
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M, L;
        cin >> N >> M >> L;

        V.clear();
        V.resize(N + 1);
        dfs_state.clear();
        dfs_state.resize(N + 1);

        for (int i = 1; i <= M; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
        }

        for (int i = 1; i <= L; i++) {
            int u;
            cin >> u;
            dfs(u);
        }

        int ans = 0;
        for (int i = 1; i <= N; i++)
            if (dfs_state[i]) ans++;
        cout << ans << endl;
    }

    return 0;
}