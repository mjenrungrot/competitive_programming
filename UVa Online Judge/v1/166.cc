/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        166.cc
#  Description:     UVa Online Judge - 166
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_LIMIT = 505;
vector<int> coins = {5, 10, 20, 50, 100, 200};
vector<int> coin_counts(coins.size());

int greedy_change(int val) {
    int ans = 0;
    for (int i = coins.size() - 1; i >= 0; i--) {
        ans += val / coins[i];
        val %= coins[i];
    }
    return ans;
}

int dp(int curr_val, int coin_idx, vector<vector<int>> &memo) {
    if (coin_idx == coins.size()) {
        if (curr_val == 0)
            return 0;
        else if (curr_val < 0)
            return greedy_change(-curr_val);
        else
            return INF;
    }
    if (curr_val < 0) {
        return greedy_change(-curr_val);
    }

    if (memo[coin_idx][curr_val] != -1) {
        return memo[coin_idx][curr_val];
    }

    int ans = INF;
    for (int counter = 0; counter <= coin_counts[coin_idx]; counter++) {
        ans = min(ans,
                  dp(curr_val - counter * coins[coin_idx], coin_idx + 1, memo) +
                      counter);
    }
    return memo[coin_idx][curr_val] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        for (int i = 0; i < coins.size(); i++) cin >> coin_counts[i];

        if (all_of(coin_counts.begin(), coin_counts.end(),
                   [](int x) { return x == 0; }))
            break;

        double val;
        cin >> val;

        int n_cents = int(round(val * 100.0));
        vector<vector<int>> memo(coins.size(), vector<int>(n_cents + 1, -1));
        int ans = dp(n_cents, 0, memo);
        cout << setw(3) << ans << endl;
    }

    return 0;
}