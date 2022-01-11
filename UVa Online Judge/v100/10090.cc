/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10090.cc
#  Description:     UVa Online Judge - 10090
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
long long N, c1, n1, c2, n2;

/*
    g = A*X + B*Y
      = A'*Y + B'*(X - (X/Y)*Y)
      = B'*X + (A' - B'(X/Y))*Y
*/
long long extendedGCD(long long x, long long y, long long& a, long long& b) {
    if (y == 0) {
        a = 1;
        b = 0;
        return x;
    }
    auto g = extendedGCD(y, x % y, a, b);
    auto tmp_a = a;
    auto tmp_b = b;
    a = tmp_b;
    b = tmp_a - tmp_b * (x / y);
    return g;
}

void solve() {
    // g = p*n1 + q*n2
    long long p, q;
    long long g = extendedGCD(n1, n2, p, q);
    if (N % g != 0) {
        cout << "failed" << endl;
        return;
    }

    // k = N / g
    // N = p * k * n1 + q * k * n2
    long long k = N / g;

    /*
    General Solution:
        N = (p * k + t * n2 / g) * n1 + (q * k - t * n1 / g) * n2

    Cost = (p * k + t * n2 / g) * c1  + (q * k - t * n1 / g) * c2
         = (p * k * c1 + q * k * c2) + (n2 / g * c1 - n1 / g * c2) * t
         = base + coeff * t

    We want p*k + t*n2/g >= 0 and q*k - t*n1/g >= 0. That is,
    t >= -p*k*g / n2      and  t <= q*k*g / n1
    */
    long long base = p * k * c1 + q * k * c2;
    long long coeff = n2 / g * c1 - n1 / g * c2;

    const long long at_least =
        static_cast<long long>(ceil(static_cast<long double>(-p) * k * g / n2));
    const long long at_most =
        static_cast<long long>(floor(static_cast<long double>(q) * k * g / n1));

    long long t;
    if (at_least > at_most) {
        cout << "failed" << endl;
        return;
    }

    // If coeff >= 0, cost is minimized when t is smallest
    if (coeff >= 0) t = at_least;

    // If coeff < 0, cost is minimized when t is biggest
    else if (coeff < 0)
        t = at_most;

    long long ans1 = static_cast<long long>(p * k + n2 / g * t);
    long long ans2 = static_cast<long long>(q * k - n1 / g * t);
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) {
        if (N == 0) break;
        cin >> c1 >> n1 >> c2 >> n2;
        solve();
    }

    return 0;
}
