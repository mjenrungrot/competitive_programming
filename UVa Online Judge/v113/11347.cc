/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11347.cc
#  Description:     UVa Online Judge - 11347
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

// O(n) sieve up to n
vector<int> sieve(int n) {
    vector<int> lp(n, 0);
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() and primes[j] <= lp[i] and
                        i * primes[j] <= n;
             ++j)
            lp[i * primes[j]] = primes[j];
    }
    return primes;
}

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 1005;
vi primes = sieve(MAXN);
vector<vi> factors(MAXN, vi(primes.size()));

void add(vi& x, vi& y) {
    assert(x.size() == y.size());
    for (int i = 0; i < x.size(); i++) x[i] += y[i];
}

void solve() {
    string S;
    cin >> S;

    int k = 0;
    for (int i = S.length() - 1; i >= 0; i--) {
        if (S[i] == '!')
            k++;
        else
            break;
    }

    int num = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '!')
            break;
        else {
            num *= 10;
            num += (S[i] - '0');
        }
    }

    vi ans(primes.size());
    int target = (num % k == 0 ? k : num % k);
    for (int i = num; i >= target; i -= k) add(ans, factors[i]);

    __uint128_t n_divisors = 1;
    __uint128_t LIMIT = 1000000000000000000LL;
    for (int i = 0; i < ans.size(); i++) {
        n_divisors *= static_cast<__uint128_t>(ans[i] + 1);
        if (n_divisors > LIMIT) {
            cout << "Infinity" << endl;
            return;
        }
    }
    cout << static_cast<uint64_t>(n_divisors) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i < MAXN; i++) {
        int curr = i;
        for (int j = 0; j < primes.size(); j++) {
            while (curr % primes[j] == 0) {
                curr /= primes[j];
                factors[i][j]++;
            }
            if (curr == 1) break;
        }
    }

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}