/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        242.cc
#  Description:     UVa Online Judge - 242
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAXLIMIT = 1005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_coins, n_combinations;
    while (cin >> n_coins) {
        if (n_coins == 0) break;

        cin >> n_combinations;

        vector<vector<int>> A(n_combinations);
        for (int i = 0; i < n_combinations; i++) {
            int N;
            cin >> N;
            for (int j = 0; j < N; j++) {
                int tmp;
                cin >> tmp;
                A[i].push_back(tmp);
            }
        }

        int maxans = -1, maxidx;
        for (int i = 0; i < n_combinations; i++) {
            vector<int> dp(MAXLIMIT);
            dp[0] = 1;

            for (auto coin : A[i]) {
                for (int val = 0; val < MAXLIMIT; val++) {
                    if (dp[val] and dp[val] <= n_coins) {
                        if (dp[val + coin] > dp[val] + 1 or dp[val + coin] == 0)
                            dp[val + coin] = dp[val] + 1;
                    }
                }
            }

            int curr = 0;
            while (dp[curr]) curr++;
            curr--;

            if (curr > maxans) {
                maxans = curr;
                maxidx = i;
            } else if (curr == maxans) {
                if (A[i].size() < A[maxidx].size()) {
                    maxidx = i;
                } else if (A[i].size() == A[maxidx].size()) {
                    bool flag = false;
                    for (int j = A[i].size() - 1, k = A[maxidx].size() - 1;
                         j >= 0 and k >= 0; j--, k--) {
                        if (A[i][j] != A[maxidx][k]) {
                            flag = A[i][j] < A[maxidx][k];
                            break;
                        }
                    }
                    if (flag) {
                        maxidx = i;
                    }
                }
            }
        }
        cout << "max coverage =" << setw(4) << maxans << " :";
        for (auto coin : A[maxidx]) cout << setw(3) << coin;
        cout << endl;
    }
    return 0;
}