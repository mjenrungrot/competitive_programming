/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        662.cc
#  Description:     UVa Online Judge - 662
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

const int MAXN = 205;
const int MAXK = 32;

int N, K;
int A[MAXN];
int dp[MAXN][MAXN][MAXK];
int backtrack[MAXN][MAXN][MAXK][2];

int f(int l, int r, int k) {
    if (l > r) return 0;
    if (k == 0) return INF_INT;
    if (dp[l][r][k] != -1) return dp[l][r][k];

    if (k == 1) {
        int ans = INF_INT;

        int n_left = 0, sum_left = 0;
        int n_right = 0, sum_right = 0;
        for (int i = l; i <= r; i++) {
            n_right++;
            sum_right += A[i];
        }

        int best_pos = -1;
        for (int pos = l; pos <= r; pos++) {
            sum_right -= A[pos];
            n_right--;

            // putting depot at pos
            int val =
                (sum_right - n_right * A[pos]) + (n_left * A[pos] - sum_left);

            sum_left += A[pos];
            n_left++;
            if (val < ans) {
                ans = val;
                best_pos = pos;
            }
        }
        backtrack[l][r][k][0] = r;
        backtrack[l][r][k][1] = best_pos;
        return dp[l][r][k] = ans;
    }

    int ans = INF_INT;
    int best_ending = -1;
    int best_cutting = -1;
    for (int ending = l; ending <= r; ending++) {
        // serving at restaurant [l, ending]
        int val = f(l, ending, 1) + f(ending + 1, r, k - 1);
        if (val < ans) {
            ans = val;
            best_ending = ending;
            best_cutting = backtrack[l][ending][1][1];
        }
    }
    backtrack[l][r][k][0] = best_ending;
    backtrack[l][r][k][1] = best_cutting;
    return dp[l][r][k] = ans;
}

void printsol(int l, int r, int k, int counter) {
    if (k == 0) return;
    int ending = backtrack[l][r][k][0];
    int pos = backtrack[l][r][k][1];

    cout << "Depot " << counter << " at restaurant " << pos << " serves";
    if (l == ending) {
        cout << " restaurant " << l << endl;
    } else {
        cout << " restaurants " << l << " to " << ending << endl;
    }
    printsol(ending + 1, r, k - 1, counter + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N >> K) {
        if (N == 0 and K == 0) break;

        for (int i = 1; i <= N; i++) cin >> A[i];
        memset(dp, -1, sizeof(dp));

        cout << "Chain " << ++n_test << endl;
        int ans = f(1, N, K);
        printsol(1, N, K, 1);
        cout << "Total distance sum = " << ans << endl << endl;
    }

    return 0;
}