/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10344.cpp
#  Description:     UVa Online Judge - 10344
=============================================================================*/
#include <cstdio>
#include <cstring>

bool found;
int A[10], pass[10];

void f(int now, int val) {
    if (now == 5) {
        if (val == 23) found = true;
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (pass[i]) continue;

        pass[i] = true;
        f(now + 1, val + A[i]);

        f(now + 1, val - A[i]);

        f(now + 1, val * A[i]);
        pass[i] = false;
    }
}

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4]) == 5) {
        if (A[0] == 0) break;

        found = false;
        for (int i = 0; i < 5; i++) {
            memset(pass, 0, sizeof pass);
            pass[i] = true;
            f(1, A[i]);
        }
        printf("%s\n", found ? "Possible" : "Impossible");
    }
    return 0;
}