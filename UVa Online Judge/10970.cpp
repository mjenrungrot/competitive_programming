/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10970.cpp
#  Description:     UVa Online Judge - 10970
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int dp[305][305];

int f(int r, int c) {
    if (r == 1 and c == 1) return 0;
    if (dp[r][c]) return dp[r][c];

    if (r < c) return dp[r][c] = f(c, r);

    int vv = 1e9;
    for (int i = 1; i <= c - 1; i++) vv = min(vv, f(r, i) + f(r, c - i) + 1);
    for (int i = 1; i <= r - 1; i++) vv = min(vv, f(i, c) + f(r - i, c) + 1);
    return dp[r][c] = vv;
}

int main() {
    // freopen("in","r",stdin);
    int x = f(300, 300);

    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        if (N < M) swap(N, M);
        printf("%d\n", dp[N][M]);
    }
    return 0;
}