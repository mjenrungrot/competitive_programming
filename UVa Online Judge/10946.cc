/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10946.cc
#  Description:     UVa Online Judge - 10946
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

const int MAXN = 100;

int R, C;
vector<string> A;
int dfs_state[MAXN][MAXN];

int floodfill(int r, int c, char ch) {
    if (dfs_state[r][c]) return 0;
    dfs_state[r][c] = 1;

    int ans = 1;
    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) != 1) continue;
            if (r + dr < 0 or r + dr >= R) continue;
            if (c + dc < 0 or c + dc >= C) continue;
            if (A[r + dr][c + dc] == ch) {
                ans += floodfill(r + dr, c + dc, ch);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> R >> C) {
        if (R == 0 and C == 0) break;

        A.resize(R);
        for (int i = 0; i < R; i++) cin >> A[i];

        memset(dfs_state, 0, sizeof(dfs_state));
        vii ans;

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (dfs_state[i][j]) continue;
                if (A[i][j] != '.') {
                    int val = floodfill(i, j, A[i][j]);
                    ans.push_back(ii(val, A[i][j]));
                }
            }

        sort(ans.begin(), ans.end(), [](ii x, ii y) {
            if (x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        });

        cout << "Problem " << ++n_test << ":" << endl;
        for (auto x : ans) {
            cout << (char)x.second << " " << x.first << endl;
        }
    }

    return 0;
}