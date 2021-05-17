/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        186.cc
#  Description:     UVa Online Judge - 186
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

vs names;
map<string, int> to_idx;
map<ii, pair<string, int>> route;
int dist[MAXN][MAXN], p[MAXN][MAXN], flag;

int conv(string u) {
    if (to_idx.count(u)) return to_idx[u];
    int ans = to_idx[u] = to_idx.size();
    names.push_back(u);
    return ans;
}

void print_path(int u, int v, int next) {
    if (u != v) print_path(u, p[u][v], v);
    if (next != -1) {
        cout << setw(20) << left << names[v] << " " << setw(20) << left
             << names[next] << " " << setw(10) << left << route[{v, next}].first
             << " " << setw(5) << right << route[{v, next}].second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++) {
            dist[i][j] = (i == j ? 0 : INF_INT);
            p[i][j] = i;
        }

    string line;
    while (getline(cin, line)) {
        vs tokens = split(line, regex(","));

        if (tokens.size() == 4) {
            int u = conv(tokens[0]);
            int v = conv(tokens[1]);
            int length = stoi(tokens[3]);
            if (length < dist[u][v]) {
                route[{u, v}] = route[{v, u}] = {tokens[2], length};
                dist[u][v] = dist[v][u] = length;
            }
        } else if (tokens.size() == 2) {
            if (not flag) {
                int N = names.size();

                for (int k = 0; k < N; k++)
                    for (int i = 0; i < N; i++)
                        for (int j = 0; j < N; j++) {
                            if (dist[i][k] + dist[k][j] < dist[i][j]) {
                                dist[i][j] = dist[i][k] + dist[k][j];
                                p[i][j] = p[k][j];
                            }
                        }

                flag = true;
            }

            int source = conv(tokens[0]);
            int target = conv(tokens[1]);

            cout << endl;
            cout << endl;
            cout << "From                 To                   Route      Miles"
                 << endl;
            cout << "-------------------- -------------------- ---------- -----"
                 << endl;
            print_path(source, target, -1);
            cout << "                                                     -----"
                 << endl;
            cout << "                                          Total      "
                 << setw(5) << right << dist[source][target] << endl;
        }
    }

    return 0;
}