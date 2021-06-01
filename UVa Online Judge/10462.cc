/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10462.cc
#  Description:     UVa Online Judge - 10462
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

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 105;
const int MAXDEPTH = 10;
int N, M, h[MAXN], dp[MAXN][MAXDEPTH], par[MAXN][MAXDEPTH];
vii V[MAXN];
vector<iii> edges;

void dfs(int u, int parent, int dis) {
    par[u][0] = parent;
    dp[u][0] = dis;
    h[u] = (parent == -1 ? 0 : h[parent] + 1);
    for (auto v : V[u]) {
        if (v.first == parent) continue;
        dfs(v.first, u, v.second);
    }
}

int lca(int u, int v) {
    int ans = -1;
    if (h[u] < h[v]) swap(u, v);

    for (int i = MAXDEPTH - 1; i >= 0; i--) {
        if (h[u] - h[v] >= (1 << i)) {
            ans = max(ans, dp[u][i]);
            u = par[u][i];
        }
    }

    if (u == v) return ans;

    for (int i = MAXDEPTH - 1; i >= 0; i--) {
        if (par[u][i] != -1 and par[v][i] != -1 and par[u][i] != par[v][i]) {
            ans = max(ans, max(dp[u][i], dp[v][i]));
            u = par[u][i];
            v = par[v][i];
        }
    }
    ans = max(ans, max(dp[u][0], dp[v][0]));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        for (int i = 0; i < MAXN; i++) V[i].clear();
        memset(par, -1, sizeof(par));

        cout << "Case #" << ++n_test << " : ";
        cin >> N >> M;

        union_find S(N + 1);
        edges.clear();
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        sort(edges.begin(), edges.end(),
             [](iii& x, iii& y) { return get<2>(x) < get<2>(y); });

        int mst = 0;
        int n_edges_mst = 0;
        vi in_mst(M);
        for (int i = 0; i < M; i++) {
            int u = get<0>(edges[i]);
            int v = get<1>(edges[i]);
            int w = get<2>(edges[i]);
            if (S.find_set(u) == S.find_set(v)) continue;
            in_mst[i] = true;
            V[u].push_back(ii(v, w));
            V[v].push_back(ii(u, w));
            S.union_set(u, v);
            n_edges_mst++;
            mst += w;
        }

        if (n_edges_mst != N - 1) {
            cout << "No way" << endl;
            continue;
        }

        dfs(1, -1, 0);
        for (int lv = 1; lv < MAXDEPTH; lv++) {
            for (int i = 1; i <= N; i++) {
                int middle = par[i][lv - 1];
                if (middle == -1) continue;
                par[i][lv] = par[middle][lv - 1];
                dp[i][lv] = max(dp[i][lv - 1], dp[middle][lv - 1]);
            }
        }

        int second_mst = INF_INT;
        for (int i = 0; i < M; i++) {
            if (in_mst[i]) continue;

            auto max_edge = lca(get<0>(edges[i]), get<1>(edges[i]));
            auto new_edge = get<2>(edges[i]);
            auto new_mst = mst - max_edge + new_edge;
            second_mst = min(second_mst, new_mst);
        }

        if (second_mst == INF_INT)
            cout << "No second way" << endl;
        else
            cout << second_mst << endl;
    }

    return 0;
}