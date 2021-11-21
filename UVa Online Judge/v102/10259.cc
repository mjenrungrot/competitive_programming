/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10259.cc
#  Description:     UVa Online Judge - 10259
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

int N, K;
int A[MAXN][MAXN];
int visited[MAXN][MAXN];
int dp[MAXN][MAXN];
vii order;
vii V[MAXN][MAXN];

void dfs(int r, int c) {
    if (visited[r][c]) return;
    visited[r][c] = true;

    for (auto& v : V[r][c]) {
        auto newr = v.first;
        auto newc = v.second;
        if (visited[newr][newc]) continue;
        dfs(newr, newc);
    }
    order.emplace_back(r, c);
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            visited[i][j] = 0;
            dp[i][j] = -INF_INT;
            V[i][j].clear();
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            for (auto d : vii({{-1, 0}, {1, 0}, {0, -1}, {0, 1}})) {
                for (int k = 1; k <= K; k++) {
                    auto newi = i + d.first * k;
                    auto newj = j + d.second * k;
                    if (newi < 0 or newi >= N or newj < 0 or newj >= N)
                        continue;
                    if (A[newi][newj] <= A[i][j]) continue;
                    V[i][j].emplace_back(newi, newj);
                }
            }
        }

    order.clear();
    dfs(0, 0);
    reverse(order.begin(), order.end());

    int ans = -INF_INT;
    for (auto& x : order) {
        dp[x.first][x.second] =
            max(dp[x.first][x.second], A[x.first][x.second]);
        for (auto& v : V[x.first][x.second]) {
            dp[v.first][v.second] =
                max(dp[v.first][v.second],
                    dp[x.first][x.second] + A[v.first][v.second]);
        }
        ans = max(ans, dp[x.first][x.second]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
        if (T) cout << endl;
    }

    return 0;
}