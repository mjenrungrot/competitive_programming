/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        260.cc
#  Description:     UVa Online Judge - 260
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

const int MAXN = 205;
int N;
string A[MAXN];
int dfs_state[MAXN][MAXN];

void dfs(int r, int c, int &ans) {
    if (ans) return;
    if (c + 1 == N) {
        ans = true;
        return;
    }

    if (c == -1) {
        for (int i = 0; i < N; i++)
            if (A[i][0] == 'w') dfs(i, 0, ans);
    } else {
        if (dfs_state[r][c] == 1) return;
        dfs_state[r][c] = 1;

        if (r - 1 >= 0 and c - 1 >= 0 and A[r - 1][c - 1] == 'w')
            dfs(r - 1, c - 1, ans);
        if (r - 1 >= 0 and A[r - 1][c] == 'w') dfs(r - 1, c, ans);
        if (c - 1 >= 0 and A[r][c - 1] == 'w') dfs(r, c - 1, ans);
        if (c + 1 < N and A[r][c + 1] == 'w') dfs(r, c + 1, ans);
        if (r + 1 < N and A[r + 1][c] == 'w') dfs(r + 1, c, ans);
        if (r + 1 < N and c + 1 < N and A[r + 1][c + 1] == 'w')
            dfs(r + 1, c + 1, ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        memset(dfs_state, 0, sizeof(dfs_state));

        int ans = false;
        dfs(0, -1, ans);  // (row, col)

        if (ans)
            cout << ++n_test << " "
                 << "W" << endl;
        else
            cout << ++n_test << " "
                 << "B" << endl;
    }
    return 0;
}