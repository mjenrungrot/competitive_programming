/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        125.cc
#  Description:     UVa Online Judge - 125
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef tuple<long long, long long, long long> lll;
typedef tuple<double, double, double> ddd;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]";
}

vs split(string line, regex re) {
    vs output;
    sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
    while (it != it_end) {
        output.push_back(it->str());
        it++;
    }
    return output;
}

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 35;

int N, M;
int infinite[MAXN][MAXN];
long long dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> M) {
        memset(dp, 0, sizeof(dp));
        memset(infinite, 0, sizeof(infinite));
        N = 0;

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            N = max(N, u + 1);
            N = max(N, v + 1);
            dp[u][v]++;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dp[i][j] += dp[i][k] * dp[k][j];
                }
            }
        }

        for (int k = 0; k < N; k++) {
            if (not dp[k][k]) continue;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dp[i][k] and dp[k][j]) {
                        infinite[i][j] = true;
                    }
                }
            }
        }

        cout << "matrix for city " << n_test++ << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j) cout << " ";
                cout << (infinite[i][j] ? -1 : dp[i][j]);
            }
            cout << endl;
        }
    }
    return 0;
}