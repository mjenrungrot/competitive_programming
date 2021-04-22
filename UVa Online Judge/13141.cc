/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13141.cc
#  Description:     UVa Online Judge 13141
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

const int MAXN = 90;
long long dp[MAXN];

long long f(int n) {
    if (n == 1) return 1;  // level 1 doesn't branch
    if (n == 2) return 1;

    if (dp[n] != -1) return dp[n];

    long long ans = 0;
    ans += f(n - 1);  // main branch
    ans += f(n - 2);  // extra branch

    return dp[n] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    memset(dp, -1, sizeof(dp));
    while (cin >> N) {
        if (N == 0) break;
        cout << f(N) << endl;
    }

    return 0;
}