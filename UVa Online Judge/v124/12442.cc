/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12442.cc
#  Description:     UVa Online Judge - 12442
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
const int MAXN = 50005;

int N;
int G[MAXN];
vi length, dfs_state;

int dfs(int u) {
    dfs_state[u] = 1;
    length[u] = 0;
    if (dfs_state[G[u]] == 0) {
        length[u] += dfs(G[u]) + 1;
    }
    dfs_state[u] = 0;
    return length[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cin >> N;

        length = vi(N + 1, -1);
        dfs_state = vi(N + 1, 0);

        for (int i = 1; i <= N; i++) {
            int u, v;
            cin >> u >> v;
            G[u] = v;
        }

        int ans = -1, ans_idx = -1;
        for (int i = 1; i <= N; i++) {
            if (length[i] == -1) length[i] = dfs(i);
            if (length[i] > ans) {
                ans = length[i];
                ans_idx = i;
            }
        }
        cout << "Case " << ++n_test << ": " << ans_idx << endl;
    }

    return 0;
}