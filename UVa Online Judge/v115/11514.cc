/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11514.cc
#  Description:     UVa Online Judge - 11514
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

int P, V, E;
string names[MAXN];

vii powers;
map<string, int> to_idx;
int dp[2][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> P >> V >> E) {
        if (P == 0 and V == 0 and E == 0) break;

        to_idx.clear();
        powers.resize(P + 1);
        for (int i = 1; i <= P; i++) {
            int power, cost;
            cin >> names[i] >> power >> cost;
            to_idx[names[i]] = i;
            powers[i] = ii(power, cost);
        }

        for (int i = 0; i < MAXN; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= V; i++) {
            int curr = i % 2;
            int prev = 1 - curr;

            for (int j = 0; j < MAXN; j++) dp[curr][j] = INF_INT;

            string name, possible;
            int defense;
            cin >> name >> defense >> possible;

            regex re(",");
            sregex_token_iterator it(possible.begin(), possible.end(), re, -1);
            sregex_token_iterator it_end;
            while (it != it_end) {
                int idx = to_idx[it->str()];
                if (powers[idx].first >= defense) {
                    dp[curr][idx] = min(dp[curr][idx],
                                        dp[prev][idx - 1] + powers[idx].second);
                }
                it++;
            }
            for (int j = 1; j < MAXN; j++)
                dp[curr][j] = min(dp[curr][j], dp[curr][j - 1]);
        }

        if (dp[V % 2][P] > E)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}