/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10912.cc
#  Description:     UVa 10912
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXK = 27;
const int MAXSUM = 360;

long long dp[MAXK][MAXK][MAXSUM];

long long f(int l, int curr_ch, int curr_sum) {
    if (l == 0) {
        return curr_sum == 0;
    }
    if (l >= MAXK) return 0;
    if (curr_sum >= MAXSUM) return 0;

    if (dp[l][curr_ch][curr_sum] != -1) return dp[l][curr_ch][curr_sum];

    long long ans = 0;
    if (curr_ch + 1 <= 26) {
        ans += f(l, curr_ch + 1, curr_sum);                      // try next ch
        ans += f(l - 1, curr_ch + 1, curr_sum - (curr_ch + 1));  // use
    }
    return dp[l][curr_ch][curr_sum] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_case = 0;
    int L, S;

    memset(dp, -1, sizeof(dp));
    while (cin >> L >> S) {
        if (L == 0 and S == 0) break;
        long long ans = f(L, 0, S);
        cout << "Case " << ++n_case << ": " << ans << endl;
    }

    return 0;
}