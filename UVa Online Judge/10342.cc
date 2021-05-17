/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10342.cc
#  Description:     UVa Online Judge - 10342
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
const int MAXN = 105;

int N, M;
vii V[MAXN];
int dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N >> M) {
        for (int i = 0; i < MAXN; i++) V[i].clear();
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) dp[i][j] = (i == j ? 0 : INF_INT);

        for (int i = 1; i <= M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            V[u].push_back(ii(v, w));
            V[v].push_back(ii(u, w));
            dp[u][v] = dp[v][u] = w;
        }

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

        cout << "Set #" << ++n_test << endl;

        int Q;
        cin >> Q;
        while (Q--) {
            int u, v;
            cin >> u >> v;

            int best = dp[u][v];
            int second_best = INF_INT;
            for (int i = 0; i < N; i++)
                for (auto x : V[i]) {
                    int source = i;
                    int target = x.first;
                    int weight = x.second;

                    if (dp[u][source] + weight + dp[target][v] > best) {
                        second_best = min(second_best, dp[u][source] + weight +
                                                           dp[target][v]);
                    }
                }

            if (second_best == INF_INT) {
                cout << "?" << endl;
            } else {
                cout << second_best << endl;
            }
        }
    }
    return 0;
}