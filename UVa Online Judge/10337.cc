/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10337.cc
#  Description:     UVa 10337
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
const int MAXN = 1005;

vvi A(10, vi(MAXN + 1));
vvi dp(2, vi(MAXN + 1, INF_INT));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        N /= 100;

        for (int i = 9; i >= 0; i--)
            for (int j = 1; j <= N; j++) cin >> A[i][j];

        dp[0][0] = 0;

        for (int n = 1; n <= N; n++) {
            int curr = n % 2;
            int prev = 1 - curr;

            fill(dp[curr].begin(), dp[curr].end(), INF_INT);

            for (int j = 0; j <= 9; j++) {
                // climb
                if (j > 0) {
                    dp[curr][j] =
                        min(dp[curr][j], dp[prev][j - 1] + 60 - A[j - 1][n]);
                }

                // hold
                dp[curr][j] = min(dp[curr][j], dp[prev][j] + 30 - A[j][n]);

                // sink
                if (j < 9) {
                    dp[curr][j] =
                        min(dp[curr][j], dp[prev][j + 1] + 20 - A[j + 1][n]);
                }
            }
        }
        cout << dp[N % 2][0] << endl;
        cout << endl;
    }
    return 0;
}