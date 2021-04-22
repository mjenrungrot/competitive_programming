/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        524.cpp
#  Description:     UVa Online Judge - 524
=============================================================================*/
#include <cstdio>

int P[50], N;
int A[50];

void f(int nn, int bitmask) {
    if (nn == N) {
        for (int i = 0; i < N; i++) {
            if (i) printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (bitmask & (1 << i)) continue;
        if (P[i + 1 + A[nn - 1]]) {
            if (nn == N - 1 and !P[i + 1 + 1]) continue;
            A[nn] = i + 1;
            f(nn + 1, bitmask | (1 << i));
        }
    }
}

int main() {
    // freopen("in","r",stdin);
    int test = 0;
    bool enter = false;
    P[2] = P[3] = P[5] = P[7] = P[11] = P[13] = P[17] = P[19] = P[23] = P[29] =
        P[31] = 1;
    while (scanf("%d", &N) == 1) {
        if (enter) printf("\n");
        enter = true;

        printf("Case %d:\n", ++test);

        A[0] = 1;
        f(1, 1);
    }
    return 0;
}