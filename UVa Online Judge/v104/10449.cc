/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10449.cc
#  Description:     UVa Online Judge - 10449
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
const int MAXN = 205;

int N, M, busyness[MAXN];
vii V[MAXN];

void solve() {
    for (int i = 1; i <= N; i++) V[i].clear();

    for (int i = 1; i <= N; i++) cin >> busyness[i];

    cin >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        int d = (busyness[v] - busyness[u]);
        d = d * d * d;
        V[u].emplace_back(v, d);
    }

    vi dist(N + 1, INF_INT);
    dist[1] = 0;

    for (int i = 0; i < N - 1; i++) {
        bool modified = false;
        for (int u = 1; u <= N; u++) {
            if (dist[u] != INF_INT) {
                for (auto& x : V[u]) {
                    auto v = x.first;
                    auto w = x.second;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        modified = true;
                    }
                }
            }
        }
        if (not modified) break;
    }

    bool neg_cycle = false;
    for (int i = 0; i < N - 1; i++) {
        bool modified = false;
        for (int u = 1; u <= N; u++) {
            if (dist[u] != INF_INT) {
                for (auto& x : V[u]) {
                    auto v = x.first;
                    auto w = x.second;
                    if (dist[u] + w < dist[v] or dist[u] == -INF_INT) {
                        dist[v] = -INF_INT;
                        modified = true;
                    }
                }
            }
        }
        if (not modified) break;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int target;
        cin >> target;

        int ans = dist[target];
        if (ans < 3 or ans == INF_INT)
            cout << "?" << endl;
        else
            cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        cout << "Set #" << ++n_test << endl;
        solve();
    }

    return 0;
}