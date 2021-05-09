/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11838.cc
#  Description:     UVa Online Judge - 11838
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
const int MAXN = 1005;

int N, M, dfs_counter;
vi dfs_num, dfs_low, visited;
vvi V, SCCs;
stack<int> st;

void findscc(int u, int p) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    visited[u] = 1;
    st.push(u);
    for (auto v : V[u]) {
        if (dfs_num[v] == 0) findscc(v, u);
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u]) {
        vi curr_scc;
        while (true) {
            int v = st.top();
            st.pop();
            visited[v] = 0;
            curr_scc.push_back(v);
            if (v == u) break;
        }
        SCCs.push_back(curr_scc);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;

        dfs_counter = 1;
        dfs_num = vi(N + 1);
        dfs_low = vi(N + 1);
        visited = vi(N + 1);
        V = vvi(N + 1);
        SCCs.clear();
        st = stack<int>();

        for (int i = 1; i <= M; i++) {
            int u, v, type;
            cin >> u >> v >> type;
            if (type == 1)
                V[u].push_back(v);
            else {
                V[u].push_back(v);
                V[v].push_back(u);
            }
        }

        for (int i = 1; i <= N; i++)
            if (dfs_num[i] == 0) findscc(i, -1);

        if (SCCs.size() == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}