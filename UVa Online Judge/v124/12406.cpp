/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12406.cpp
#  Description:     UVa Online Judge - 12406
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    // freopen("in","r",stdin);
    int T, test = 0;
    scanf("%d", &T);
    while (T--) {
        int p, q;
        scanf("%d %d", &p, &q);

        long long minval = 1e18, maxval = -1e18;
        int qq = 1 << q;
        for (int i = 0; i < (1 << p); i++) {
            long long val = 0LL;
            for (int j = 0; j < p; j++) {
                val *= 10LL;
                if (i & (1 << j))
                    val += 2LL;
                else
                    val += 1LL;
            }
            if (val % qq == 0) {
                minval = min(minval, val);
                maxval = max(maxval, val);
            }
        }

        if (minval == maxval)
            printf("Case %d: %lld\n", ++test, minval);
        else if (minval == 1e18)
            printf("Case %d: impossible\n", ++test);
        else
            printf("Case %d: %lld %lld\n", ++test, minval, maxval);
    }
    return 0;
}