/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10003.cc
#  Description:     UVa Online Judge - 10003
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
const int INF = 1e9;
int dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, N;
    while (cin >> L) {
        if (L == 0) break;
        cin >> N;

        vector<int> A(N + 2);
        A[0] = 0;
        A[N + 1] = L;
        for (int i = 1; i <= N; i++) cin >> A[i];

        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                dp[i][j] = INF;
            }

        for (int d = 2; d <= A.size(); d++) {
            for (int start = 0; start < A.size(); start++) {
                int end = start + d - 1;
                if (end >= A.size()) break;
                if (d == 2) {
                    dp[start][end] = 0;
                } else {
                    for (int k = start + 1; k <= end - 1; k++) {
                        dp[start][end] =
                            min(dp[start][end],
                                dp[start][k] + dp[k][end] + A[end] - A[start]);
                    }
                }
            }
        }
        cout << "The minimum cutting is " << dp[0][N + 1] << "." << endl;
    }
    return 0;
}