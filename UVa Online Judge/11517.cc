#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXLIMIT = 20005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int price;
        cin >> price;

        int N;
        cin >> N;

        vector<int> dp(MAXLIMIT, INF);
        dp[0] = 0;
        int ans_val = -1, ans_n_coins = -1;

        for (int i = 0; i < N; i++)
        {
            int coin;
            cin >> coin;
            for (int val = MAXLIMIT - 1; val >= coin; val--)
            {
                dp[val] = min(dp[val], dp[val - coin] + 1);

                if (val >= price and dp[val] < INF)
                {
                    if (ans_val == -1 or val < ans_val or (val == ans_val and dp[val] < ans_n_coins))
                    {
                        ans_val = val;
                        ans_n_coins = dp[val];
                    }
                }
            }
        }
        cout << ans_val << " " << ans_n_coins << endl;
    }
    return 0;
}