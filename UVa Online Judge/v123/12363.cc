/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12363.cc
#  Description:     UVa Online Judge - 12363
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
const int MAXN = 10005;

int N, dfs_counter;
vi V[MAXN], dfs_num, dfs_low, component;
vii bridges;
set<ii> is_bridge;

void dfs(int u, int p) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for (auto v : V[u]) {
        if (dfs_num[v] == 0) {
            dfs(v, u);

            if (dfs_low[v] > dfs_num[u]) {
                bridges.push_back(ii(min(u, v), max(u, v)));
                is_bridge.insert(ii(min(u, v), max(u, v)));
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

void fill_component(int u, int idx) {
    component[u] = idx;
    for (auto v : V[u]) {
        if (component[v]) continue;
        if (is_bridge.count(ii(min(u, v), max(u, v)))) {
            fill_component(v, idx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) {
        for (int i = 0; i < MAXN; i++) V[i].clear();
        dfs_num = vi(MAXN, 0);
        dfs_low = vi(MAXN, 0);
        component = vi(MAXN, 0);
        bridges.clear();
        is_bridge.clear();
        dfs_counter = 1;

        if (N == 0) break;

        int n_edges, n_queries;
        cin >> n_edges >> n_queries;
        for (int i = 0; i < n_edges; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);
        }

        for (int i = 1; i <= N; i++) {
            if (dfs_num[i] == 0) {
                dfs(i, -1);
            }
        }

        int idx = 0;
        for (int i = 1; i <= N; i++) {
            if (component[i] == 0) {
                fill_component(i, ++idx);
            }
        }

        for (int i = 0; i < n_queries; i++) {
            int start, end;
            cin >> start >> end;
            if (component[start] == component[end])
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
        cout << "-" << endl;
    }

    return 0;
}