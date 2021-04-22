/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10855.cpp
#  Description:     UVa Online Judge - 10855
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

char A[1000][1000], B[1000][1000], C[1000][1000];
int N1, N2;

int f(int y, int x) {
    for (int i = y, k = 1; i <= y + N2 - 1; i++, k++)
        for (int j = x, l = 1; j <= x + N2 - 1; j++, l++)
            if (B[k][l] != A[i][j]) return false;
    return true;
}

void rotate() {
    for (int i = 1; i <= N2; i++)
        for (int j = 1; j <= N2; j++) C[j][N2 - i + 1] = B[i][j];
    for (int i = 1; i <= N2; i++)
        for (int j = 1; j <= N2; j++) B[i][j] = C[i][j];
}

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d %d", &N1, &N2) == 2) {
        if (!N1) break;
        for (int i = 1; i <= N1; i++) scanf("%s", &A[i][1]);
        for (int i = 1; i <= N2; i++) scanf("%s", &B[i][1]);

        for (int k = 0; k < 4; k++) {
            if (k) printf(" ");
            int ans = 0;
            for (int i = 1; i <= N1 - N2 + 1; i++)
                for (int j = 1; j <= N1 - N2 + 1; j++) ans += f(i, j);
            rotate();
            printf("%d", ans);
        }
        printf("\n");
    }
    return 0;
}