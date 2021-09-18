/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10487.cpp
#  Description:     UVa Online Judge - 10487
=============================================================================*/
#include <cstdio>

int N, M, A[1005];
int abs(int x) { return x < 0 ? -x : x; }

int main() {
    // freopen("in","r",stdin);
    int test = 0;
    while (scanf("%d", &N) == 1) {
        if (!N) break;
        printf("Case %d:\n", ++test);

        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
        scanf("%d", &M);
        for (int i = 1; i <= M; i++) {
            int xx, val, dif = 1e9;
            scanf("%d", &xx);
            for (int j = 1; j <= N; j++)
                for (int k = j + 1; k <= N; k++) {
                    if (abs(xx - A[j] - A[k]) < dif) {
                        dif = abs(xx - A[j] - A[k]);
                        val = A[j] + A[k];
                    }
                }
            printf("Closest sum to %d is %d.\n", xx, val);
        }
    }
    return 0;
}