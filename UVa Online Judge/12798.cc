/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12798.cc
#  Description:     UVa Online Judge - 12798
=============================================================================*/
#include <cstdio>

int N, M;
int X[105][105];

int main() {
    while (scanf("%d %d", &N, &M) == 2) {
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            bool check = true;
            for (int j = 1; j <= M; j++) {
                scanf("%d", &X[i][j]);
                if (X[i][j] == 0) check = false;
            }
            if (check) ans += 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}