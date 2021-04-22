/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10465.cc
#  Description:     UVa Online Judge - 10465
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

const int MAXN = 10005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N, T;
    while (cin >> M >> N >> T) {
        vi dp(MAXN, -INF_INT);
        dp[0] = 0;
        for (int i = 0; i + M < MAXN; i++) {
            if (dp[i] != -INF_INT) dp[i + M] = max(dp[i + M], dp[i] + 1);
        }
        for (int i = 0; i + N < MAXN; i++) {
            if (dp[i] != -INF_INT) dp[i + N] = max(dp[i + N], dp[i] + 1);
        }

        int ans = dp[T];
        if (ans == -INF_INT) {
            for (int i = T - 1; i >= 0; i--) {
                if (dp[i] != -INF_INT) {
                    cout << dp[i] << " " << T - i << endl;
                    break;
                }
            }
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}