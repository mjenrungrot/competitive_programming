/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        459.cc
#  Description:     UVa Online Judge - 459
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

void dfs(int u, int n_cc) {
    if (dfs_state[u] != 0) return;
    dfs_state[u] = n_cc;

    for (auto v : V[u]) {
        if (dfs_state[v] != 0) continue;
        dfs(v, n_cc);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);
    getline(cin, line);  // empty line
    while (T--) {
        getline(cin, line);
        char ch = line[0];

        V.clear();
        V.resize(ch + 1);
        dfs_state.clear();
        dfs_state.resize(ch + 1);

        while (getline(cin, line)) {
            if (line == "") break;
            V[line[0]].push_back(line[1]);
            V[line[1]].push_back(line[0]);
        }

        int n_cc = 0;
        for (int i = 'A'; i <= (int)ch; i++) {
            if (dfs_state[i] == 0) dfs(i, ++n_cc);
        }
        cout << n_cc << endl;
        if (T) cout << endl;
    }

    return 0;
}