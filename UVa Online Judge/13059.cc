/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13059.cc
#  Description:     UVa Online Judge - 13059
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

long long N;

int main() {
    while (cin >> N) {
        long long ans = 0;

        while (N > 1) {
            if (N % 2 == 0) {
                ans += (N / 2);
                N /= 2;
            } else {
                ans += N / 2;
                N = (N + 1) / 2;
            }
        }

        cout << ans << endl;
    }
    return 0;
}