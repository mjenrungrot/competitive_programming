/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1230.cpp
#  Description:     UVa Online Judge - 1230
=============================================================================*/
#include <cstdio>

int T, x, n, y;

int pow(int base, int expo) {
    if (expo == 0) return 1;

    if (expo & 1)
        return (base * pow(base, expo - 1)) % n;
    else {
        int vv = pow(base, expo / 2) % n;
        return (vv * vv) % n;
    }
}

int main() {
    // freopen("in","r",stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &x, &y, &n);
        printf("%d\n", pow(x, y));
    }
    return 0;
}