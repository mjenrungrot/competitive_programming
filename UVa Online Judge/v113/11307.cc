/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11307.cc
#  Description:     UVa Online Judge - 11307
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

vs split(string line) {
    vs output;
    istringstream iss(line);
    string tmp;
    while (iss >> tmp) {
        output.push_back(tmp);
    }
    return output;
}

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
const int MAX_COLOR = 10;

int N, in_deg[MAXN];
vi V[MAXN];
int dp[MAXN][MAX_COLOR];

int dfs(int u, int c) {
    if (dp[u][c] != INF_INT) return dp[u][c];

    int total = c;
    for (auto& v : V[u]) {
        int minval = INF_INT;
        for (int newc = 1; newc < MAX_COLOR; newc++) {
            if (newc == c) continue;
            minval = min(minval, dfs(v, newc));
        }
        total += minval;
    }
    return dp[u][c] = total;
}

void solve() {
    for (int i = 0; i < N; i++) {
        V[i].clear();
        in_deg[i] = 0;
        for (int j = 0; j < MAX_COLOR; j++) dp[i][j] = INF_INT;
    }
    string line;

    char ch;
    int u, v;
    for (int i = 1; i <= N; i++) {
        getline(cin, line);
        istringstream iss(line);

        iss >> u >> ch;
        while (iss >> v) {
            V[u].emplace_back(v);
            in_deg[v]++;
        }
    }

    int count_root = 0;
    int ans = INF_INT;
    for (int i = 0; i < N; i++) {
        count_root += (in_deg[i] == 0);
        if (in_deg[i] == 0) {
            for (int c = 1; c < MAX_COLOR; c++) {
                ans = min(ans, dfs(i, c));
            }
        }
    }
    cout << ans << endl;

    getline(cin, line);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (getline(cin, line)) {
        N = stoi(line);
        if (N == 0) break;
        solve();
    }

    return 0;
}