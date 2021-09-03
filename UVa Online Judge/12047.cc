/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12047.cc
#  Description:     UVa Online Judge - 12047
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
const int MAXN = 10005;

int N, M, s, t, p;
vii V[MAXN], V_inv[MAXN];
vi dist, dist_inv;

void run() {
    for (int i = 0; i < MAXN; i++) {
        V[i].clear();
        V_inv[i].clear();
    }

    cin >> N >> M >> s >> t >> p;
    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        V[u].emplace_back(v, w);
        V_inv[v].emplace_back(u, w);
    }

    auto cmp = [](ii x, ii y) { return x.first > y.first; };
    priority_queue<ii, vii, decltype(cmp)> pq(cmp);

    // dijkstra forward
    dist = vi(MAXN, INF_INT);
    dist[s] = 0;
    pq.push({dist[s], s});

    while (not pq.empty()) {
        auto curr_d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();

        if (curr_d < dist[u]) continue;
        for (auto& x : V[u]) {
            if (curr_d + x.second < dist[x.first]) {
                dist[x.first] = curr_d + x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }

    // dijkstra backward
    dist_inv = vi(MAXN, INF_INT);
    dist_inv[t] = 0;
    pq.push({dist_inv[t], t});

    while (not pq.empty()) {
        auto curr_d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();

        if (curr_d < dist_inv[u]) continue;
        for (auto& x : V_inv[u]) {
            if (curr_d + x.second < dist_inv[x.first]) {
                dist_inv[x.first] = curr_d + x.second;
                pq.push({dist_inv[x.first], x.first});
            }
        }
    }

    int ans = -1;
    for (int u = 1; u <= N; u++) {
        for (auto& x : V[u]) {
            auto v = x.first;
            auto d = x.second;

            if (dist[u] + d + dist_inv[v] <= p) {
                ans = max(ans, d);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        run();
    }

    return 0;
}