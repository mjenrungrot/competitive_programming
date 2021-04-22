/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11236.cpp
#  Description:     UVa Online Judge - 11236
=============================================================================*/
#include <cstdio>

const int MAXVAL = 2000;
int main() {
    // freopen("out","w",stdout);
    for (int a = 1; a < MAXVAL; a++)
        for (int b = a; b < MAXVAL; b++) {
            if (a + b > MAXVAL) break;
            for (int c = b; c < MAXVAL; c++) {
                if (a + b + c > MAXVAL) break;

                int vv = (a + b + c) * 1000000LL;
                int vv2 = (a * b * c - 1000000L);
                if (vv2 <= 0) continue;
                if (vv % vv2 != 0) continue;
                int d = vv / vv2;

                if (d < c or d < b or d < a) break;
                if (a + b + c + d > MAXVAL) continue;
                printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", a / 100, a % 100,
                       b / 100, b % 100, c / 100, c % 100, d / 100, d % 100);
            }
        }
    return 0;
}