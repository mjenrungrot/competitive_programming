/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12337.cc
#  Description:     UVa Online Judge - 12337
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int T;
char A[105][105];
string line;

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> line;

        int N = line.length();
        int ans = INF;
        for (int r = 2; r <= N; r++) {
            if (N % r != 0) continue;
            int c = N / r;
            if (c == 1) continue;
            memset(A, -1, sizeof(A));

            int xx = 1, yy = 1, di = 0, curr = 0;
            A[yy][xx] = line[curr++];
            while (curr < N) {
                if (1 <= yy + dy[di] and yy + dy[di] <= r and
                    1 <= xx + dx[di] and xx + dx[di] <= c and
                    A[yy + dy[di]][xx + dx[di]] == -1) {
                    yy += dy[di];
                    xx += dx[di];
                    A[yy][xx] = line[curr++];
                } else {
                    di = (di + 1) % 4;
                }
            }

            bool beatiful = true;
            for (int i = 1; i <= c and beatiful; i++) {
                for (int j = 2; j <= r; j++) {
                    if (A[j][i] == A[1][i])
                        continue;
                    else {
                        beatiful = false;
                        break;
                    }
                }
            }
            if (beatiful) ans = min(ans, r + c);
        }
        if (ans == INF) ans = -1;
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}