/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        705.cc
#  Description:     UVa Online Judge - 705
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

const int MAXN = 200;

int R, C;
char original[MAXN][MAXN];
int dfs_state[MAXN * MAXN];
vi V[MAXN * MAXN];
map<ii, int> to_idx;

ii conv(ii pos) {
    return ii(pos.first + pos.second, R + pos.second - pos.first);
}

int floodfill(int node, int parent, int &cycle) {
    if (dfs_state[node]) return 0;
    dfs_state[node] = 1;

    int ans = 1;
    for (auto v : V[node]) {
        if (v == parent) continue;
        if (dfs_state[v]) {
            cycle = true;
            continue;
        }
        ans += floodfill(v, node, cycle);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> C >> R) {
        if (R == 0 and C == 0) break;

        memset(dfs_state, 0, sizeof(dfs_state));
        to_idx.clear();
        for (int i = 0; i < MAXN * MAXN; i++) V[i].clear();

        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++) {
                cin >> original[i][j];

                // make nodes
                ii top_left = conv(ii(i, j));
                for (int dr : {0, 1}) {
                    for (int dc : {0, 1}) {
                        ii transformed_pos =
                            ii(top_left.first + dr, top_left.second + dc);
                        if (to_idx.count(transformed_pos)) continue;
                        to_idx[transformed_pos] = to_idx.size() + 1;
                    }
                }

                // make edges
                ii top_right = ii(top_left.first, top_left.second + 1);
                ii bot_left = ii(top_left.first + 1, top_left.second);
                ii bot_right = ii(top_left.first + 1, top_left.second + 1);
                if (original[i][j] == '/') {
                    V[to_idx[top_left]].push_back(to_idx[top_right]);
                    V[to_idx[top_right]].push_back(to_idx[top_left]);
                    V[to_idx[bot_left]].push_back(to_idx[bot_right]);
                    V[to_idx[bot_right]].push_back(to_idx[bot_left]);
                } else {
                    V[to_idx[top_left]].push_back(to_idx[bot_left]);
                    V[to_idx[bot_left]].push_back(to_idx[top_left]);
                    V[to_idx[top_right]].push_back(to_idx[bot_right]);
                    V[to_idx[bot_right]].push_back(to_idx[top_right]);
                }
            }

        int ans = 0, n_cycles = 0;
        for (auto x : to_idx) {
            ii pos = x.first;
            int idx = to_idx[pos];

            if (dfs_state[idx]) continue;
            int cycle = false;
            int val = floodfill(idx, -1, cycle);
            if (not cycle) continue;
            ans = max(ans, val);
            n_cycles++;
        }
        cout << "Maze #" << ++n_test << ":" << endl;
        if (n_cycles)
            cout << n_cycles << " Cycles; the longest has length " << ans << "."
                 << endl;
        else
            cout << "There are no cycles." << endl;
        cout << endl;
    }

    return 0;
}