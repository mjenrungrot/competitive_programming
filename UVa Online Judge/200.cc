/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        200.cc
#  Description:     UVa Online Judge - 200
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

const int MAXN = 300;

vi V[MAXN];
int dfs_state[MAXN];
vector<string> lines;
set<char> all_chars;

void toposort(int node, vi &output) {
    dfs_state[node] = 1;
    for (auto v : V[node]) {
        if (dfs_state[v]) continue;
        toposort(v, output);
    }
    output.push_back(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        if (cin.eof()) break;

        lines.clear();
        all_chars.clear();
        string line;
        while (getline(cin, line)) {
            if (line == "#") break;
            lines.push_back(line);
            for (auto ch : lines.back()) all_chars.insert(ch);
        }
        if (lines.size() == 0) break;

        for (int i = 0; i < MAXN; i++) V[i].clear();
        for (int i = 0; i < lines.size() - 1; i++) {
            for (int j = 0; j < lines[i].size() and j < lines[i + 1].size();
                 j++) {
                if (lines[i][j] == lines[i + 1][j]) continue;
                V[lines[i][j]].push_back(lines[i + 1][j]);
                break;
            }
        }

        // topo sort
        memset(dfs_state, 0, sizeof(dfs_state));
        vi output;
        for (auto ch : all_chars) {
            if (dfs_state[ch]) continue;
            toposort(ch, output);
        }
        reverse(output.begin(), output.end());

        for (auto ch : output) {
            cout << (char)ch;
        }
        cout << endl;
    }

    return 0;
}