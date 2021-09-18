/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12955.cc
#  Description:     UVa Online Judge - 12955
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

const int MAXN = 100005;
const int MAXK = 10;
int dp[MAXN];
int factorial[MAXK];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    factorial[0] = 1;
    for (int i = 1; i < MAXK; i++) factorial[i] = factorial[i - 1] * i;

    for (int i = 0; i < MAXN; i++) dp[i] = INF_INT;
    dp[0] = 0;

    for (int i = MAXK - 1; i >= 0; i--) {
        for (int j = 0; j + factorial[i] < MAXN; j++) {
            dp[j + factorial[i]] = min(dp[j + factorial[i]], dp[j] + 1);
        }
    }

    int N;
    while (cin >> N) {
        cout << dp[N] << endl;
    }

    return 0;
}
