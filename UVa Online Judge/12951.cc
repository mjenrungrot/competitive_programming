/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12951.cc
#  Description:     UVa 12951
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
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

const int MAXN = 200005;
int dp[MAXN][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, C;
    while (cin >> N >> C) {
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 0;
        dp[0][1] = -INF_INT;
        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + x);  // sell
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - x - C);
        }
        int ans = max(dp[N][0], dp[N][1]);
        cout << ans << endl;
    }
    return 0;
}