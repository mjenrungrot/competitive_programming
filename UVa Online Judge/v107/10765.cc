/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10765.cc
#  Description:     UVa Online Judge - 10765
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

int N, n_stations;
vi V[MAXN];
int dfs_counter;
vi dfs_num, dfs_low, articulation_point, n_components;

void dfs(int u, int parent) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    int n_children = 0;

    for (auto v : V[u]) {
        if (dfs_num[v] == 0) {
            n_children++;
            dfs(v, u);

            if (parent != -1 and
                dfs_low[v] >= dfs_num[u]) {  // v can go to u or ancestors of u
                articulation_point[u] = true;
                n_components[u] += 1;
            } else if (parent == -1 and n_children > 1) {
                articulation_point[u] = true;
                n_components[u] += 1;
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != parent) {  // non-trivial back-edge
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> n_stations) {
        if (N == 0 and n_stations == 0) break;

        for (int i = 0; i < MAXN; i++) V[i].clear();
        dfs_num = vi(MAXN, 0);
        dfs_low = vi(MAXN, 0);
        articulation_point = vi(MAXN, 0);
        n_components = vi(MAXN, 1);
        dfs_counter = 1;

        while (true) {
            int u, v;
            cin >> u >> v;
            if (u == -1 and v == -1) break;
            V[u].push_back(v);
            V[v].push_back(u);
        }

        for (int i = 0; i < N; i++) {
            if (dfs_num[i] == 0) {
                dfs(i, -1);
            }
        }

        vii ans;
        for (int i = 0; i < N; i++) {
            ans.push_back(ii(i, n_components[i]));
        }
        sort(ans.begin(), ans.end(), [](ii x, ii y) {
            if (x.second != y.second) return x.second > y.second;
            return x.first < y.first;
        });

        for (int i = 0; i < n_stations; i++)
            cout << ans[i].first << " " << ans[i].second << endl;
        cout << endl;
    }

    return 0;
}