/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12405.cc
#  Description:     UVa Online Judge - 12405
=============================================================================*/
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int N;
        string S;
        cin >> N >> S;

        int ans = 0;
        int prev = -100;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '.') {
                if (abs(i - prev) <= 1)
                    continue;
                else {
                    ans++;
                    prev = i + 1;
                }
            }
        }
        cout << "Case " << tt << ": " << ans << endl;
    }
    return 0;
}