/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13095.cc
#  Description:     UVa Online Judge - 13095
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        vector<int> xs(N + 1);
        vector<vector<int> > qs(10, vector<int>(N + 1));
        for (int i = 1; i <= N; i++) {
            cin >> xs[i];
            for (int j = 0; j < 10; j++) qs[j][i] = qs[j][i - 1] + (xs[i] == j);
        }

        int Q;
        cin >> Q;
        for (int i = 1; i <= Q; i++) {
            int L, R;
            cin >> L >> R;

            int ans = 0;
            for (int j = 0; j < 10; j++) ans += (qs[j][R] - qs[j][L - 1] > 0);
            cout << ans << endl;
        }
    }
    return 0;
}