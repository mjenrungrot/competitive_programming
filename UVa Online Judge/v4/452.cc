/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        452.cc
#  Description:     UVa Online Judge - 452
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

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 26;

int days[MAXN];
vi V[MAXN];
vi visited;
vi order;

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;

    for (auto& v : V[u]) {
        if (not visited[v]) dfs(v);
    }
    order.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    int T;

    cin >> T;
    cin.ignore();
    cin.ignore();

    while (T--) {
        order.clear();
        visited = vi(MAXN, 0);

        for (int i = 0; i < MAXN; i++) {
            days[i] = 0;
            V[i].clear();
        }

        while (getline(cin, line) and line != "") {
            istringstream iss(line);
            string target, source;
            iss >> target;

            iss >> days[target[0] - 'A'];

            if (iss >> source) {
                for (auto& ch : source) {
                    V[ch - 'A'].push_back(target[0] - 'A');
                }
            }

            if (cin.eof()) break;
        }

        for (int i = 0; i < MAXN; i++) {
            if (not visited[i]) {
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());

        int ans = 0;
        vi dp(MAXN, 0);
        for (auto& x : order) {
            dp[x] = max(dp[x], days[x]);
            for (auto& v : V[x]) {
                dp[v] = max(dp[v], dp[x] + days[v]);
            }
            ans = max(ans, dp[x]);
        }
        cout << ans << endl;
        if (T) cout << endl;
    }
    return 0;
}