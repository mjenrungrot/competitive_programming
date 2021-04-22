/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1105.cc
#  Description:     UVa Online Judge - 1105
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_case = 0;
    int dx, dy, n, q;
    while (cin >> dx >> dy >> n >> q) {
        if (dx == 0) break;

        int size_rotated = dx + dy + 1;
        vector<vector<int> > A(size_rotated, vector<int>(size_rotated));
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            int new_y = y - x + dx;  // y in [1,dy]; x-dx in [1-dx, 0]; y - x +
                                     // dx in [1,dx+dy-1]
            int new_x = y + x;       // x+y [2, dx+dy]
            A[new_y][new_x]++;
        }

        for (int i = 1; i < size_rotated; i++)
            for (int j = 1; j < size_rotated; j++) {
                A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
            }

        cout << "Case " << ++n_case << ":" << endl;
        for (int i = 1; i <= q; i++) {
            int limit;
            cin >> limit;

            int ans = -1;
            int best_r = -1, best_c = -1;
            for (int r = 1; r <= dy; r++)
                for (int c = 1; c <= dx; c++) {
                    int new_r = r - c + dx;
                    int new_c = r + c;

                    int upper_row = max(new_r - limit, 1);
                    int lower_row = min(new_r + limit, dx + dy);
                    int left_col = max(new_c - limit, 1);
                    int right_col = min(new_c + limit, dx + dy);
                    int count = A[lower_row][right_col] -
                                A[lower_row][left_col - 1] -
                                A[upper_row - 1][right_col] +
                                A[upper_row - 1][left_col - 1];

                    if (count > ans) {
                        ans = count;
                        best_r = r;
                        best_c = c;
                    }
                }
            cout << ans << " (" << best_c << "," << best_r << ")" << endl;
        }
    }
    return 0;
}