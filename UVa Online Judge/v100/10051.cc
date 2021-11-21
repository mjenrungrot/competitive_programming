/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10051.cc
#  Description:     UVa Online Judge - 10051
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
const int MAXN = 505;
const vs names = {"front", "back", "left", "right", "top", "bottom"};

int N;
int A[MAXN][6];
vi V[6 * MAXN];

int opp(int i) {
    switch (i) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 4;
        default:
            return -1;
    }
}

void dfs(int u, vi& visited, vi& order) {
    if (visited[u]) return;
    visited[u] = true;

    for (auto& v : V[u]) {
        if (visited[v]) continue;
        dfs(v, visited, order);
    }
    order.push_back(u);
}

void print_sol(int node, vi& parent) {
    auto row = node / 6;
    auto face = node % 6;
    auto top_name = names[face];
    if (parent[node] != -1) print_sol(parent[node], parent);
    cout << row + 1 << " " << top_name << endl;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> A[i][j];
            V[6 * i + j].clear();
        }
    }

    for (int i1 = 0; i1 < N; i1++) {
        for (int i2 = i1 + 1; i2 < N; i2++) {
            // i1 on top of i2
            // bottom [i1] == top[i2]
            for (int j1 = 0; j1 < 6; j1++) {
                for (int j2 = 0; j2 < 6; j2++) {
                    if (A[i1][opp(j1)] == A[i2][j2]) {
                        V[6 * i1 + j1].push_back(6 * i2 + j2);
                    }
                }
            }
        }
    }

    vi visited(6 * N, 0);
    vi order;
    for (int i = 0; i < 6 * N; i++) {
        if (not visited[i]) dfs(i, visited, order);
    }
    reverse(order.begin(), order.end());

    vi dp(6 * N, -INF_INT);
    vi parent(6 * N, -1);
    int maxval = -1, maxidx;
    for (auto& x : order) {
        if (1 > dp[x]) {
            dp[x] = 1;
            parent[x] = -1;
        }
        for (auto& v : V[x]) {
            if (dp[x] + 1 > dp[v]) {
                dp[v] = dp[x] + 1;
                parent[v] = x;
            }
        }
        if (dp[x] > maxval) {
            maxval = dp[x];
            maxidx = x;
        }
    }
    cout << maxval << endl;
    print_sol(maxidx, parent);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;

        if (n_test) cout << endl;
        cout << "Case #" << ++n_test << endl;
        solve();
    }

    return 0;
}