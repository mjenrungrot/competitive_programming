/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1025.cc
#  Description:     UVa Online Judge - 1025
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
const int MAXN = 55;
const int MAXT = 205;

int N, T;
int tt[MAXN];
int M1, M2;
int ff[MAXT][MAXN];
int bb[MAXT][MAXN];
int dp[MAXT][MAXN];

void solve() {
    memset(ff, 0, sizeof(ff));
    memset(bb, 0, sizeof(bb));
    for (int i = 0; i < MAXT; i++)
        for (int j = 0; j < MAXN; j++) dp[i][j] = INF_INT;
    dp[0][1] = 0;

    cin >> T;
    for (int i = 1; i < N; i++) cin >> tt[i];

    cin >> M1;
    for (int i = 1; i <= M1; i++) {
        int x;
        cin >> x;

        if (x <= T) ff[x][1] = true;
        for (int k = 1; k < N; k++) {
            x += tt[k];
            if (x <= T)
                ff[x][k + 1] = true;
            else
                break;
        }
    }

    cin >> M2;
    for (int i = 1; i <= M2; i++) {
        int x;
        cin >> x;

        if (x <= T) bb[x][N] = true;
        for (int k = N - 1; k >= 1; k--) {
            x += tt[k];
            if (x <= T)
                bb[x][k] = true;
            else
                break;
        }
    }

    for (int t = 1; t <= T; t++) {
        for (int i = 1; i <= N; i++) {
            // curr [t][i] from [prev t][i-1] or [prev t][i+1]

            // train from i-1 to i: must ends at t
            if (i - 1 >= 1 and t - tt[i - 1] >= 0 and ff[t][i]) {
                dp[t][i] = min(dp[t][i], dp[t - tt[i - 1]][i - 1]);
            }

            // train from i+1 to i: must ends at t
            if (i + 1 <= N and t - tt[i] >= 0 and bb[t][i]) {
                dp[t][i] = min(dp[t][i], dp[t - tt[i]][i + 1]);
            }

            // stay at i
            dp[t][i] = min(dp[t][i], dp[t - 1][i] + 1);
        }
    }

    if (dp[T][N] == INF_INT)
        cout << "impossible" << endl;
    else
        cout << dp[T][N] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;
        cout << "Case Number " << ++n_test << ": ";
        solve();
    }

    return 0;
}