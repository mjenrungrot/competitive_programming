/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11078.cpp
#  Description:     UVa Online Judge - 11078
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, xx, maxval = -1e9, maxans = -1e9;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &xx);
            maxans = max(maxans, maxval - xx);
            maxval = max(maxval, xx);
        }
        printf("%d\n", maxans);
    }
    return 0;
}