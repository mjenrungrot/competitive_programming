/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12614.cc
#  Description:     UVa Online Judge - 12614
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int T;
int N;
int x, ans;

int main() {
    scanf("%d", &T);
    for (int _i = 1; _i <= T; _i++) {
        scanf("%d", &N);
        ans = -1e9;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &x);
            ans = max(ans, x);
        }
        printf("Case %d: %d\n", _i, ans);
    }
    return 0;
}