/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1247.cc
#  Description:     UVa Online Judge - 1247
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
const int MAXN = 26;

int N, M;
int dist[MAXN][MAXN], length[MAXN][MAXN], path[MAXN][MAXN];

void print_path(int u, int v) {
    if (u != v) print_path(u, path[u][v]);
    if (u != v) cout << " ";
    cout << (char)('A' + v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                dist[i][j] = (i == j ? 0 : INF_INT);
                length[i][j] = (i == j ? 0 : INF_INT);
                path[i][j] = -1;
            }

        for (int i = 0; i < M; i++) {
            char u, v;
            int w;
            cin >> u >> v >> w;
            dist[u - 'A'][v - 'A'] = dist[v - 'A'][u - 'A'] = w;
            length[u - 'A'][v - 'A'] = length[v - 'A'][u - 'A'] = 1;
            path[u - 'A'][v - 'A'] = u - 'A';
            path[v - 'A'][u - 'A'] = v - 'A';
        }

        for (int k = 0; k < MAXN; k++)
            for (int i = 0; i < MAXN; i++)
                for (int j = 0; j < MAXN; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        length[i][j] = length[i][k] + length[k][j];
                        path[i][j] = path[k][j];
                    } else if (dist[i][k] + dist[k][j] == dist[i][j] and
                               length[i][k] + length[k][j] < length[i][j]) {
                        length[i][j] = length[i][k] + length[k][j];
                        path[i][j] = path[k][j];
                    }
                }

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            char u, v;
            cin >> u >> v;
            print_path(u - 'A', v - 'A');
            cout << endl;
        }
    }

    return 0;
}