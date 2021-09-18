/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11230.cc
#  Description:     UVa Online Judge - 11230
=============================================================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, R, C;
    while (cin >> N >> M >> R >> C) {
        if (N == 0 and M == 0 and R == 0 and C == 0) break;

        vector<string> curr(N, string(M, '0')), target(N);
        for (int i = 0; i < N; i++) {
            cin >> target[i];
        }

        int ans = 0;
        for (int i = 0; i < N - R + 1; i++) {
            for (int j = 0; j < M - C + 1; j++) {
                if (curr[i][j] == target[i][j]) continue;

                ans++;
                for (int rr = i; rr < i + R; rr++)
                    for (int cc = j; cc < j + C; cc++) {
                        curr[rr][cc] = (curr[rr][cc] == '0' ? '1' : '0');
                    }
            }
        }

        bool check = true;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (curr[i][j] != target[i][j]) {
                    check = false;
                    break;
                }
            }

        if (not check)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}