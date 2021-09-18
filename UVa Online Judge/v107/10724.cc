/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10724.cc
#  Description:     UVa Online Judge - 10724
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
const int MAXN = 55;

int N, M;
int exist[MAXN][MAXN];
double dp[MAXN][MAXN];
vdd V;
vector<pair<int, double>> G[MAXN];

double d(dd x, dd y) {
    return sqrt((x.first - y.first) * (x.first - y.first) +
                (x.second - y.second) * (x.second - y.second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;
        V.clear();
        for (int i = 0; i < MAXN; i++) G[i].clear();
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                dp[i][j] = (i == j ? 0 : 1e9);
                exist[i][j] = 0;
            }

        for (int i = 0; i < N; i++) {
            double x, y;
            cin >> x >> y;
            V.push_back(dd(x, y));
        }

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].push_back({v, d(V[u], V[v])});
            G[v].push_back({u, d(V[u], V[v])});
            dp[u][v] = dp[v][u] = G[u].back().second;
            exist[u][v] = exist[v][u] = true;
        }

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

        ii best;
        double best_total = 0;
        for (int u = 0; u < N; u++) {
            for (int v = u + 1; v < N; v++) {
                if (exist[u][v]) continue;
                double total = 0.0;
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++) {
                        double val = dp[i][j];
                        val = min(val, dp[i][u] + d(V[u], V[v]) + dp[v][j]);
                        val = min(val, dp[i][v] + d(V[u], V[v]) + dp[u][j]);
                        total += dp[i][j] - val;
                    }
                cerr << u << " " << v << " " << total << endl;
                if (total > best_total) {
                    best_total = total;
                    best = ii(u, v);
                }
            }
        }

        if (best_total < 1.0 + 1e-6) {
            cout << "No road required" << endl;
        } else {
            cout << best.first + 1 << " " << best.second + 1 << endl;
        }
    }

    return 0;
}