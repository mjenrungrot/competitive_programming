/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        567.cc
#  Description:     UVa Online Judge - 567
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
const int N = 20;

vi V[N];
int dist[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (true) {
        if (cin.eof()) break;

        for (int i = 0; i < N; i++) V[i].clear();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) dist[i][j] = (i == j ? 0 : INF_INT);

        for (int i = 0; i < N - 1; i++) {
            int k;
            cin >> k;
            if (cin.eof()) break;
            for (int j = 1; j <= k; j++) {
                int v;
                cin >> v;
                v--;
                V[i].push_back(v);
                V[v].push_back(i);
                dist[i][v] = dist[v][i] = 1;
            }
        }
        if (cin.eof()) break;

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }

        cout << "Test Set #" << ++n_test << endl;

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            int s, t;
            cin >> s >> t;
            cout << setw(2) << s << " to " << setw(2) << t << ": "
                 << dist[s - 1][t - 1] << endl;
        }
        cout << endl;
    }

    return 0;
}