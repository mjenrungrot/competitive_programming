/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10401.cc
#  Description:     UVa Online Judge - 10401
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
const int MAXN = 20;

string line;
int N;
long long dp[MAXN][MAXN];

int f(char ch) {
    if ('1' <= ch and ch <= '9') return ch - '0';
    return 10 + ch - 'A';
}

void solve() {
    memset(dp, 0, sizeof(dp));

    N = line.length();

    long long total = 1;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '?') {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = total;
                if (i - 1 >= 0 and j - 1 >= 1) dp[i][j] -= dp[i - 1][j - 1];
                if (i - 1 >= 0) dp[i][j] -= dp[i - 1][j];
                if (i - 1 >= 0 and j + 1 <= N) dp[i][j] -= dp[i - 1][j + 1];
            }

            total = 0;
            for (int j = 1; j <= N; j++) total += dp[i][j];
        } else {
            int val = f(line[i]);
            for (int j = 1; j <= N; j++) dp[i][j] = 0;
            dp[i][val] = total;
            if (i - 1 >= 0 and val - 1 >= 1) dp[i][val] -= dp[i - 1][val - 1];
            if (i - 1 >= 0) dp[i][val] -= dp[i - 1][val];
            if (i - 1 >= 0 and val + 1 <= N) dp[i][val] -= dp[i - 1][val + 1];
            total = dp[i][val];
        }
    }

    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> line) solve();

    return 0;
}