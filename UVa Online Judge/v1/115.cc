/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        115.cc
#  Description:     UVa Online Judge - 115
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
const int MAXN = 405;

int N, timer, L, in_deg[MAXN], depth[MAXN], cluster_id[MAXN];
vi V[MAXN], tin, tout;
vvi up;
map<string, int> to_idx;

int f(string name) {
    if (to_idx.count(name)) return to_idx[name];
    return to_idx[name] = to_idx.size();
}

void dfs(int u, int d, int cluster, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    depth[u] = d;
    cluster_id[u] = cluster;

    for (int i = 1; i <= L; i++) up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto& v : V[u]) {
        if (v != p) dfs(v, d + 1, cluster, u);
    }

    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
    for (int i = L; i >= 0; i--) {
        if (not is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void preprocess() {
    tin.resize(N);
    tout.resize(N);
    timer = 0;
    L = ceil(log2(N));
    up.assign(N, vi(L + 1));

    int cluster_no = 1;
    for (int i = 0; i < N; i++)
        if (in_deg[i] == 0) {
            dfs(i, 1, cluster_no++, i);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string name1, name2;
    while (cin >> name1 >> name2) {
        if (name1 == "no.child") break;
        int id1 = f(name1);
        int id2 = f(name2);
        V[id2].emplace_back(id1);
        in_deg[id1]++;
    }

    N = to_idx.size();
    preprocess();

    while (cin >> name1 >> name2) {
        int id1 = f(name1);
        int id2 = f(name2);

        if (id1 >= N or id2 >= N or id1 == id2 or
            cluster_id[id1] != cluster_id[id2]) {
            cout << "no relation" << endl;
            continue;
        }

        // name1 is ancestor of name2
        if (is_ancestor(id1, id2)) {
            int depth_diff = depth[id2] - depth[id1];
            if (depth_diff == 1)
                cout << "parent" << endl;
            else if (depth_diff == 2)
                cout << "grand parent" << endl;
            else {
                for (int i = 1; i <= depth_diff - 2; i++) cout << "great ";
                cout << "grand parent" << endl;
            }
            continue;
        }

        if (is_ancestor(id2, id1)) {
            int depth_diff = depth[id1] - depth[id2];
            if (depth_diff == 1)
                cout << "child" << endl;
            else if (depth_diff == 2)
                cout << "grand child" << endl;
            else {
                for (int i = 1; i <= depth_diff - 2; i++) cout << "great ";
                cout << "grand child" << endl;
            }
            continue;
        }

        // sibling
        if (up[id1][0] == up[id2][0]) {
            cout << "sibling" << endl;
            continue;
        }

        // counsin
        int lca_node = lca(id1, id2);
        int depth_diff1 = depth[id1] - depth[lca_node] - 1;
        int depth_diff2 = depth[id2] - depth[lca_node] - 1;

        cout << min(depth_diff1, depth_diff2) << " cousin";
        if (abs(depth_diff1 - depth_diff2))
            cout << " removed " << abs(depth_diff1 - depth_diff2);
        cout << endl;
    }

    return 0;
}
