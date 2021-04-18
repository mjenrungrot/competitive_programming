#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

const int INF = 1e9;
const int MAXT = 303;
const int MAXN = 35;

typedef pair<int, int> ii;
int dp[MAXN][MAXT][MAXT];
ii parent[MAXN][MAXT][MAXT];
int T1, T2;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> T1 >> T2) {
        if (T1 == 0 and T2 == 0) break;
        cin >> N;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= T1; j++)
                for (int k = 0; k <= T2; k++) dp[i][j][k] = INF;
        }
        dp[0][0][0] = 0;

        for (int i = 1; i <= N; i++) {
            int n_samples;
            cin >> n_samples;

            vector<int> cost1(n_samples), cost2(n_samples);
            for (int j = 0; j < n_samples; j++) cin >> cost1[j];
            for (int j = 0; j < n_samples; j++) cin >> cost2[j];

            for (int j = 0; j <= n_samples; j++) {
                int n1 = j;
                int n2 = n_samples - n1;

                for (int t1 = 0; t1 <= T1; t1++) {
                    if (t1 + n1 > T1) continue;
                    for (int t2 = 0; t2 <= T2; t2++) {
                        if (t2 + n2 > T2) continue;
                        int c1 = n1 ? cost1[n1 - 1] : 0;
                        int c2 = n2 ? cost2[n2 - 1] : 0;

                        int val = dp[i - 1][t1][t2] + c1 + c2;
                        if (val < dp[i][t1 + n1][t2 + n2]) {
                            dp[i][t1 + n1][t2 + n2] = val;
                            parent[i][t1 + n1][t2 + n2] = ii(n1, n2);
                        }
                    }
                }
            }
        }
        string output = "";
        output += to_string(dp[N][T1][T2]) + '\n';
        vector<int> ans(N + 1);

        int n1 = T1, n2 = T2;
        for (int i = N; i >= 1; i--) {
            ii p = parent[i][n1][n2];
            ans[i] = p.first;
            n1 -= p.first;
            n2 -= p.second;
        }
        for (int i = 1; i <= N; i++) {
            if (i > 1) output += ' ';
            output += to_string(ans[i]);
        }
        output += '\n';

        output += '\n';
        cout << output;
    }
    return 0;
}