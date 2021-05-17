/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10803.cc
#  Description:     UVa Online Judge - 10803
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
const int MAXN = 105;
int N;
vdd V;
double dp[MAXN][MAXN];
vector<pair<int, double>> G[MAXN];

double dist(dd x, dd y) {
    return sqrt((x.first - y.first) * (x.first - y.first) +
                (x.second - y.second) * (x.second - y.second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cout << "Case #" << ++n_test << ":" << endl;

        cin >> N;

        for (int i = 0; i < MAXN; i++) G[i].clear();
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) dp[i][j] = (i == j ? 0.0 : 1e9);
        }
        V.resize(N + 1);

        for (int i = 1; i <= N; i++) {
            double x, y;
            cin >> x >> y;
            V[i] = dd(x, y);
        }

        const double INF = 1e8;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                double d = dist(V[i], V[j]);
                dp[i][j] = (d < 10.0 + 1e-8 ? d : INF);
            }
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        double max_dist = 0.0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                max_dist = max(max_dist, dp[i][j]);
            }

        if (max_dist < INF) {
            cout << fixed << setprecision(4) << max_dist << endl;
        } else {
            cout << "Send Kurdy" << endl;
        }
        cout << endl;
    }

    return 0;
}