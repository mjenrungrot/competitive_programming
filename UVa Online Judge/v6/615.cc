/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        615.cc
#  Description:     UVa Online Judge - 615
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
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

// Debug Snippets

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x) {
    int f = 0;
    cerr << '{';
    for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)

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

// End Debug Snippets

vs split(string line) {
    vs output;
    istringstream iss(line);
    string tmp;
    while (iss >> tmp) {
        output.push_back(tmp);
    }
    return output;
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

map<int, int> to_idx;
vii A;

int f(int x) {
    if (to_idx.count(x)) return to_idx[x];
    return to_idx[x] = to_idx.size();
}

void dfs(int u, vvi& V, vi& visited) {
    if (visited[u]) return;
    visited[u] = true;
    for (auto& v : V[u]) dfs(v, V, visited);
}

void solve() {
    if (A.empty()) {
        cout << " is a tree." << endl;
        return;
    }

    to_idx.clear();
    for (auto& x : A) {
        f(x.first);
        f(x.second);
    }

    vi in_deg(to_idx.size());
    vi visited(to_idx.size());
    vvi V(to_idx.size());
    for (auto& x : A) {
        int id1 = f(x.first);
        int id2 = f(x.second);
        in_deg[id2]++;
        V[id1].push_back(id2);
    }

    int count_root = 0, root = -1;
    for (int i = 0; i < to_idx.size(); i++) {
        if (in_deg[i] == 0) count_root++, root = i;
        if (count_root > 1 or in_deg[i] > 1) {
            cout << " is not a tree." << endl;
            return;
        }
    }
    if (count_root == 0) {
        cout << " is not a tree." << endl;
        return;
    }

    dfs(root, V, visited);
    for (auto& x : visited) {
        if (not x) {
            cout << " is not a tree." << endl;
            return;
        }
    }

    cout << " is a tree." << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    int u, v;
    while (cin >> u >> v) {
        if (u < 0 and v < 0) break;

        A.clear();
        if (u != 0 and v != 0) {
            A.emplace_back(u, v);
            while (cin >> u >> v) {
                if (u == 0 and v == 0) break;
                A.emplace_back(u, v);
            }
        }

        cout << "Case " << ++n_test;
        solve();
    }

    return 0;
}