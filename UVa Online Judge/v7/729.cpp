/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        729.cpp
#  Description:     UVa Online Judge - 729
=============================================================================*/
#include <cstdio>

char str[20];
int N, K;

void f(int now, int have) {
    if (now == N) {
        if (have < K) return;
        printf("%s\n", str);
        return;
    }

    str[now] = '0';
    f(now + 1, have);
    if (have < K) {
        str[now] = '1';
        f(now + 1, have + 1);
    }
}

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        str[N] = 0;
        f(0, 0);
        if (T) printf("\n");
    }
    return 0;
}