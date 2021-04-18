/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10520.cc
#  Description:     UVa 10520
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
long long memo[30][30];
int N;

long long f(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];

    long long ans = 0LL;
    if (i < j) {
        for (int k = i; k < j; k++) ans = max(ans, f(i, k) + f(k + 1, j));
    } else {
        long long left = 0LL;
        if (i < N) {
            for (int k = i + 1; k <= N; k++)
                left = max(left, f(k, 1) + f(k, j));
        }

        long long right = 0LL;
        if (j > 0) {
            for (int k = 1; k < j; k++) {
                right = max(right, f(i, k) + f(N, k));
            }
        }

        ans = left + right;
    }
    return memo[i][j] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A_n;
    while (cin >> N >> A_n) {
        memset(memo, -1, sizeof(memo));
        memo[N][1] = A_n;
        cout << f(1, N) << endl;
    }

    return 0;
}