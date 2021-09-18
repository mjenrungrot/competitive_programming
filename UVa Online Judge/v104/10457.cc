/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10457.cc
#  Description:     UVa Online Judge - 10457
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

int N;
vector<iii> edges;
vi parent, ranking;

int find_set(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    if (ranking[u] < ranking[v])
        parent[u] = v;
    else
        parent[v] = u;
    if (ranking[u] == ranking[v]) ranking[u]++;
}

bool mst(int idx, int st, int ed, int& biggest) {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        ranking[i] = 1;
    }

    for (int i = idx; i < edges.size(); i++) {
        auto u = get<0>(edges[i]);
        auto v = get<1>(edges[i]);

        if (find_set(u) == find_set(v)) continue;
        union_set(u, v);

        if (find_set(st) == find_set(ed)) {
            biggest = get<2>(edges[i]);
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    int M;
    while (cin >> N >> M) {
        if (N == 0) break;
        edges.clear();

        for (int i = 0; i < M; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            edges.push_back({u, v, d});
        }
        parent = vi(N + 1, 0);
        ranking = vi(N + 1, 0);

        sort(edges.begin(), edges.end(),
             [](iii& x, iii& y) { return get<2>(x) < get<2>(y); });

        int cost_s, cost_t;
        cin >> cost_s >> cost_t;

        int q;
        cin >> q;
        while (q--) {
            int s, t;
            cin >> s >> t;

            int res = INF_INT;
            int biggest = 0;
            for (int i = 0; i < edges.size(); i++) {
                if (mst(i, s, t, biggest)) {
                    res = min(res, biggest - get<2>(edges[i]));
                } else {
                    break;
                }
            }
            int ans = cost_s + cost_t + res;

            cout << ans << endl;
        }
    }

    return 0;
}