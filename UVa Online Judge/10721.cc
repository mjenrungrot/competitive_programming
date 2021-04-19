/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10721.cc
#  Description:     UVa 10721
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

const int MAXN = 52;

long long dp[MAXN][MAXN][MAXN];
long long f(int n, int k, int m) {
    if (n == 0 and k == 0) return 1;
    if (n < 0 or k < 0) return 0;

    if (dp[n][k][m] != -1) return dp[n][k][m];

    long long ans = 0LL;
    for (int i = 1; i <= m; i++) {
        ans += f(n - i, k - 1, m);
    }
    return dp[n][k][m] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, M;
    memset(dp, -1, sizeof(dp));
    while (cin >> N >> K >> M) {
        cout << f(N, K, M) << endl;
    }
    return 0;
}