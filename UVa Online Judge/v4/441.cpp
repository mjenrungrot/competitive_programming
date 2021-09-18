/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        441.cpp
#  Description:     UVa Online Judge - 441
=============================================================================*/
#include <cstdio>

int A[60], N;

int main() {
    // freopen("in","r",stdin);
    bool enter = false;
    while (scanf("%d", &N) == 1) {
        if (!N) break;
        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

        if (enter) printf("\n");
        enter = true;

        for (int i = 1; i <= N - 5; i++)
            for (int j = i + 1; j <= N - 4; j++)
                for (int k = j + 1; k <= N - 3; k++)
                    for (int l = k + 1; l <= N - 2; l++)
                        for (int m = l + 1; m <= N - 1; m++)
                            for (int n = m + 1; n <= N; n++) {
                                printf("%d %d %d %d %d %d\n", A[i], A[j], A[k],
                                       A[l], A[m], A[n]);
                            }
    }
    return 0;
}