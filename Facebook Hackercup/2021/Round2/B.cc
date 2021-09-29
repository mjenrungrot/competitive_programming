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

class union_find {
    vi parent, sizes;

   public:
    union_find(int n) {
        parent.resize(n);
        sizes.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int find_set(int a) {
        if (a == parent[a]) return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sizes[a] < sizes[b]) swap(a, b);
            parent[b] = a;
            sizes[a] += sizes[b];
        }
    }
};

vs split(string line, regex re) {
    vs output;
    sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
    while (it != it_end) {
        output.push_back(it->str());
        it++;
    }
    return output;
}

namespace lca {
// info: lca using binary lifting
// guide:
// [0]: Set n, and adj (start with 0-idx)
// [1]: call preprocess with root
// [2]: call lca(u, v)

// need to set the following
int n;
vector<vector<int>> adj;

// this will be updated
int l, timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int u, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i <= l; i++) up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }

    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; i--) {
        if (not is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

}  // namespace lca

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 800005;

int N;
vvi pos_freq;
int D[MAXN], Z[MAXN];

void init(int u, int p, int depth) {
    Z[u] = D[u] = depth;
    for (auto& x : lca::adj[u]) {
        if (x == p) continue;
        init(x, u, depth + 1);
    }
}

void postfix(int u, int p, int& ans) {
    for (auto& x : lca::adj[u]) {
        if (x == p) continue;
        postfix(x, u, ans);
    }

    if (p != u) {
        Z[p] = min(Z[p], Z[u]);
        ans += (Z[u] == D[u]);
    }
}

void solve() {
    cin >> N;
    lca::n = N;
    lca::adj.clear();
    lca::adj.resize(N);

    debug(N);

    pos_freq.clear();
    pos_freq.resize(N + 1);

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        lca::adj[u].push_back(v);
        lca::adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        int freq;
        cin >> freq;
        pos_freq[freq].push_back(i - 1);
    }

    lca::preprocess(0);

    init(0, 0, 0);

    for (auto& f : pos_freq) {
        if (f.size() == 1) continue;
        int earliest = INF_INT;
        for (int i = 1; i < f.size(); i++) {
            int lca_val = lca::lca(f[i - 1], f[i]);
            earliest = min(earliest, D[lca_val]);
        }
        for (int i = 0; i < f.size(); i++) Z[f[i]] = earliest;
    }
    int ans = 0;
    postfix(0, 0, ans);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

// // 2 8 x
// // 7 9 x
// // 7 3 x
// // 1 3 x
// // 3 8 x
// // 8 5 x
// // 5 6 x
// // 6 4 x

// 0 | 2 --- | | | 7 6 | | | 8 | | ---- | | 1 4 ---- | | | |
//     5 3

//         0 1 2 3 4 5 6 7 8 9 5 3 3 4 6 3 10 6 8 8

//         LCA(3) == > 2(D = 1)