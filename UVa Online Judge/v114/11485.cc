/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11485.cc
#  Description:     UVa Online Judge - 11485
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

const int K = 8;
const int MAXN = 85;
vi A;
long long dp1[K + 1][MAXN], dp2[K + 1][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        if (N == 0) break;

        A.resize(N);
        for (int i = 0; i < N; i++) {
            double x;
            cin >> x;
            A[i] = int(round(x * 10.0)) % 10;
        }

        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        dp1[0][0] = 1;
        dp2[0][0] = 1;
        for (int i = 1; i <= K; i++) {
            for (auto val : A) {
                for (int j = 0; j < MAXN; j++) {
                    if (j - val >= 0 and dp1[i - 1][j - val]) {
                        dp1[i][j] += dp1[i - 1][j - val];
                    }
                    if (j - (val - val % 10) >= 0 and
                        dp2[i - 1][j - (val - val % 10)]) {
                        dp2[i][j] += dp2[i - 1][j - (val - val % 10)];
                    }
                }
            }
        }

        long long part1 = 0LL, part2 = 0LL;
        for (int i = 0; i < MAXN; i++) {
            part1 += (long long)dp1[K][i] * (i - i % 10);
            part2 += (long long)dp2[K][i] * i;
        }
        cout << (part1 - part2) / 10 << endl;
    }
    return 0;
}