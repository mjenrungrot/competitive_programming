/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11717.cpp
#  Description:     UVa Online Judge - 11717
=============================================================================*/
#include <cstdio>

const int MAXN = 1005;
int N, I, K, A[MAXN];

void run() {
    scanf("%d %d %d", &N, &I, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

    int now = 0, n_ignored = 0, n_inactive = 0;
    bool isActive = true;
    for (int i = 1; i <= N; i++) {
        int diff = A[i] - now;
        if (isActive) {
            if (diff < I) {
                now = A[i];
            } else {
                n_inactive++;
                now = A[i];
                isActive = false;
            }
        } else {
            if (diff < K) {
                n_ignored++;
            } else {
                isActive = true;
                if (diff < K + I) {
                    now = A[i];
                } else {
                    n_inactive++;
                    now = A[i];
                    isActive = false;
                }
            }
        }

        // printf("[%d] : %d %d\n",i,n_inactive,n_ignored);
    }
    printf("%d %d\n", n_inactive, n_ignored);
}

int main() {
    // freopen("in","r",stdin);

    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case %d: ", i);
        run();
    }
    return 0;
}