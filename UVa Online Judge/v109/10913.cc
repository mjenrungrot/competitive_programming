/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10913.cc
#  Description:     UVa Online Judge - 10913
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
const int MAXN = 77;
const int MAXK = 6;

int N, K;
int A[MAXN][MAXN], neg_sum[MAXN][MAXN], cum_sum[MAXN][MAXN];
int dp[MAXK][MAXN][MAXN];

void solve() {
    memset(neg_sum, 0, sizeof(neg_sum));

    for (int i = 1; i <= N; i++) {
        neg_sum[i][0] = 0;
        cum_sum[i][0] = 0;
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            neg_sum[i][j] = neg_sum[i][j - 1] + (A[i][j] < 0);
            cum_sum[i][j] = cum_sum[i][j - 1] + A[i][j];
        }
    }

    for (int k = 0; k <= K; k++)
        for (int i = 0; i <= N; i++)
            for (int j = 1; j <= N; j++) dp[k][i][j] = -INF_INT;

    dp[0][0][1] = 0;

    for (int k = 0; k <= K; k++) {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                for (int prevc = 1; prevc <= N; prevc++) {
                    int prevk = k - (neg_sum[r][max(c, prevc)] -
                                     neg_sum[r][min(c, prevc) - 1]);

                    int sum_val = cum_sum[r][max(c, prevc)] -
                                  cum_sum[r][min(c, prevc) - 1];

                    if (prevk >= 0 and dp[prevk][r - 1][prevc] != -INF_INT) {
                        dp[k][r][c] =
                            max(dp[k][r][c], dp[prevk][r - 1][prevc] + sum_val);
                    }
                }
            }
        }
    }

    int ans = -INF_INT;
    for (int k = 0; k <= K; k++) ans = max(ans, dp[k][N][N]);

    if (ans == -INF_INT)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N >> K) {
        if (N == 0 and K == 0) break;
        cout << "Case " << ++n_test << ": ";
        solve();
    }

    return 0;
}