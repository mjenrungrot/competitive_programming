#include <bits/stdc++.h>
using namespace std;

const int MAXLIMIT = 303;
long long dp[MAXLIMIT][MAXLIMIT][MAXLIMIT];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < MAXLIMIT; i++)
    {
        dp[0][i][0] = 1; // (val, curr_coin_val, n_coins)
    }

    for (int val = 1; val < MAXLIMIT; val++)
    {
        int cumsum = 0;
        for (int curr_coin_val = 1; curr_coin_val < MAXLIMIT; curr_coin_val++)
        {
            for (int n_coins = 1; n_coins < MAXLIMIT; n_coins++)
            {
                if (val - curr_coin_val >= 0)
                    dp[val][curr_coin_val][n_coins] += dp[val - curr_coin_val][curr_coin_val][n_coins - 1];
                dp[val][curr_coin_val][n_coins] += dp[val][curr_coin_val - 1][n_coins];
            }
        }
    }

    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        string token;
        istringstream iss(line);
        while (getline(iss, token, ' '))
        {
            nums.push_back(stoi(token));
        }

        long long ans = 0;
        int L, R;
        if (nums.size() == 1)
        {
            L = 0;
            R = nums[0];
        }
        else if (nums.size() == 2)
        {
            L = 0;
            R = min(nums[1], nums[0]);
        }
        else
        {
            L = min(nums[1], MAXLIMIT - 1);
            R = min(nums[2], MAXLIMIT - 1);
        }
        ans = 0;
        for (int i = L; i <= R; i++)
        {
            ans += dp[nums[0]][MAXLIMIT - 1][i];
        }
        cout << ans << endl;
    }
    return 0;
}