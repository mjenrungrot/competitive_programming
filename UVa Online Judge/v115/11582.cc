/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11582.cc
#  Description:     UVa Online Judge - 11582
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
const int MAXN = 1005;
uint64_t a, b;
int fib[MAXN * MAXN], memo[MAXN][MAXN];
int n;

int mod_pow(uint64_t a, uint64_t b, int mod) {
    if (b == 0) return 1;
    int tmp = mod_pow(a, b >> 1, mod);
    int ans = (tmp * tmp) % mod;
    if (b & 1) ans = (ans * (a % mod)) % mod;
    return static_cast<int>(ans);
}

void solve() {
    cin >> a >> b >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) memo[i][j] = -1;

    int mu = -1, lambda = -1;
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n * n + 2; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % n;
        if (memo[fib[i - 2]][fib[i - 1]] != -1) {
            mu = memo[fib[i - 2]][fib[i - 1]];
            lambda = i - mu;
            break;
        }
        memo[fib[i - 2]][fib[i - 1]] = i;
    }

    // a^b = mu + k*\lambda + r
    int rem =
        static_cast<int>(mod_pow(a, b, lambda));  // (mu + r) % lambda = rem
    int r = (lambda + rem - mu) % lambda;
    int ans = fib[mu + r];

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}