/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12981.cc
#  Description:     UVa Online Judge - 12981
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int a[10], b[10];

int main() {
    int T;
    scanf("%d", &T);
    for (int _i = 1; _i <= T; _i++) {
        for (int i = 1; i <= 4; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= 4; i++) scanf("%d", &b[i]);

        bool check = false;
        for (int tt = 1; tt <= 4; tt++) {
            // cmp
            bool cmp = true;
            for (int i = 1; i <= 4; i++)
                if (a[i] != b[i]) {
                    cmp = false;
                    break;
                }
            if (cmp) {
                check = true;
                break;
            }

            // rotate
            int tmp;
            tmp = a[1];
            a[1] = a[2];
            a[2] = a[4];
            a[4] = a[3];
            a[3] = tmp;
        }

        printf("Case #%d: %s\n", _i, check ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}