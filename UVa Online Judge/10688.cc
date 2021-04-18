/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10688.cc
#  Description:     UVa 10688
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
const int MAXN = 505;

int N, K;
long long dp[MAXN][MAXN];

long long f(int l, int r) {
    if (l >= r) return 0LL;

    if (dp[l][r] != -1) return dp[l][r];

    long long ans = INF_LL;
    for (int k = l; k <= r; k++) {
        long long val = f(l, k - 1) + (k + K) * (r - l + 1) + f(k + 1, r);
        ans = min(ans, val);
    }
    return dp[l][r] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        memset(dp, -1, sizeof(dp));

        long long ans = f(1, N);
        cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}