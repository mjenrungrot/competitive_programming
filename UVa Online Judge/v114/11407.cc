/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11407.cc
#  Description:     UVa 11407
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

const int MAXN = 10005;

int dp[MAXN];

void gen() {
    for (int i = 0; i < MAXN; i++) dp[i] = INF_INT;

    dp[0] = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 1; j * j + i < MAXN; j++) {
            dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    gen();

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << endl;
    }

    return 0;
}