/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10662.cpp
#  Description:     UVa Online Judge - 10662
=============================================================================*/
#include <algorithm>
#include <cassert>
#include <cstdio>
using namespace std;

int T, R, H, A[30], B[30], C[30];
int X[30][30], Y[30][30], Z[30][30];

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d %d %d", &T, &R, &H) == 3) {
        for (int i = 1; i <= T; i++) {
            scanf("%d", &A[i]);
            for (int j = 1; j <= R; j++) scanf("%d", &X[i][j]);
        }
        for (int i = 1; i <= R; i++) {
            scanf("%d", &B[i]);
            for (int j = 1; j <= H; j++) scanf("%d", &Y[i][j]);
        }
        for (int i = 1; i <= H; i++) {
            scanf("%d", &C[i]);
            for (int j = 1; j <= T; j++) scanf("%d", &Z[i][j]);
        }

        int ans = 1e9, a1, a2, a3;
        for (int i = 1; i <= T; i++)
            for (int j = 1; j <= R; j++)
                for (int k = 1; k <= H; k++) {
                    if (!X[i][j] and !Y[j][k] and !Z[k][i]) {
                        if (A[i] + B[j] + C[k] < ans) {
                            assert(A[i] <= 1e9);
                            assert(B[j] <= 1e9);
                            assert(C[k] <= 1e9);
                            ans = A[i] + B[j] + C[k];
                            a1 = i;
                            a2 = j;
                            a3 = k;
                        }
                    }
                }

        if (ans >= 1e9) {
            printf("Don't get married!\n");
        } else {
            printf("%d %d %d:%d\n", a1 - 1, a2 - 1, a3 - 1, ans);
        }
    }
    return 0;
}
