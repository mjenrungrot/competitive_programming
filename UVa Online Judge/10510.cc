/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10510.cc
#  Description:     UVa Online Judge - 10510
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

enum state { UNVISITED, IN_PROGRESS, DONE };
int N, M;
int numSCC;
int dfs_num_counter, dfs_state[MAXN], dfs_num[MAXN], dfs_low[MAXN],
    visited[MAXN];
vi V[MAXN];
stack<int> St;

void dfs(int u, int &forward_edge) {
    dfs_state[u] = IN_PROGRESS;
    dfs_num[u] = dfs_low[u] = dfs_num_counter++;
    St.push(u);
    visited[u] = true;

    for (auto v : V[u]) {
        if (dfs_state[v] == UNVISITED) {
            dfs(v, forward_edge);
        } else if (dfs_state[v] == DONE) {
            forward_edge = true;
        }

        if (visited[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }
    dfs_state[u] = DONE;
    if (dfs_low[u] == dfs_num[u]) {
        ++numSCC;
        while (true) {
            int v = St.top();
            St.pop();
            visited[v] = 0;
            if (u == v) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        memset(dfs_state, UNVISITED, sizeof(dfs_state));
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < MAXN; i++) V[i].clear();
        St = stack<int>();
        numSCC = 0;
        dfs_num_counter = 0;

        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
        }

        int forward_edge = false;
        for (int i = 0; i < N; i++) {
            if (dfs_state[i] == UNVISITED) dfs(i, forward_edge);
        }

        if (numSCC == 1 and not forward_edge)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}