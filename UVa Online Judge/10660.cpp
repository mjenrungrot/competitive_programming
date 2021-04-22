/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10660.cpp
#  Description:     UVa Online Judge - 10660
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int abs(int x) { return x < 0 ? -x : x; }
int A[10][10];

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) A[i][j] = 0;
        for (int i = 1; i <= N; i++) {
            int r, c, v;
            scanf("%d %d %d", &r, &c, &v);
            A[r][c] = v;
        }

        int ans = 2e9, x1, x2, x3, x4, x5;
        for (int a = 0; a < 21; a++)
            for (int b = a + 1; b < 22; b++)
                for (int c = b + 1; c < 23; c++)
                    for (int d = c + 1; d < 24; d++)
                        for (int e = d + 1; e < 25; e++) {
                            int sum = 0;
                            for (int rr = 0; rr < 5; rr++)
                                for (int cc = 0; cc < 5; cc++) {
                                    int pos = 5 * rr + cc;
                                    int v1 = (abs(pos / 5 - a / 5) +
                                              abs(pos % 5 - a % 5)) *
                                             A[rr][cc];
                                    int v2 = (abs(pos / 5 - b / 5) +
                                              abs(pos % 5 - b % 5)) *
                                             A[rr][cc];
                                    int v3 = (abs(pos / 5 - c / 5) +
                                              abs(pos % 5 - c % 5)) *
                                             A[rr][cc];
                                    int v4 = (abs(pos / 5 - d / 5) +
                                              abs(pos % 5 - d % 5)) *
                                             A[rr][cc];
                                    int v5 = (abs(pos / 5 - e / 5) +
                                              abs(pos % 5 - e % 5)) *
                                             A[rr][cc];

                                    int minval = min(min(v1, v2), min(v3, v4));
                                    minval = min(minval, v5);
                                    sum += minval;
                                }
                            if (sum < ans) {
                                ans = sum;
                                x1 = a;
                                x2 = b;
                                x3 = c;
                                x4 = d;
                                x5 = e;
                            }
                        }
        printf("%d %d %d %d %d\n", x1, x2, x3, x4, x5);
    }
    return 0;
}