/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        725.cpp
#  Description:     UVa Online Judge - 725
=============================================================================*/
#include <cstdio>
#include <vector>
using namespace std;

int check(int a, int b) {
    int cc[20];
    for (int i = 0; i <= 9; i++) cc[i] = 0;

    if (a < 10000 or b < 10000) cc[0] = true;

    while (a) {
        cc[a % 10] = true;
        a /= 10;
    }
    while (b) {
        cc[b % 10] = true;
        b /= 10;
    }

    for (int i = 0; i <= 9; i++)
        if (cc[i] == 0) return false;
    return true;
}

int main() {
    // freopen("in","r",stdin);
    int N, space = false;
    while (scanf("%d", &N) == 1) {
        if (!N) break;

        if (space) printf("\n");
        space = true;

        bool have = false;
        for (int i = 1000; i < 100000; i++) {
            if (i * N < 100000 and i * N > 999) {
                if (!check(i * N, i)) continue;
                printf("%05d / %05d = %d\n", i * N, i, N);
                have = true;
            }
        }
        if (not have) printf("There are no solutions for %d.\n", N);
    }
    return 0;
}
