/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10246.cc
#  Description:     UVa Online Judge - 10246
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
#define what_is(x) cerr << #x << " is " << x << endl;
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
const int MAXC = 85;

int C, R, Q;
int cost[MAXC];
int dp[MAXC][MAXC], p[MAXC][MAXC], exp_cost[MAXC][MAXC];

void check(int u, int v, int& c) {
    if (u != v) check(u, p[u][v], c);
    c = max(c, cost[v]);
    debug(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> C >> R >> Q) {
        if (C == 0 and R == 0 and Q == 0) break;

        memset(cost, 0, sizeof(cost));
        for (int i = 1; i <= C; i++) {
            cin >> cost[i];
        }
        for (int i = 0; i < MAXC; i++)
            for (int j = 0; j < MAXC; j++) {
                dp[i][j] = (i == j ? 0 : INF_INT);
                exp_cost[i][j] = max(cost[i], cost[j]);
            }

        for (int i = 1; i <= R; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            dp[u][v] = dp[v][u] = w;
            exp_cost[u][v] = exp_cost[v][u] = max(cost[u], cost[v]);
        }

        // 1: dp is guaranteed
        // 2: exp is guaranteed
        // 3: dp + exp is guaranteed
        for (int n_times = 1; n_times <= 3; n_times++)
            for (int k = 1; k <= C; k++)
                for (int i = 1; i <= C; i++)
                    for (int j = 1; j <= C; j++) {
                        if (dp[i][k] + dp[k][j] +
                                max(exp_cost[i][k], exp_cost[k][j]) <
                            dp[i][j] + exp_cost[i][j]) {
                            dp[i][j] = dp[i][k] + dp[k][j];
                            exp_cost[i][j] =
                                max(exp_cost[i][k], exp_cost[k][j]);
                        }
                    }

        if (n_test) cout << endl;
        cout << "Case #" << ++n_test << endl;
        for (int i = 1; i <= Q; i++) {
            int u, v;
            cin >> u >> v;

            if (dp[u][v] == INF_INT) {
                cout << -1 << endl;
                continue;
            }

            int c = dp[u][v] + exp_cost[u][v];
            cout << c << endl;
        }
    }

    return 0;
}