#include <bits/stdc++.h>
using namespace std;

const int MAXLIMIT = 100005;
const int N_COINS = 4;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        vector<int> cs(N_COINS), ds(N_COINS);
        vector<long long> dp(MAXLIMIT);
        dp[0] = 1;

        for (int i = 0; i < N_COINS; i++)
        {
            cin >> cs[i];
            for (int j = cs[i]; j < MAXLIMIT; j++)
                dp[j] += dp[j - cs[i]];
        }

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++)
        {
            for (int j = 0; j < N_COINS; j++)
                cin >> ds[j];

            int V;
            cin >> V;

            long long ans = 0;
            // Find how many ways that the bit-th coin exceeds the limit.
            // Suppose coin A exceeds the limit. The number of ways to reach
            // the total value V is dp[V - (nA + 1)*A] given that nA is the
            // amount of coin A.
            for (int mask = 0; mask < (1 << N_COINS); mask++)
            {
                int parity = 1;
                long long curr_val = V;
                for (int bit = 0; bit < N_COINS; bit++)
                {
                    if ((1 << bit) & mask)
                    {
                        curr_val -= (long long)(ds[bit] + 1) * cs[bit]; // assume using at least ds[bit]+1 coins
                        parity = 1 - parity;
                    }
                }
                if (parity)
                    ans += curr_val >= 0 ? dp[curr_val] : 0;
                else
                    ans -= curr_val >= 0 ? dp[curr_val] : 0;
            }
            cout << ans << endl;
        }
    }
    return 0;
}