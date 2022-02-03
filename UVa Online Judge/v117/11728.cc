/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11728.cc
#  Description:     UVa Online Judge - 11728
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
vi sum(MAXN);
unordered_map<int, int> ans;
vi primes = sieve(MAXN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sum[0] = 0;
    sum[1] = 1;
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        int curr_sum = 1;
        int curr_num = i;
        for (int j = 0; j < primes.size(); j++) {
            if (primes[j] * primes[j] > curr_num) break;
            int tmp_num = 1;
            int tmp_sum = 1;
            while (curr_num % primes[j] == 0) {
                tmp_num *= primes[j];
                tmp_sum += tmp_num;
                curr_num /= primes[j];
            }
            curr_sum *= tmp_sum;
        }
        if (curr_num > 1) {
            curr_sum *= (1 + curr_num);
            curr_num = 1;
        }
        ans[curr_sum] = i;
    }

    int N, n_test = 0;
    while (cin >> N) {
        if (N == 0) break;

        cout << "Case " << ++n_test << ": ";
        if (ans.count(N))
            cout << ans[N] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}