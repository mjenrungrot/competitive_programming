/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11026.cc
#  Description:     UVa 11026
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
const int MAXN = 1005;

int N, K;
long long M;
int A[MAXN];

long long dp[MAXN][MAXN];

long long f(int n, int k) {
    if (n > N) {
        if (k > n)
            return 0;
        else
            return 1;
    }

    if (dp[n][k] != -1) return dp[n][k];
    long long ans = 0;
    ans += f(n + 1, k);
    ans += A[n] * f(n + 1, k + 1);

    return dp[n][k] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and K == 0) break;
        for (int i = 1; i <= N; i++) cin >> A[i];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * A[i]) % M;
            }
        }

        long long ans = 0LL;
        for (int i = 1; i <= N; i++) ans = max(ans, dp[N][i]);
        cout << ans << endl;
    }
    return 0;
}