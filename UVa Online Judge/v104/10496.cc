/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10496.cc
#  Description:     UVa Online Judge - 10496
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 15;
const int MAXMASK = 1 << 15;
typedef pair<int, int> ii;
int dist[MAXN][MAXN];
int memo[MAXN][MAXMASK];

int f(int curr, int mask) {
    if (mask == 0) {
        return curr == 0 ? 0 : INF;
    }
    if (memo[curr][mask] != -1) return memo[curr][mask];

    int ans = INF;
    int curr_mask = mask, best_idx = -1;
    while (curr_mask) {
        int next_bit = __builtin_ctz(curr_mask & -curr_mask);
        int val = dist[curr][next_bit] + f(next_bit, mask - (1 << next_bit));
        if (val < ans) {
            ans = min(ans, val);
            best_idx = next_bit;
        }
        curr_mask -= curr_mask & -curr_mask;
    }
    return memo[curr][mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int C, R;
        cin >> C >> R;
        int start_x, start_y;
        cin >> start_x >> start_y;

        int N;
        vector<ii> nodes;

        nodes.push_back(ii(start_x, start_y));
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            nodes.push_back(ii(x, y));
        }

        for (int i = 0; i < nodes.size(); i++)
            for (int j = 0; j < nodes.size(); j++) {
                if (i == j) {
                    dist[i][j] = INF;
                } else {
                    dist[i][j] = abs(nodes[i].first - nodes[j].first) +
                                 abs(nodes[i].second - nodes[j].second);
                }
            }

        for (int k = 0; k < nodes.size(); k++)
            for (int i = 0; i < nodes.size(); i++)
                for (int j = 0; j < nodes.size(); j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        memset(memo, -1, sizeof(memo));
        int ans = f(0, (1 << nodes.size()) - 1);

        cout << "The shortest path has length " << ans << endl;
    }
    return 0;
}