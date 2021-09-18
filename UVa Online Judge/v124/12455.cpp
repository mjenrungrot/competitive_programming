/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12455.cpp
#  Description:     UVa Online Judge - 12455
=============================================================================*/
#include <cstdio>

int A[30];

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, P;
        scanf("%d %d", &N, &P);
        for (int i = 0; i < P; i++) scanf("%d", &A[i]);

        for (int i = 0; i < (1 << P); i++) {
            int tmp = 0;
            for (int j = 0; j < P; j++)
                if ((1 << j) & i) tmp += A[j];
            if (tmp == N) goto end;
        }
        printf("NO\n");
        continue;

    end:
        printf("YES\n");
    }
    return 0;
}