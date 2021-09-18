/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11933.cpp
#  Description:     UVa Online Judge - 11933
=============================================================================*/
#include <cstdio>
int main() {
    int N;
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        if (!N) break;
        int A = 0, B = 0, cc = 0;
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & N) {
                cc++;
                if (cc % 2 == 1)
                    A += (1 << i);
                else
                    B += (1 << i);
            }
        }
        printf("%d %d\n", A, B);
    }
    return 0;
}