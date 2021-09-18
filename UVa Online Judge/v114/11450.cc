/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11450.cc
#  Description:     UVa 11450
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

const int MAXBUDGET = 205;
vvi dp(2, vi(MAXBUDGET, 0));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        fill(dp[0].begin(), dp[0].end(), 0);
        dp[0][0] = true;

        for (int i = 1; i <= M; i++) {
            int curr = i % 2;
            int prev = 1 - curr;

            fill(dp[curr].begin(), dp[curr].end(), 0);

            int K;
            cin >> K;
            for (int j = 1; j <= K; j++) {
                int x;
                cin >> x;

                for (int j = 0; j + x <= N; j++) {
                    if (dp[prev][j]) dp[curr][j + x] = true;
                }
            }
        }

        int ans = -1;
        for (int i = 0; i <= N; i++)
            if (dp[M % 2][i]) ans = max(ans, i);
        if (ans == -1)
            cout << "no solution" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}