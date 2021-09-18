/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10731.cc
#  Description:     UVa Online Judge - 10731
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

int dfs_counter;
vector<vs> data;
map<string, int> name_to_idx;
vi dfs_num, dfs_low, visited;
vvi V, SCCs;
stack<int> st;
vs names;

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
    bool newline = false;
    while (true) {
        getline(cin, line);
        int n_lines = stoi(line);
        if (n_lines == 0) break;

        name_to_idx.clear();
        data.clear();
        V.clear();
        names.clear();

        for (int i = 1; i <= n_lines; i++) {
            getline(cin, line);
            vs tokens = split(line, regex("\\s"));
            for (auto& token : tokens) {
                if (name_to_idx.count(token)) continue;
                name_to_idx[token] = name_to_idx.size();
                names.push_back(token);
            }
            data.push_back(tokens);
        }

        V.resize(name_to_idx.size());
        for (auto& tokens : data) {
            assert(tokens.size() == 6);
            for (int i = 0; i < 5; i++)
                V[name_to_idx[tokens[5]]].push_back(name_to_idx[tokens[i]]);
        }

        dfs_num = vi(name_to_idx.size());
        dfs_low = vi(name_to_idx.size());
        visited = vi(name_to_idx.size());
        dfs_counter = 1;
        st = stack<int>();
        SCCs.clear();

        for (int i = 0; i < V.size(); i++) {
            if (dfs_num[i] == 0) findscc(i);
        }

        // sort SCC
        for (int i = 0; i < SCCs.size(); i++) {
            sort(SCCs[i].begin(), SCCs[i].end(), [](int x, int y) {
                assert(x < names.size());
                assert(y < names.size());
                return names[x] < names[y];
            });
        }
        sort(SCCs.begin(), SCCs.end(), [](vi x, vi y) {
            assert(x[0] < names.size());
            assert(y[0] < names.size());
            return names[x[0]] < names[y[0]];
        });

        if (newline) cout << endl;
        newline = true;

        for (auto& scc : SCCs) {
            bool space = false;
            for (auto& num : scc) {
                if (space) cout << " ";
                space = true;
                cout << names[num];
            }
            cout << endl;
        }
    }

    return 0;
}