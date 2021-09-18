/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        147.cc
#  Description:     UVa Online Judge - 147
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_LIMIT = 30005;
vector<int> coins = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<long long>> dp(coins.size(), vector<long long>(MAX_LIMIT, 0));
    for (int coin_idx = 0; coin_idx < coins.size(); coin_idx++) {
        dp[coin_idx][0] = 1;
    }

    for (int val = 5; val < MAX_LIMIT; val += 5) {
        for (int coin_idx = 0; coin_idx < coins.size(); coin_idx++) {
            if (val - coins[coin_idx] >= 0)
                dp[coin_idx][val] += dp[coin_idx][val - coins[coin_idx]];
            if (coin_idx - 1 >= 0) dp[coin_idx][val] += dp[coin_idx - 1][val];
        }
    }

    double val;
    while (cin >> val) {
        if (fabs(val) < 1e-6) break;

        int n_cents = int(round(val * 100.0));
        long long ans = dp[coins.size() - 1][n_cents];
        cout << setw(6) << fixed << setprecision(2) << val << setw(17) << ans
             << endl;
    }
    return 0;
}