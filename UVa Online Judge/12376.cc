/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12376.cc
#  Description:     UVa Online Judge - 12376
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

int N, M;
vi values, V[MAXN];

void dfs(int u, int curr_val) {
    int best_v = -1, best_v_val = -1;
    for (auto& v : V[u]) {
        if (values[v] > best_v_val) {
            best_v_val = values[v];
            best_v = v;
        }
    }

    if (best_v == -1) {
        cout << curr_val << " " << u << endl;
        return;
    }

    dfs(best_v, curr_val + best_v_val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;

    while (T--) {
        cout << "Case " << ++n_test << ": ";

        values = vi(MAXN, 0);
        for (int i = 0; i < MAXN; i++) V[i].clear();

        cin >> N >> M;
        for (int i = 0; i < N; i++) cin >> values[i];
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
        }

        dfs(0, values[0]);
    }

    return 0;
}