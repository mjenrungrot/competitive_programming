/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10910.cc
#  Description:     UVa 10910
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

const int MAXN = 75;
long long dp[MAXN][MAXN][MAXN];

long long f(int n, int t, int p) {
    if (n == 0) {
        return t == 0;
    }

    if (dp[n][t][p] != -1) return dp[n][t][p];
    long long ans = 0LL;
    for (int i = p; i <= t; i++) {
        if (t - i >= 0) ans += f(n - 1, t - i, p);
    }
    return dp[n][t][p] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    int T;
    cin >> T;
    while (T--) {
        int N, T, P;
        cin >> N >> T >> P;
        cout << f(N, T, P) << endl;
    }
    return 0;
}