/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11908.cc
#  Description:     UVa Online Judge - 11908
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

const int MAXN = 200005;

vector<iii> A;
vi dp(MAXN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            A[i] = iii(x, x + y - 1, z);
        }

        sort(A.begin(), A.end(),
             [](iii x, iii y) { return get<0>(x) < get<0>(y); });

        fill(dp.begin(), dp.end(), -INF_INT);
        dp[0] = 0;

        int curr_sweep = 0;
        int ans = -INF_INT;
        for (int i = 0; i < N; i++) {
            int start_lv = get<0>(A[i]);
            int end_lv = get<1>(A[i]);
            int cost = get<2>(A[i]);

            while (curr_sweep < start_lv) {
                curr_sweep++;
                dp[curr_sweep] = max(dp[curr_sweep], dp[curr_sweep - 1]);
            }

            dp[end_lv] = max(dp[end_lv], dp[start_lv - 1] + cost);
            ans = max(ans, dp[end_lv]);
        }

        cout << "Case " << ++n_test << ": " << ans << endl;
    }
    return 0;
}