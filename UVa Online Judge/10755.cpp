/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10755.cpp
#  Description:     UVa Online Judge - 10755
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long dp[30][30][30];
int A, B, C;

void add(int a, int b, int c, long long val) { dp[a][b][c] += val; }

long long f(int a1, int b1, int c1, int a2, int b2, int c2) {
    long long ans = dp[a2][b2][c2];
    ans -= dp[a1 - 1][b2][c2];
    ans -= dp[a2][b1 - 1][c2];
    ans -= dp[a2][b2][c1 - 1];
    ans += dp[a1 - 1][b1 - 1][c2];
    ans += dp[a1 - 1][b2][c1 - 1];
    ans += dp[a2][b1 - 1][c1 - 1];
    ans -= dp[a1 - 1][b1 - 1][c1 - 1];
    return ans;
}

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &A, &B, &C);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++) {
                    long long x;
                    scanf("%lld", &x);
                    add(i, j, k, x);
                }
        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++) {
                    dp[i][j][k] += dp[i][j][k - 1] + dp[i][j - 1][k] +
                                   dp[i - 1][j][k] - dp[i - 1][j - 1][k] -
                                   dp[i - 1][j][k - 1] - dp[i][j - 1][k - 1] +
                                   dp[i - 1][j - 1][k - 1];
                }

        long long ans = -1e18;
        for (int i1 = 1; i1 <= A; i1++)
            for (int i2 = i1; i2 <= A; i2++) {
                for (int j1 = 1; j1 <= B; j1++)
                    for (int j2 = j1; j2 <= B; j2++) {
                        for (int k1 = 1; k1 <= C; k1++)
                            for (int k2 = k1; k2 <= C; k2++) {
                                long long vv = f(i1, j1, k1, i2, j2, k2);
                                ans = max(ans, vv);
                            }
                    }
            }
        printf("%lld\n", ans);
        if (T) printf("\n");
    }
    return 0;
}