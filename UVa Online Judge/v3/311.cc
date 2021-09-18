/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        311.cc
#  Description:     UVa Online Judge - 311
=============================================================================*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int N = 6;
    vector<int> B(N);
    while (true) {
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        if (B[0] + B[1] + B[2] + B[3] + B[4] + B[5] == 0) break;

        int ans = 0;

        // 6x6
        ans += B[5];

        // 5x5
        ans += B[4];
        B[0] -= 11 * B[4];  // 11 spaces for 1x1

        // 4x4
        ans += B[3];
        B[1] -= 5 * B[3];  // 5 spaces for 2x2

        // 3x3
        if (B[2] % 4 == 0) {
            ans += B[2] / 4;
        } else if (B[2] % 4 == 3) {
            B[1] -= 1;
            B[0] -= 5;
            ans += B[2] / 4 + 1;
        } else if (B[2] % 4 == 2) {
            B[1] -= 3;
            B[0] -= 6;
            ans += B[2] / 4 + 1;
        } else if (B[2] % 4 == 1) {
            B[1] -= 5;
            B[0] -= 7;
            ans += B[2] / 4 + 1;
        }

        // 2x2
        if (B[1] > 0) {
            ans += (B[1] + 8) / 9;
            B[1] -= 9 * ((B[1] + 8) / 9);
        }

        if (B[1] < 0) B[0] -= (-B[1]) * 4;  // convert spaces for 1x1

        // 1x1
        if (B[0] > 0) ans += (B[0] + 35) / 36;

        cout << ans << endl;
    }
    return 0;
}