/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        435.cpp
#  Description:     UVa Online Judge - 435
=============================================================================*/
#include <cstdio>

int N, P[30], all;
int ans[30];

void f(int bitmask) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        if ((1 << i) & bitmask) sum += P[i];
    for (int i = 0; i < N; i++) {
        if ((1 << i) & bitmask) {
            if (2 * (sum - P[i]) <= all and 2 * sum > all) {
                ans[i]++;
            }
        }
    }
}

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);

        all = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &P[i]);
            all += P[i];
            ans[i] = 0;
        }

        for (int i = 0; i < (1 << N); i++) f(i);
        for (int i = 0; i < N; i++)
            printf("party %d has power index %d\n", i + 1, ans[i]);
        printf("\n");
    }
    return 0;
}