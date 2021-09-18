/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11571.cpp
#  Description:     UVa Online Judge - 11571
=============================================================================*/
#include <cmath>
#include <cstdio>
long long A, B, C;

long long abs(int x) { return x < 0 ? -x : x; }

int main() {
    freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &A, &B, &C);
        bool found = false;
        for (int x = -1820000; x <= 1820000 and !found; x++) {
            if (x and B % abs(x) == 0) {
                long long v1 = A - x;
                long long v2 = B / x;
                long long v3 = C - x * x;
                if (v3 >= 0 and v1 * v1 - 2 * v2 == v3) {
                    printf("%lld %lld %lld\n", x, v1, v2);
                    found = true;
                }
            }
        }
        if (not found) printf("No solution.\n");
    }
    return 0;
}