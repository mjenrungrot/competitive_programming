/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11709.cc
#  Description:     UVa Online Judge - 11709
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
map<string, int> name_to_idx;
vi V[MAXN], dfs_num, dfs_low, visited;
vvi SCCs;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (true) {
        getline(cin, line);
        vs nums = split(line, regex("\\s"));
        N = stoi(nums[0]);
        M = stoi(nums[1]);

        if (N == 0 and M == 0) break;

        name_to_idx.clear();
        for (int i = 0; i < MAXN; i++) V[i].clear();
        dfs_num = vi(MAXN, 0);
        dfs_low = vi(MAXN, 0);
        visited = vi(MAXN, 0);
        SCCs.clear();
        st = stack<int>();
        dfs_counter = 1;

        for (int i = 0; i < N; i++) {
            getline(cin, line);
            name_to_idx[line] = i;
        }

        for (int i = 0; i < M; i++) {
            string source, target;
            getline(cin, source);
            getline(cin, target);

            int u = name_to_idx[source];
            int v = name_to_idx[target];
            V[u].push_back(v);
        }

        for (int i = 0; i < N; i++)
            if (dfs_num[i] == 0) findscc(i);

        cout << SCCs.size() << endl;
    }

    return 0;
}