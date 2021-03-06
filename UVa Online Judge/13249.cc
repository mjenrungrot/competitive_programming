/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13249.cc
#  Description:     UVa Online Judge - 13249
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

int N, M, d[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) d[i][j] = (i == j ? 0 : INF_INT);

        for (int i = 1; i <= M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            d[u][v] = d[v][u] = min(d[u][v], w);
        }

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        int sa, sb, sc;
        cin >> sa >> sb >> sc;

        int max_dist = -1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) max_dist = max(max_dist, d[i][j]);

        int ta = (max_dist + sa - 1) / sa;
        int tb = (max_dist + sb - 1) / sb;
        int tc = (max_dist + sc - 1) / sc;

        int ans = max(ta, max(tb, tc));
        cout << ans << endl;
    }

    return 0;
}