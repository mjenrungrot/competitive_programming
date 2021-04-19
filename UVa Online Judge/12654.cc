/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12654.cc
#  Description:     UVa 12654
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

const int MAXN = 2005;

int N, C, T1, T2;
vi A;

int dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> C >> T1 >> T2) {
        A.clear();
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            A.push_back(x);
            A.push_back(C + x);
        }
        sort(A.begin(), A.end());

        int ans = INF_INT;
        for (int start = 0; start < N; start++) {
            for (int i = start; i <= start + N; i++) dp[i] = INF_INT;
            dp[start] = 0;

            int curr1 = start, curr2 = start;
            for (int i = start; i < start + N; i++) {
                while (curr1 + 1 < start + N and A[curr1 + 1] - A[i] <= T1)
                    curr1++;
                while (curr2 + 1 < start + N and A[curr2 + 1] - A[i] <= T2)
                    curr2++;

                // dp[x] = optimal for A[start..x-1]
                dp[curr1 + 1] = min(dp[curr1 + 1], dp[i] + T1);
                dp[curr2 + 1] = min(dp[curr2 + 1], dp[i] + T2);
            }
            ans = min(ans, dp[start + N]);
        }

        cout << ans << endl;
    }
    return 0;
}