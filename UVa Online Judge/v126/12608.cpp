/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12608.cpp
#  Description:     UVa Online Judge - 12608
=============================================================================*/
#include <cassert>
#include <cstdio>

int N, W;
int A[2000][2];

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &W, &N);
        for (int i = 1; i <= N; i++) scanf("%d %d", &A[i][0], &A[i][1]);

        int ans = 0, id_now = 1, weight_now = 0, pos_now = 0;
        while (id_now <= N) {
            assert(weight_now < W);

            ans += (A[id_now][0] - pos_now);
            pos_now = A[id_now][0];
            if (A[id_now][1] > W) {
                assert(false);
                ans += pos_now;
                pos_now = 0;
                weight_now = 0;
                id_now++;
            } else if (weight_now + A[id_now][1] > W) {
                ans += pos_now;
                pos_now = 0;
                weight_now = 0;
            } else if (weight_now + A[id_now][1] < W) {
                weight_now += A[id_now][1];
                id_now++;
                continue;
            } else {
                weight_now += A[id_now][1];
                ans += pos_now;
                weight_now = 0;
                pos_now = 0;
                id_now++;
            }
        }
        if (pos_now != 0) ans += pos_now;
        printf("%d\n", ans);
    }
    return 0;
}