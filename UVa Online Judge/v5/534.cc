/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        534.cc
#  Description:     UVa Online Judge - 534
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

int N;
vector<ii> points;
vector<tuple<int, int, double>> edges;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;
        points.clear();
        edges.clear();

        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                double d = hypot(points[i].first - points[j].first,
                                 points[i].second - points[j].second);
                edges.push_back({i, j, d});
            }

        sort(edges.begin(), edges.end(),
             [](tuple<int, int, double>& x, tuple<int, int, double>& y) {
                 return get<2>(x) < get<2>(y);
             });

        parent = vi(N);
        ranking = vi(N);
        for (int i = 0; i < N; i++) parent[i] = i;

        double ans = 0;
        for (auto& edge : edges) {
            auto u = get<0>(edge);
            auto v = get<1>(edge);
            auto d = get<2>(edge);

            if (find_set(u) == find_set(v)) continue;
            union_set(u, v);
            ans = max(ans, d);
            if (find_set(0) == find_set(1)) break;
        }

        cout << "Scenario #" << ++n_test << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << ans << endl;
        cout << endl;
    }

    return 0;
}