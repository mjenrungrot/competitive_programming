/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11658.cc
#  Description:     UVa Online Judge - 11658
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_LIMIT = 10005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, x;
    while (cin >> N >> x) {
        if (N == 0) break;

        vector<int> percentiles_int(N + 1);
        vector<bool> reachable(MAX_LIMIT, false);
        reachable[0] = true;

        for (int i = 1; i <= N; i++) {
            double tmp;
            cin >> tmp;
            percentiles_int[i] = round(tmp * 100.0);

            if (i == x) continue;
            for (int j = MAX_LIMIT - 1; j >= 0; j--) {
                if (not reachable[j]) continue;
                if (j + percentiles_int[i] >= MAX_LIMIT) continue;
                reachable[j + percentiles_int[i]] = true;
            }
        }

        double ans = 0.0;
        for (int i = 0; i < MAX_LIMIT; i++) {
            if (not reachable[i]) continue;
            if (i + percentiles_int[x] > 5000) {
                int own = percentiles_int[x];
                int total = i + percentiles_int[x];
                ans = max(ans, (double)own / total * 100.0);
            }
        }

        double rounded_ans = round(ans * 100.0) / 100.0;
        cout << fixed << setprecision(2) << rounded_ans << endl;
    }
    return 0;
}