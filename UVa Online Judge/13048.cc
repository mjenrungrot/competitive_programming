/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13048.cc
#  Description:     UVa Online Judge - 13048
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

string segment;

int main() {
    int T;
    scanf("%d", &T);
    for (int _i = 1; _i <= T; _i++) {
        printf("Case %d: ", _i);

        cin >> segment;
        int ans = 0;
        int length = segment.size();
        for (int i = 0; i < length; i++) {
            if (segment[i] != '-') continue;
            if (i + 1 < length and segment[i + 1] == 'B') continue;
            if (i + 2 < length and segment[i + 2] == 'B') continue;
            if (i + 1 < length and segment[i + 1] == 'S') continue;
            if (i - 1 >= 0 and segment[i - 1] == 'S') continue;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}