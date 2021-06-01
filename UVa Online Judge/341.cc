/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        341.cc
#  Description:     UVa Online Judge - 341
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
const int MAXN = 20;

int N;
int dist[MAXN][MAXN], path[MAXN][MAXN];
vii V[MAXN];

void print_path(int u, int v) {
    if (u != v) {
        print_path(u, path[u][v]);
        cout << " ";
    }
    cout << v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;

        for (int i = 0; i < MAXN; i++) V[i].clear();
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                dist[i][j] = (i == j ? 0 : INF_INT);
                path[i][j] = i;
            }

        for (int i = 1; i <= N; i++) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                int v, w;
                cin >> v >> w;
                V[i].push_back(ii(v, w));
                dist[i][v] = min(dist[i][v], w);
            }
        }

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        path[i][j] = path[k][j];
                    }
                }

        int start, end;
        cin >> start >> end;
        cout << "Case " << ++n_test << ": Path = ";
        print_path(start, end);
        cout << "; " << dist[start][end] << " second delay" << endl;
    }

    return 0;
}