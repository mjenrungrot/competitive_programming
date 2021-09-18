/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12783.cc
#  Description:     UVa Online Judge - 12783
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

vs split(string line, regex re) {
    vs output;
    sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
    while (it != it_end) {
        output.push_back(it->str());
        it++;
    }
    return output;
}

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 1005;

int N, M;
int dfs_counter;
vi V[MAXN], dfs_num, dfs_low;
vii ans;

void dfs(int u, int p) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for (auto v : V[u]) {
        if (dfs_num[v] == 0) {
            dfs(v, u);

            if (dfs_low[v] > dfs_num[u]) {
                ans.push_back(ii(min(u, v), max(u, v)));
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        for (int i = 0; i < MAXN; i++) V[i].clear();
        dfs_num = vi(MAXN, 0);
        dfs_low = vi(MAXN, 0);
        dfs_counter = 1;
        ans.clear();

        if (N == 0 and M == 0) break;

        for (int i = 1; i <= M; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);
        }

        for (int i = 0; i < N; i++)
            if (dfs_num[i] == 0) dfs(i, -1);

        sort(ans.begin(), ans.end());
        cout << ans.size();
        for (auto x : ans) cout << " " << x.first << " " << x.second;
        cout << endl;
    }

    return 0;
}