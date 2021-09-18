/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        639.cpp
#  Description:     UVa Online Judge - 639
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int N, NN;
char T[10][10], X[10][10];

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%s", T[i]);

        NN = N * N;
        int ans = 0, tmp_ans;
        for (int i = 0; i < (1 << NN); i++) {
            bool possible = true;
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++) X[j][k] = T[j][k];

            tmp_ans = 0;
            for (int j = 0; j < NN; j++) {
                if (i & (1 << j)) {
                    tmp_ans++;
                    int rr = j / N;
                    int cc = j % N;
                    if (T[rr][cc] == 'X') {
                        possible = false;
                        break;
                    }
                    X[rr][cc] = '*';
                }
            }

            // hori
            for (int j = 0; j < N; j++) {
                int prev = -1;
                for (int k = 0; k < N; k++) {
                    if (X[j][k] == '.')
                        continue;
                    else if (X[j][k] == '*') {
                        if (prev == -1)
                            prev = k;
                        else {
                            possible = false;
                            break;
                        }
                    } else if (X[j][k] == 'X')
                        prev = -1;
                }
            }
            if (not possible) continue;

            // vert
            for (int j = 0; j < N; j++) {
                int prev = -1;
                for (int k = 0; k < N; k++) {
                    if (X[k][j] == '.')
                        continue;
                    else if (X[k][j] == '*') {
                        if (prev == -1)
                            prev = k;
                        else {
                            possible = false;
                            break;
                        }
                    } else if (X[k][j] == 'X')
                        prev = -1;
                }
            }
            if (not possible) continue;

            ans = max(ans, tmp_ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}