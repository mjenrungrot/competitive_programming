/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12938.cc
#  Description:     UVa Online Judge - 12938
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int T;
string line, original;
int perfect_square[10005];

void precompute() {
    for (int i = 1; i < 100; i++) perfect_square[i * i] = true;
}

int main() {
    ios::sync_with_stdio(false);
    precompute();

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> line;
        original = line;

        int ans = 0, val;
        for (int digit = 0; digit < line.length(); digit++) {
            line = original;
            for (int num = (digit == 0 ? 1 : 0); num < 10; num++) {
                if ('0' + num == original[digit]) continue;
                line[digit] = '0' + num;

                val = 0;
                for (int j = 0; j < line.length(); j++) {
                    val *= 10;
                    val += line[j] - '0';
                }

                if (perfect_square[val]) {
                    ans++;
                }
            }
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}