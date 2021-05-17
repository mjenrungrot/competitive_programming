/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10987.cc
#  Description:     UVa Online Judge - 10987
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

int N, d[MAXN][MAXN], adjacent[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cout << "Case #" << ++n_test << ":" << endl;

        cin >> N;

        memset(d, 0, sizeof(d));
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= i - 1; j++) {
                cin >> d[i][j];
                d[j][i] = d[i][j];
            }
        }

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) adjacent[i][j] = true;

        bool notdone = true;
        for (int k = 1; k <= N and notdone; k++) {
            for (int i = 1; i <= N and notdone; i++) {
                for (int j = 1; j <= N and notdone; j++) {
                    if (d[i][k] + d[k][j] < d[i][j]) {
                        notdone = false;
                        break;
                    }

                    if (i == j or j == k or i == k) continue;

                    // possible to delete this edge
                    if (d[i][k] + d[k][j] == d[i][j]) adjacent[i][j] = false;
                }
            }
        }

        vector<iii> edges;
        if (notdone) {
            for (int i = 1; i <= N; i++)
                for (int j = i + 1; j <= N; j++) {
                    if (adjacent[i][j]) edges.push_back({i, j, d[i][j]});
                }
        }

        if (edges.size() == 0)
            cout << "Need better measurements." << endl;
        else {
            cout << edges.size() << endl;
            for (auto edge : edges) {
                cout << get<0>(edge) << " " << get<1>(edge) << " "
                     << get<2>(edge) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}