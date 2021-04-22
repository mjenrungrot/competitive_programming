/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1261.cc
#  Description:     UVa Online Judge - 1261
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
int dp[MAXN][MAXN];
bool issame[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string line;
        cin >> line;

        int N = line.length();
        memset(dp, 0, sizeof(dp));
        memset(issame, 0, sizeof(issame));

        for (int i = 0; i < N; i++) {
            int curr = i + 1;
            issame[i][i] = true;
            while (curr < N and line[curr] == line[i]) {
                issame[i][curr++] = true;
            }

            if (i - 1 < 0 or line[i - 1] != line[i]) {
                dp[i][curr - 1] = (i != curr - 1);
            }
        }

        for (int d = 1; d <= N; d++) {
            for (int start = 0; start < N; start++) {
                int end = start + d - 1;
                if (end >= N) break;
                if (start - 1 >= 0 and line[start] == line[start - 1]) continue;
                if (end + 1 < line.length() and line[end] == line[end + 1])
                    continue;

                for (int k1 = start; k1 < end; k1++) {
                    for (int k2 = k1 + 1; k2 <= end; k2++) {
                        // popping group length > 1
                        if (d - (k2 - k1 + 1) == 1) continue;

                        // if left group > 1, must be able to do it
                        if (k1 - start > 1 and not dp[start][k1 - 1]) continue;

                        // if right group > 1, must be able to do it
                        if (end - k2 > 1 and not dp[k2 + 1][end]) continue;

                        // if left group = 1 and right group = 1, must be able
                        // to combine
                        if (k1 - start == 1 and end - k2 == 1 and
                            line[k1] != line[k2])
                            continue;

                        // the middle group must be able to do it
                        if (not dp[k1][k2]) continue;
                        dp[start][end] = true;
                        break;
                    }
                    if (dp[start][end]) break;
                }
            }
        }
        cout << dp[0][N - 1] << endl;
    }
    return 0;
}