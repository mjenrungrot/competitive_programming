/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1013.cc
#  Description:     UVa Online Judge - 1013
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
const int MAXN = 55;

int N;
vector<iii> points;
vector<tuple<int, int, double>> edges;
vi parent, ranking;
vector<pair<int, double>> V[MAXN];

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

void dfs(int u, int p, double max_time, double& cum) {
    cum += max_time * get<2>(points[u]);
    for (auto v : V[u]) {
        if (v.first == p) continue;
        dfs(v.first, u, max(max_time, v.second), cum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;
        points.clear();
        edges.clear();
        for (int i = 0; i < MAXN; i++) V[i].clear();

        for (int i = 0; i < N; i++) {
            int x, y, m;
            cin >> x >> y >> m;
            points.push_back({x, y, m});
        }

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                double d = hypot(get<0>(points[i]) - get<0>(points[j]),
                                 get<1>(points[i]) - get<1>(points[j]));
                edges.push_back({i, j, d});
            }

        sort(edges.begin(), edges.end(),
             [](tuple<int, int, double>& x, tuple<int, int, double>& y) {
                 return get<2>(x) < get<2>(y);
             });

        parent = vi(N);
        ranking = vi(N);
        for (int i = 0; i < N; i++) parent[i] = i;

        for (auto& edge : edges) {
            auto u = get<0>(edge);
            auto v = get<1>(edge);
            auto d = get<2>(edge);

            if (find_set(u) == find_set(v)) continue;
            V[u].push_back({v, d});
            V[v].push_back({u, d});
            union_set(u, v);
        }

        double cum = 0.0, total_pop = 0.0;
        for (int i = 0; i < N; i++) total_pop += get<2>(points[i]);
        dfs(0, -1, 0, cum);

        double ans = cum / total_pop;
        cout << "Island Group: " << ++n_test << " Average " << fixed
             << setprecision(2) << ans << endl;

        cout << endl;
    }

    return 0;
}