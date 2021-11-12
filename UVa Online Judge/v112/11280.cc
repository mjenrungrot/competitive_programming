/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11280.cc
#  Description:     UVa Online Judge - 11280
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
const int MAXN = 105;

int N;
vii V[MAXN];
int dist[MAXN][MAXN];  // (node, used_edge)
map<string, int> to_idx;

int f(string x) {
    if (to_idx.count(x)) return to_idx[x];
    return to_idx[x] = to_idx.size();
}

void solve() {
    to_idx.clear();

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        f(name);
    }

    int M;
    cin >> M;

    for (int i = 0; i < N; i++) V[i].clear();
    for (int i = 1; i <= M; i++) {
        string u, v;
        int d;
        cin >> u >> v >> d;
        int uu = f(u);
        int vv = f(v);
        V[uu].emplace_back(vv, d);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF_INT;
        }

    int start = f("Calgary");
    int target = f("Fredericton");

    dist[start][0] = 0;
    for (int i = 1; i <= N - 1; i++) {
        for (int u = 0; u < N; u++) {
            for (auto& x : V[u]) {
                auto v = x.first;
                auto w = x.second;
                if (dist[u][i - 1] + w < dist[v][i]) {
                    dist[v][i] = dist[u][i - 1] + w;
                }
            }
        }
    }

    int nq;
    cin >> nq;
    while (nq--) {
        int q;
        cin >> q;
        q = min(q, N - 2);  // remove start + end
        q++;                // add end

        int ans = INF_INT;
        for (int i = 1; i <= q; i++) ans = min(ans, dist[target][i]);

        if (ans == INF_INT) {
            cout << "No satisfactory flights" << endl;
        } else {
            cout << "Total cost of flight(s) is $" << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cout << "Scenario #" << ++n_test << endl;
        solve();
        if (T) cout << endl;
    }

    return 0;
}