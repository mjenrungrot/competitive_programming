/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11686.cc
#  Description:     UVa Online Judge - 11686
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

enum STATE { UNVISITED, IN_PROGRESS, DONE };
const int MAXN = 1000006;
int N, M;
vi V[MAXN];
int dfs_state[MAXN];

void toposort(int u, vi &ans, int &impossible) {
    dfs_state[u] = IN_PROGRESS;
    for (auto v : V[u]) {
        if (dfs_state[v] == IN_PROGRESS) {
            impossible = true;
            return;
        } else if (dfs_state[v] == DONE)
            continue;
        toposort(v, ans, impossible);
    }
    dfs_state[u] = DONE;
    ans.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;

        memset(dfs_state, 0, sizeof(dfs_state));
        for (int i = 0; i < MAXN; i++) V[i].clear();

        for (int i = 1; i <= M; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
        }

        vi ans;
        int impossible = false;
        for (int i = 1; i <= N; i++) {
            if (dfs_state[i]) continue;
            toposort(i, ans, impossible);
        }
        reverse(ans.begin(), ans.end());

        if (impossible)
            cout << "IMPOSSIBLE" << endl;
        else {
            for (auto x : ans) cout << x << endl;
        }
    }

    return 0;
}