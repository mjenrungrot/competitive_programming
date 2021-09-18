/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11849.cpp
#  Description:     UVa Online Judge - 11849
=============================================================================*/
#include <cstdio>

int A[1000005], B[1000005];
int N, M;

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 and M == 0) break;
        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
        for (int i = 1; i <= M; i++) scanf("%d", &B[i]);

        int ans = 0, id1 = 1, id2 = 1;
        while (id1 <= N and id2 <= M) {
            if (A[id1] < B[id2]) {
                id1++;
            } else if (A[id1] > B[id2]) {
                id2++;
            } else {
                id1++;
                id2++;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}