/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11770.cc
#  Description:     UVa Online Judge - 11770
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
const int MAXN = 10005;

int N, M, dfs_counter;
vi V[MAXN], dfs_num, dfs_low, visited;
vvi SCCs;
map<int, int> to_new_idx;
vvi new_V;
stack<int> st;

void findscc(int u) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    visited[u] = true;
    st.push(u);

    for (auto v : V[u]) {
        if (dfs_num[v] == 0) findscc(v);
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u]) {
        vi SCC;
        while (true) {
            int top = st.top();
            st.pop();
            visited[top] = false;
            to_new_idx[top] = SCCs.size();
            SCC.push_back(top);
            if (top == u) break;
        }
        SCCs.push_back(SCC);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cout << "Case " << ++n_test << ": ";

        // clear
        for (int i = 0; i < MAXN; i++) V[i].clear();
        dfs_num = vi(MAXN, 0);
        dfs_low = vi(MAXN, 0);
        visited = vi(MAXN, 0);
        dfs_counter = 1;
        st = stack<int>();
        to_new_idx.clear();
        SCCs.clear();
        new_V.clear();

        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
        }

        for (int i = 1; i <= N; i++)
            if (dfs_num[i] == 0) findscc(i);

        vi in_degrees(SCCs.size(), 0);
        for (int i = 1; i <= N; i++) {
            for (auto v : V[i]) {
                int curr_idx = to_new_idx[i];
                int target_idx = to_new_idx[v];
                if (curr_idx == target_idx) continue;
                in_degrees[target_idx]++;
            }
        }

        int ans = 0;
        for (auto& u : in_degrees) {
            if (u == 0) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}