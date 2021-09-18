/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10943.cc
#  Description:     UVa 10943
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

const int MAXN = 105;
const int MAXK = 105;
long long dp[MAXN][MAXK];

long long f(int n, int k) {
    if (k == 0) {
        return n == 0;
    }

    if (dp[n][k] != -1) return dp[n][k];

    long long ans = 0LL;
    for (int i = 0; i <= n; i++) ans = (ans + f(n - i, k - 1)) % 1000000LL;
    return dp[n][k] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    memset(dp, -1, sizeof(dp));
    while (cin >> N >> K) {
        if (N == 0 and K == 0) break;
        cout << f(N, K) << endl;
    }

    return 0;
}