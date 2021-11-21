/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11957.cc
#  Description:     UVa Online Judge - 11957
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
const int MAXN = 105;
const int MOD = 1000007;

int N;
char A[MAXN][MAXN];
int dp[MAXN][MAXN];

int check(int r, int c) {
    if (r < 1 or r > N) return false;
    if (c < 1 or c > N) return false;
    return true;
}

void solve() {
    cin >> N;
    for (int i = N; i >= 1; i--)
        for (int j = 1; j <= N; j++) cin >> A[i][j];

    memset(dp, 0, sizeof(dp));

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (A[r][c] == 'W') {
                dp[r][c] = 1;
            }

            if (dp[r][c]) {
                if (check(r + 1, c - 1) and A[r + 1][c - 1] != 'B') {
                    dp[r + 1][c - 1] += dp[r][c];
                    dp[r + 1][c - 1] %= MOD;
                } else if (check(r + 1, c - 1) and A[r + 1][c - 1] == 'B' and
                           check(r + 2, c - 2) and A[r + 2][c - 2] == '.') {
                    dp[r + 2][c - 2] += dp[r][c];
                    dp[r + 2][c - 2] %= MOD;
                }
                if (check(r + 1, c + 1) and A[r + 1][c + 1] != 'B') {
                    dp[r + 1][c + 1] += dp[r][c];
                    dp[r + 1][c + 1] %= MOD;
                } else if (check(r + 1, c + 1) and A[r + 1][c + 1] == 'B' and
                           check(r + 2, c + 2) and A[r + 2][c + 2] == '.') {
                    dp[r + 2][c + 2] += dp[r][c];
                    dp[r + 2][c + 2] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int c = 1; c <= N; c++) {
        ans += dp[N][c];
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}