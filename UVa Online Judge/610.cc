/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        610.cc
#  Description:     UVa Online Judge - 610
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
vii bridges, ans;
set<ii> is_bridge, done;

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

void printans(int u, int p) {
    dfs_num[u] = true;
    for (auto v : V[u]) {
        if (done.count(ii(min(u, v), max(u, v)))) continue;
        if (is_bridge.count(ii(min(u, v), max(u, v)))) {
            ans.push_back(ii(u, v));
            ans.push_back(ii(v, u));
            done.insert(ii(min(u, v), max(u, v)));
            if (dfs_num[v] == 0) printans(v, u);
        } else if (v != p) {
            ans.push_back(ii(u, v));
            done.insert(ii(min(u, v), max(u, v)));
            if (dfs_num[v] == 0) printans(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;

        for (int i = 0; i < MAXN; i++) V[i].clear();
        dfs_num = vi(MAXN, 0);
        dfs_low = vi(MAXN, 0);
        bridges.clear();
        is_bridge.clear();
        done.clear();
        ans.clear();
        dfs_counter = 1;

        for (int i = 0; i < M; i++) {
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

        cout << ++n_test << endl;
        cout << endl;

        dfs_num = vi(MAXN, 0);
        for (int i = 1; i <= N; i++) {
            if (dfs_num[i] == 0) {
                printans(i, -1);
            }
        }

        sort(ans.begin(), ans.end());
        for (auto x : ans) {
            cout << x.first << " " << x.second << endl;
        }

        cout << "#" << endl;
    }

    return 0;
}