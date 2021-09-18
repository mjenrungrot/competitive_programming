/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10036.cc
#  Description:     UVa Online Judge - 10036
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int mm(int x, int k) { return ((x % k) + k) % k; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<vector<int>> dp(2, vector<int>(K));
        int x;
        cin >> x;
        dp[0][mm(x, K)] = true;

        for (int i = 1; i < N; i++) {
            cin >> x;
            int curr = i % 2;
            int prev = 1 - curr;
            for (int j = 0; j < K; j++) dp[curr][j] = 0;
            for (int j = 0; j < K; j++) {
                if (dp[prev][j]) {
                    dp[curr][mm(j + x, K)] = true;
                    dp[curr][mm(j - x, K)] = true;
                }
            }
        }

        if (dp[(N - 1) % 2][0])
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;
    }
    return 0;
}