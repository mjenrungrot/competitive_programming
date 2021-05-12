/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10354.cc
#  Description:     UVa Online Judge - 10354
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
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

int P, R, BH, OF, YH, M;
int dist1[MAXN][MAXN], dist2[MAXN][MAXN], parent[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> P >> R >> BH >> OF >> YH >> M) {
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                dist1[i][j] = dist2[i][j] = (i == j ? 0 : INF_INT);

        for (int i = 0; i < R; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            dist1[u][v] = dist1[v][u] = dist2[u][v] = dist2[v][u] = w;
        }

        for (int k = 1; k <= P; k++)
            for (int i = 1; i <= P; i++)
                for (int j = 1; j <= P; j++) {
                    dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
                }

        bitset<MAXN> cant;
        for (int i = 1; i <= P; i++) {
            if (dist1[BH][OF] == dist1[BH][i] + dist1[i][OF]) {
                cant.set(i);
                dist2[i][i] = INF_INT;
            }
        }

        for (int k = 1; k <= P; k++) {
            if (cant.test(k)) continue;
            for (int i = 1; i <= P; i++) {
                if (cant.test(i)) continue;
                for (int j = 1; j <= P; j++) {
                    if (cant.test(j)) continue;
                    dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
                }
            }
        }

        if (dist2[YH][M] == INF_INT or cant.test(YH) or cant.test(M)) {
            cout << "MISSION IMPOSSIBLE." << endl;
        } else {
            cout << dist2[YH][M] << endl;
        }
    }

    return 0;
}