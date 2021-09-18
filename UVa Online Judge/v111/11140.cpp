/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11140.cpp
#  Description:     UVa Online Judge - 11140
=============================================================================*/
#include <cstdio>
#include <cstring>

const int MAXR = 200;
const int MAXC = 200;

int R, C, N, R2, C2, rbegin, cbegin;
char T[200][200], T2[200][200];

int equal(int rr1, int cc1, int rr2, int cc2) {
    if (T2[rr2][cc2] == '.') return true;
    if (T[rr1][cc1] == T2[rr2][cc2])
        return true;
    else
        return false;
}

int check(int r, int c) {
    bool pass = true;
    for (int i = r, k = 1; i <= r + R2 - 1; i++, k++)
        for (int j = c, l = 1; j <= c + C2 - 1; j++, l++)
            if (not equal(i, j, k, l)) {
                return false;
            }
    return true;
}

int main() {
    // freopen("in","r",stdin);
    bool line = false;
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        scanf("%d %d %d", &R, &C, &N);
        memset(T, 0, sizeof T);
        for (int i = 1; i <= R; i++) scanf("%s", &T[100 + i][100]);
        for (int i = 0; i < MAXR; i++)
            for (int j = 0; j < MAXC; j++)
                if (T[i][j] == 0) T[i][j] = '.';

        for (int i = 1; i <= N; i++) {
            scanf("%d %d", &R2, &C2);
            for (int j = 1; j <= R2; j++) scanf("%s", &T2[j][1]);

            bool pass = false;
            for (int k = 1; k < MAXR; k++)
                for (int m = 1; m < MAXC; m++)
                    if (check(k, m)) {
                        pass = true;
                        break;
                    }
            if (pass)
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");
    }
    return 0;
}