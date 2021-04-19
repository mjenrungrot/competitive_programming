/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11420.cc
#  Description:     UVa 11420
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

const int MAXN = 70;

int N, S;
long long dp[MAXN][MAXN][2];

long long f(int n, int s, int prev) {
    if (n == 0) {
        return (s == 0);
    }

    if (dp[n][s][prev] != -1) return dp[n][s][prev];

    long long ans = 0;
    if (prev == 1) {
        // above is locked
        ans += f(n - 1, s - 1, prev);  // lock this one
        ans += f(n - 1, s, 0);         // not locking this one
    } else {
        // above is unlocked
        ans += f(n - 1, s, 1);  // lock this one
        ans += f(n - 1, s, 0);  // not locking this one
    }
    return dp[n][s][prev] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    while (cin >> N >> S) {
        if (N < 0 and S < 0) break;
        cout << f(N, S, 1) << endl;
    }

    return 0;
}