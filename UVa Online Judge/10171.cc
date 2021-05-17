/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10171.cc
#  Description:     UVa Online Judge - 10171
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
const int MAXN = 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        if (N == 0) break;

        vvi d1(MAXN, vi(MAXN, INF_INT)), d2(MAXN, vi(MAXN, INF_INT));
        for (int i = 0; i < MAXN; i++) d1[i][i] = d2[i][i] = 0;

        map<char, int> to_idx;

        for (int i = 0; i < N; i++) {
            char st, di, u_str, v_str;
            int w;

            cin >> st >> di >> u_str >> v_str >> w;

            int u = (to_idx.count(u_str) ? to_idx[u_str]
                                         : (to_idx[u_str] = to_idx.size()));
            int v = (to_idx.count(v_str) ? to_idx[v_str]
                                         : (to_idx[v_str] = to_idx.size()));
            if (st == 'Y') {
                d1[u][v] = min(d1[u][v], w);
                if (di == 'B') d1[v][u] = min(d1[v][u], w);
            } else if (st == 'M') {
                d2[u][v] = min(d2[u][v], w);
                if (di == 'B') d2[v][u] = min(d2[v][u], w);
            }
        }

        for (int k = 0; k < MAXN; k++)
            for (int i = 0; i < MAXN; i++)
                for (int j = 0; j < MAXN; j++) {
                    d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
                    d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
                }

        char source_str, target_str;
        cin >> source_str >> target_str;
        int source =
            (to_idx.count(source_str) ? to_idx[source_str]
                                      : (to_idx[source_str] = to_idx.size()));

        int target =
            (to_idx.count(target_str) ? to_idx[target_str]
                                      : (to_idx[target_str] = to_idx.size()));

        int ans = INF_INT;
        for (auto kv : to_idx) {
            int val = d1[source][kv.second] + d2[target][kv.second];
            ans = min(val, ans);
        }

        if (ans == INF_INT) {
            cout << "You will never meet." << endl;
        } else {
            cout << ans;
            for (auto kv : to_idx) {
                int val = d1[source][kv.second] + d2[target][kv.second];
                if (val == ans) cout << " " << kv.first;
            }
            cout << endl;
        }
    }

    return 0;
}