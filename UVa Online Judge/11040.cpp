/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11040.cpp
#  Description:     UVa Online Judge - 11040
=============================================================================*/
#include <cstdio>
int A[10][10], B[20][20];

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= i; j++) scanf("%d", &A[i][j]);
        for (int i = 1; i <= 9; i += 2) B[9][i] = A[5][(i + 1) / 2];
        for (int i = 2; i <= 8; i += 2)
            B[9][i] = (A[4][i / 2] - B[9][i - 1] - B[9][i + 1]) / 2;
        for (int i = 8; i >= 1; i--)
            for (int j = 1; j <= i; j++)
                B[i][j] = B[i + 1][j] + B[i + 1][j + 1];
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= i; j++) {
                if (j > 1) printf(" ");
                printf("%d", B[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}