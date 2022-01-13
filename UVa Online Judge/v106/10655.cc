/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10655.cc
#  Description:     UVa Online Judge - 10655
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
int64_t p, q;
int n;

struct matrix {
    __int128_t A[2][2];
    matrix() { A[0][0] = A[0][1] = A[1][0] = A[1][1] = 0; }
};

struct matrix I() {
    struct matrix out;
    out.A[0][0] = out.A[1][1] = 1;
    return out;
}

struct matrix
multiply(struct matrix& x, struct matrix& y) {
    struct matrix out;
    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++) {
            if (x.A[i][k] == 0) continue;
            for (int j = 0; j < 2; j++) out.A[i][j] += x.A[i][k] * y.A[k][j];
        }
    return out;
}

struct matrix fast_pow(struct matrix& x, int n) {
    if (n == 0) return I();
    struct matrix tmp = fast_pow(x, n >> 1);
    struct matrix ans = multiply(tmp, tmp);
    if (n & 1) ans = multiply(ans, x);
    return ans;
}

void solve() {
    /*
        a^n + b^n = (a^{n-1} + b^{n-1})(a+b) - ab(a^{n-2} + b^{n-2})

        Let f(n) = a^n + b^n. Where
            f(0) = 2
            f(1) = p

        We can write
            f(n+1) = p*f(n) - q*f(n-1)

        In matrix form,
            [p  -q]^k [f(n)  ] = [f(n+k)  ]
            [1   0]   [f(n-1)]   [f(n+k-1)]

        Let n = 1. It follows that,
            [p  -q]^k [p] = [f(k+1) ]
            [1   0]   [2]   [f(k)   ]

        If we let A = [[p,-q],[1,0]] and B = A^k, it must be that
            f(k) = B{1,0} * p + B{1,1} * 2
    */
    struct matrix A;
    A.A[0][0] = p;
    A.A[0][1] = -q;
    A.A[1][0] = 1;
    A.A[1][1] = 0;

    struct matrix B = fast_pow(A, n);
    int64_t ans = static_cast<int64_t>(B.A[1][0] * p + B.A[1][1] * 2);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> p >> q) {
        if (not(cin >> n)) break;
        solve();
    }

    return 0;
}