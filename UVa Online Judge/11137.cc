#include <bits/stdc++.h>
using namespace std;

const int MAXLIMIT = 10005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> coins;
    int curr = 1;
    while (curr * curr * curr <= MAXLIMIT)
    {
        coins.push_back(curr * curr * curr);
        curr++;
    }

    vector<vector<long long>> dp(MAXLIMIT, vector<long long>(coins.size()));
    for (int i = 0; i < coins.size(); i++)
    {
        dp[0][i] = 1;
    }

    for (int val = 1; val < MAXLIMIT; val++)
    {
        for (int coin_idx = 0; coin_idx < coins.size(); coin_idx++)
        {
            if (val - coins[coin_idx] >= 0 and dp[val - coins[coin_idx]][coin_idx])
                dp[val][coin_idx] += dp[val - coins[coin_idx]][coin_idx];

            if (coin_idx - 1 >= 0)
                dp[val][coin_idx] += dp[val][coin_idx - 1];
        }
    }

    int N;
    while (cin >> N)
    {
        cout << dp[N][coins.size() - 1] << endl;
    }
    return 0;
}