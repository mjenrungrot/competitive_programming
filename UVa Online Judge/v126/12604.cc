/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12604.cc
#  Description:     UVa Online Judge - 12604
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
string alpha, W, S;

uint64_t binpow(uint64_t base, uint64_t exp, uint64_t mod) {
    if (exp == 0) return 1LL;
    uint64_t tmp = binpow(base, exp >> 1, mod) % mod;
    uint64_t ans = (tmp * tmp) % mod;
    if (exp & 1) ans = (ans * base) % mod;
    return ans;
}

const long long p = 293;
const long long MOD = 1e9 + 9;
const long long MOD_INV = binpow(p, MOD - 2, MOD);

map<char, char> mapping(int k) {
    map<char, char> mapping;
    for (int i = 0; i < alpha.length(); i++)
        mapping[alpha[i]] = alpha[(i + k) % alpha.length()];
    return mapping;
}

void solve() {
    const long long p = 293;
    cin >> alpha >> W >> S;

    map<long long, int> hash_to_shift;
    for (int k = 0; k < alpha.length(); k++) {
        map<char, char> M = mapping(k);
        long long hash_val = 0;
        long long p_val = 1;
        for (int i = 0; i < W.length(); i++) {
            hash_val = (hash_val + p_val * M[W[i]]) % MOD;
            p_val = (p_val * p) % MOD;
        }
        hash_to_shift[hash_val] = k;
    }

    if (W.length() > S.length()) {
        cout << "no solution" << endl;
        return;
    }

    map<int, int> counter;
    long long curr_hash = 0;
    long long p_val = 1;
    for (int i = 0; i < W.length(); i++) {
        curr_hash = (curr_hash + p_val * S[i]) % MOD;
        p_val = (p_val * p) % MOD;
    }
    if (hash_to_shift.count(curr_hash)) {
        int k = hash_to_shift[curr_hash];
        if (not counter.count(k)) counter[k] = 0;
        counter[k]++;
    }

    long long p_left = 1;
    long long p_inv = MOD_INV;
    for (int en = W.length(); en < S.length(); en++) {
        curr_hash = (curr_hash - p_left * S[en - W.length()]) % MOD;
        curr_hash = (curr_hash + MOD) % MOD;
        curr_hash = (curr_hash + p_val * S[en]) % MOD;
        long long tmp_hash = (curr_hash * p_inv) % MOD;
        p_left = (p_left * p) % MOD;
        p_val = (p_val * p) % MOD;
        p_inv = (p_inv * MOD_INV) % MOD;
        if (hash_to_shift.count(tmp_hash)) {
            int k = hash_to_shift[tmp_hash];
            if (not counter.count(k)) counter[k] = 0;
            counter[k]++;
        }
    }

    vi ans;
    for (auto& x : counter) {
        if (counter[x.first] == 1) ans.push_back(x.first);
    }

    if (ans.size() == 0) {
        cout << "no solution" << endl;
    } else if (ans.size() == 1) {
        cout << "unique: " << ans[0] << endl;
    } else {
        cout << "ambiguous:";
        for (auto& x : ans) cout << " " << x;
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}