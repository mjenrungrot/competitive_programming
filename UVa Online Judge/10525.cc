/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10525.cc
#  Description:     UVa Online Judge - 10525
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
const int MAXN = 100;

int N, M, d1[MAXN][MAXN], d2[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;

        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                d1[i][j] = d2[i][j] = (i == j ? 0 : INF_INT);
            }

        for (int i = 1; i <= M; i++) {
            int u, v, a, b;
            cin >> u >> v >> a >> b;
            if (a < d1[u][v] or (a == d1[u][v] and b < d2[u][v])) {
                d1[u][v] = d1[v][u] = a;
                d2[u][v] = d2[v][u] = b;
            }
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (d1[i][k] + d1[k][j] < d1[i][j]) {
                        d1[i][j] = d1[i][k] + d1[k][j];
                        d2[i][j] = d2[i][k] + d2[k][j];
                    } else if (d1[i][k] + d1[k][j] == d1[i][j] and
                               d2[i][k] + d2[k][j] < d2[i][j]) {
                        d1[i][j] = d1[i][k] + d1[k][j];
                        d2[i][j] = d2[i][k] + d2[k][j];
                    }
                }
            }
        }

        int Q;
        cin >> Q;
        while (Q--) {
            int u, v;
            cin >> u >> v;
            if (d1[u][v] == INF_INT) {
                cout << "No Path." << endl;
            } else {
                cout << "Distance and time to reach destination is " << d2[u][v]
                     << " & " << d1[u][v] << "." << endl;
            }
        }

        if (T) cout << endl;
    }

    return 0;
}