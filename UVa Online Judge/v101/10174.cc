/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10174.cc
#  Description:     UVa Online Judge - 10174
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

/*
Claim 1: N can be written as A^2 - B^2 iff
    (1) N = 2k + 1    for some integer k
    (2) N = 4k        for some integer k

[1]: Let A = k+1, B = k.
     A^2 - B^2 = 2k + 1
               = N
[2]: Let A = (N/4+1), B = (N/4-1).
     A^2 - B^2 = (A-B)(A+B)
               = N

Claim 2: N can't be written as A^2 - B^2 iff
    N = 4k + 2
Proof:
    Suppose there is A and B s.t. A^2 - B^2 = 4k + 2.
    WLOG, let A = B + m for some integer m.
    Then, A^2-B^2 = 2m + 1.
    It follows that 2m + 1 = 4k + 2, or
        k = (2m - 1) / 4
    which is guaranteed to not be an integer.
    By contradiction, N can't be 4k+2.
*/
void solve1(int a) {
    if (a == 0) {
        cout << "0 0" << endl;
        return;
    }

    bool neg = (a < 0);
    a = abs(a);

    int A, B;
    if (a % 4 == 0) {
        A = a / 4 + 1;
        B = a / 4 - 1;
    } else if (a % 2 == 1) {
        int k = a / 2;
        A = k + 1;
        B = k;
    } else if (a % 4 == 2) {
        cout << "Bachelor Number." << endl;
        return;
    }

    if (neg)
        cout << B << " " << A << endl;
    else
        cout << A << " " << B << endl;
}

void solve2(int a, int b) {
    int ans = 0;
    for (int i = a; i <= b; i++)
        if (i % 4 == 2 and i != 0) ans++;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);

        int a, b;
        iss >> a;
        if (iss >> b) {
            solve2(a, b);
        } else {
            solve1(a);
        }
    }

    return 0;
}