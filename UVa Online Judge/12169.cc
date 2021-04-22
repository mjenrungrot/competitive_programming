/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12169.cc
#  Description:     UVa Online Judge - 12169
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int T, n[10005];

bool check(int a, int b) {
    for (int i = 1; i <= T; i++) {
        int next_val = (a * n[i] + b) % 10001;
        int next_next_val = (a * next_val + b) % 10001;
        if (i + 1 <= T and next_next_val != n[i + 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    if (T == 0) {
        return 0;
    } else if (T == 1) {
        cin >> n[0];
        cout << 0 << endl;
    }

    for (int i = 1; i <= T; i++) cin >> n[i];
    for (int a = 0; a <= 10000; a++)
        for (int b = 0; b <= 10000; b++) {
            if (check(a, b)) {
                for (int i = 1; i <= T; i++) {
                    int ans = (a * n[i] + b) % 10001;
                    cout << ans << endl;
                }
                return 0;
            }
        }

    return 0;
}