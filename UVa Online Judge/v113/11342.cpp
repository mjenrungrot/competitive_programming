/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11342.cpp
#  Description:     UVa Online Judge - 11342
=============================================================================*/
#include <cmath>
#include <cstdio>

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);

        bool found = false;
        for (int i = 0; i * i <= N and !found; i++) {
            for (int j = i; i * i + j * j <= N and !found; j++) {
                int k = N - i * i - j * j;
                int vv = (int)floor(sqrt((double)(k)));
                if (vv * vv == k and vv >= j) {
                    printf("%d %d %d\n", i, j, vv);
                    found = true;
                }
            }
        }
        if (!found) printf("-1\n");
    }
    return 0;
}