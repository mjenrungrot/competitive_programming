/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11341.cc
#  Description:     UVa Online Judge - 11341
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int> > dp_scores(2, vector<int>(M + 1, -1));
        dp_scores[0][0] = 0;

        int ans = -1;
        for (int i = 1; i <= N; i++) {
            int curr_row = i % 2;
            int prev_row = 1 - curr_row;
            for (int j = 1; j <= M; j++) {
                int x;
                cin >> x;

                if (x < 5) continue;
                for (int k = M; k >= 0; k--) {
                    if (dp_scores[prev_row][k] == -1) continue;
                    if (k + j > M) continue;
                    dp_scores[curr_row][k + j] = max(
                        dp_scores[curr_row][k + j], dp_scores[prev_row][k] + x);
                    if (i == N) ans = max(ans, dp_scores[curr_row][k + j]);
                }
            }
            fill(dp_scores[prev_row].begin(), dp_scores[prev_row].end(), -1);
        }

        if (ans == -1) {
            cout << "Peter, you shouldn't have played billiard that much."
                 << endl;
        } else {
            double avg = (double)ans / N + 1e-9;
            double rounded_avg = round(avg * 100.0) / 100.0;
            cout << "Maximal possible average mark - ";
            cout << fixed << setprecision(2) << rounded_avg << "." << endl;
        }
    }
    return 0;
}