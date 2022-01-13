/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10518.cc
#  Description:     UVa Online Judge - 10518
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
int64_t n, b;

struct matrix {
    int A[3][3];
    matrix() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) A[i][j] = 0;
    }
};

inline struct matrix I() {
    struct matrix out;
    for (int i = 0; i < 3; i++) out.A[i][i] = 1;
    return out;
}

inline struct matrix
multiply(struct matrix& x, struct matrix& y) {
    struct matrix out;
    for (int i = 0; i < 3; i++)
        for (int k = 0; k < 3; k++)
            for (int j = 0; j < 3; j++) {
                out.A[i][j] = (out.A[i][j] + x.A[i][k] * y.A[k][j]) % b;
            }
    return out;
}

struct matrix fast_mod(struct matrix& x, uint64_t n) {
    if (n == 0) return I();
    struct matrix tmp = fast_mod(x, n >> 1);
    struct matrix ans = multiply(tmp, tmp);
    if (n & 1) ans = multiply(ans, x);
    return ans;
}

void solve() {
    if (n <= 1) {
        cout << 1 % b << endl;
        return;
    }

    /*
        [ 1  1  1 ]^k [ n_calls(n-1) ] = [ n_calls(n+k-1) ]
        [ 1  0  0 ]   [ n_calls(n-2) ]   [ n_calls(n+k-2) ]
        [ 0  0  1 ]   [   1          ]   [ 1              ]

        Set n = 2
        ans = mid row * [n_calls(1), n_calls(0), 1]
            = sum of mid row
    */

    struct matrix A;
    A.A[0][0] = A.A[0][1] = A.A[0][2] = A.A[1][0] = A.A[2][2] = 1;
    struct matrix B = fast_mod(A, n);
    cout << (B.A[1][0] + B.A[1][1] + B.A[1][2]) % b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> n >> b) {
        if (n == 0 and b == 0) break;
        cout << "Case " << ++n_test << ": " << n << " " << b << " ";
        solve();
    }

    return 0;
}