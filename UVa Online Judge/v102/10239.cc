/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10239.cc
#  Description:     UVa Online Judge - 10239
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
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

const int MAXN = 1005;
const int MAXK = 12;

int N;
long long W;
vdd A;
vl qs;
vl dp;
long long rmq[MAXN][MAXK];
int log_2[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    log_2[1] = 0;
    for (int i = 2; i < MAXN; i++) log_2[i] = log_2[i / 2] + 1;

    double tmp;
    while (cin >> N >> tmp) {
        W = round(tmp * 10000.0);
        if (N == 0 and W == 0) break;

        A.resize(N + 1);
        qs.resize(N + 1);
        dp.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            double hi, wi;
            cin >> hi >> wi;
            A[i] = ll(round(hi * 10000.0), round(wi * 10000.0));
            qs[i] = qs[i - 1] + round(wi * 10000.0);
            rmq[i][0] = round(hi * 10000.0);
        }

        for (int k = 1; k < MAXK; k++) {
            for (int i = 1; i + (1 << k) <= N + 1; i++) {
                rmq[i][k] = max(rmq[i][k - 1], rmq[i + (1 << (k - 1))][k - 1]);
            }
        }

        fill(dp.begin(), dp.end(), INF_LL);
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (qs[i] - qs[prev] <= W) {
                    int lv = log_2[i - prev];
                    dp[i] =
                        min(dp[i], dp[prev] + max(rmq[prev + 1][lv],
                                                  rmq[i - (1 << lv) + 1][lv]));
                }
            }
        }

        double ans = (double)dp[N] / 10000.0;
        cout << fixed << setprecision(4) << ans << endl;
    }
    return 0;
}