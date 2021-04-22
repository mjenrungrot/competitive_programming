/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11565.cpp
#  Description:     UVa Online Judge - 11565
=============================================================================*/
#include <cstdio>

int A, B, C;

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &A, &B, &C);

        bool found = false;
        for (int x = -100; x <= 100 and !found; x++)
            for (int y = -100; y <= 100 and !found; y++)
                for (int z = -100; z <= 100 and !found; z++) {
                    if (x == y or x == z or y == z) continue;
                    if (x + y + z == A and x * y * z == B and
                        x * x + y * y + z * z == C) {
                        printf("%d %d %d\n", x, y, z);
                        found = true;
                    }
                }
        if (not found) printf("No solution.\n");
    }
    return 0;
}