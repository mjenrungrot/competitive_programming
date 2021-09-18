/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1229.cc
#  Description:     UVa Online Judge - 1229
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

int N, dfs_counter;
vi V[MAXN], dfs_num, dfs_low, visited;
vvi SCCs;
map<string, int> name_to_idx;
vector<vs> data;
vs names;
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
        vi scc;
        while (true) {
            int top = st.top();
            st.pop();
            visited[top] = false;
            scc.push_back(top);
            if (top == u) break;
        }
        SCCs.push_back(scc);
    }
}

void dfs(int u, vi& state, vs& ans) {
    if (state[u]) return;
    state[u] = 1;
    ans.push_back(names[u]);
    for (auto v : V[u]) {
        dfs(v, state, ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (true) {
        getline(cin, line);
        N = stoi(line);
        if (N == 0) break;

        name_to_idx.clear();
        names.resize(N + 1);
        data.resize(N + 1);
        for (int i = 0; i < MAXN; i++) V[i].clear();

        for (int i = 1; i <= N; i++) {
            getline(cin, line);
            vs tokens = split(line, regex("\\s"));
            names[i] = tokens[0];
            name_to_idx[names[i]] = i;
            data[i] = tokens;
        }

        for (int i = 1; i <= N; i++) {
            for (int token_idx = 1; token_idx < data[i].size(); token_idx++) {
                V[name_to_idx[data[i][0]]].push_back(
                    name_to_idx[data[i][token_idx]]);
            }
        }

        dfs_low = vi(MAXN, 0);
        dfs_num = vi(MAXN, 0);
        visited = vi(MAXN, 0);
        dfs_counter = 1;
        st = stack<int>();
        SCCs.clear();

        for (int i = 1; i <= N; i++) {
            if (dfs_num[i] == 0) findscc(i);
        }

        vi state(MAXN);
        vs ans;
        for (int i = 0; i < SCCs.size(); i++) {
            if (SCCs[i].size() > 1) dfs(SCCs[i][0], state, ans);
        }

        sort(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}