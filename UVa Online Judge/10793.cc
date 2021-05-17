/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10793.cc
#  Description:     UVa Online Judge - 10793
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

int N, M, dp[MAXN][MAXN];
vii V[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cin >> N >> M;

        for (int i = 0; i < MAXN; i++) V[i].clear();
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                dp[i][j] = (i == j) ? 0 : INF_INT;
            }

        for (int i = 1; i <= M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            dp[u][v] = dp[v][u] = min(dp[u][v], w);
        }

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

        vi candidates;
        assert(N > 5);
        for (int i = 6; i <= N; i++) {
            if (dp[1][i] == dp[2][i] and dp[1][i] == dp[3][i] and
                dp[1][i] == dp[4][i] and dp[1][i] == dp[5][i]) {
                candidates.push_back(i);
            }
        }

        cout << "Map " << ++n_test << ": ";
        if (candidates.size() == 0) {
            cout << -1 << endl;
            continue;
        }

        int best_candidate_longest_dist = INF_INT;
        for (auto candidate : candidates) {
            int dist = -1;
            for (int i = 1; i <= N; i++) dist = max(dist, dp[candidate][i]);
            best_candidate_longest_dist =
                min(best_candidate_longest_dist, dist);
        }

        if (best_candidate_longest_dist == INF_INT) {
            cout << -1 << endl;
            continue;
        }

        cout << best_candidate_longest_dist << endl;
    }
    return 0;
}