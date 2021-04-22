/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11003.cc
#  Description:     UVa Online Judge - 11003
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int MAXLIMIT = 6005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        if (N == 0) break;

        vector<ii> A(N);
        for (int i = 0; i < N; i++) {
            int weight, load;
            cin >> weight >> load;
            A[i] = ii(weight, load);
        }

        vector<int> dp(MAXLIMIT, -1);
        dp[0] = 0;

        int ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = A[i].second - 1; j >= 0; j--) {
                if (dp[j] == -1) continue;
                dp[j + A[i].first] = max(dp[j + A[i].first], dp[j] + 1);
                ans = max(ans, dp[j + A[i].first]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}