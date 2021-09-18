/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11953.cc
#  Description:     UVa Online Judge - 11953
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

const int MAXN = 105;

int N;
int dfs_state[MAXN][MAXN];
string A[MAXN];
vi sizes;

void dfs(int r, int c) {
    if (dfs_state[r][c]) return;
    dfs_state[r][c] = sizes.size();
    sizes.back()++;

    for (int dy : {-1, 0, 1}) {
        for (int dx : {-1, 0, 1}) {
            if (dy == 0 and dx == 0) continue;
            if (abs(dy) + abs(dx) == 2) continue;
            if (r + dy < 0 or r + dy >= N) continue;
            if (c + dx < 0 or c + dx >= N) continue;
            if (A[r + dy][c + dx] == '.') continue;
            if (dfs_state[r + dy][c + dx]) continue;
            dfs(r + dy, c + dx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cin >> N;
        memset(dfs_state, 0, sizeof(dfs_state));
        for (int i = 0; i < N; i++) cin >> A[i];

        sizes.clear();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (A[i][j] != 'x') continue;
                if (not dfs_state[i][j]) {
                    sizes.push_back(0);
                    dfs(i, j);
                }
            }

        int ans = 0;
        cout << "Case " << ++n_test << ": " << sizes.size() << endl;
    }

    return 0;
}