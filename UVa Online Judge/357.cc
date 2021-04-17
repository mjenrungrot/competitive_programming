#include <bits/stdc++.h>
using namespace std;

const int MAXLIMIT = 30005;
const int INF = 1e9;
vector<int> coins = {1, 5, 10, 25, 50};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<long long>> memo(MAXLIMIT, vector<long long>(coins.size() + 1));
    for (int i = 0; i < coins.size(); i++)
        memo[0][i] = 1;

    for (int val = 1; val < MAXLIMIT; val++)
    {
        for (int coin_idx = 0; coin_idx < coins.size(); coin_idx++)
        {
            if (val - coins[coin_idx] >= 0 and memo[val - coins[coin_idx]][coin_idx])
            {
                memo[val][coin_idx] += memo[val - coins[coin_idx]][coin_idx];
            }
            if (coin_idx - 1 >= 0)
            {
                memo[val][coin_idx] += memo[val][coin_idx - 1];
            }
        }
    }

    int N;
    while (cin >> N)
    {
        long long ans = 0;
        for (int coin_idx = 0; coin_idx < coins.size(); coin_idx++)
            ans = max(ans, memo[N][coin_idx]);

        if (ans > 1)
        {
            cout << "There are " << ans << " ways to produce " << N << " cents change." << endl;
        }
        else if (ans == 1)
        {
            cout << "There is only " << ans << " way to produce " << N << " cents change." << endl;
        }
    }
    return 0;
}