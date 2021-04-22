/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10503.cpp
#  Description:     UVa Online Judge - 10503
=============================================================================*/
#include <cstdio>

int A[20][2], N, M;
int B[2], C[2];
bool found;

void f(int n, int bitmask, int last) {
    if (found) return;

    if (n == 0) {
        for (int i = 1; i <= M; i++)
            for (int j = 0; j <= 1; j++)
                if (A[i][j] == last) {
                    f(n + 1, bitmask | (1 << i), A[i][!j]);
                }
    } else if (n < N) {
        for (int i = 1; i <= M; i++) {
            if ((1 << i) & bitmask) continue;
            for (int j = 0; j <= 1; j++)
                if (A[i][j] == last) {
                    f(n + 1, bitmask | (1 << i), A[i][!j]);
                }
        }
    } else {
        if (last == C[0]) {
            found = true;
            return;
        }
    }
}

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        if (not N) break;
        scanf("%d", &M);
        scanf("%d %d", &B[0], &B[1]);
        scanf("%d %d", &C[0], &C[1]);
        for (int i = 1; i <= M; i++) scanf("%d %d", &A[i][0], &A[i][1]);
        found = false;
        f(0, 0, B[1]);
        printf("%s\n", found ? "YES" : "NO");
    }
    return 0;
}