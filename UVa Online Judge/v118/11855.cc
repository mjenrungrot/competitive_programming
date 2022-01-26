/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11855.cc
#  Description:     UVa Online Judge - 11855
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
const int N_ALPHA = 256;
string line;

void solve() {
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    line += '$';
    int N = line.length();

    // 0-th iteration
    vi SA(N), RA(N), cnt(max(N, N_ALPHA), 0);
    for (int i = 0; i < N; ++i) cnt[line[i]]++;
    for (int i = 1; i < N_ALPHA; ++i) cnt[i] += cnt[i - 1];
    for (int i = 0; i < N; ++i) SA[--cnt[line[i]]] = i;
    RA[SA[0]] = 0;
    int classes = 1;
    for (int i = 1; i < N; i++) {
        if (line[SA[i]] != line[SA[i - 1]]) classes++;
        RA[SA[i]] = classes - 1;
    }

    // iteration step
    vi SA_n(N), RA_n(N);
    for (int h = 0; (1 << h) < N; ++h) {
        for (int i = 0; i < N; ++i) {
            SA_n[i] = SA[i] - (1 << h);
            if (SA_n[i] < 0) SA_n[i] += N;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < N; ++i) cnt[RA[SA_n[i]]]++;
        for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
        for (int i = N - 1; i >= 0; i--) SA[--cnt[RA[SA_n[i]]]] = SA_n[i];
        RA_n[SA[0]] = 0;
        classes = 1;
        for (int i = 1; i < N; ++i) {
            ii cur = {RA[SA[i]], RA[(SA[i] + (1 << h)) % N]};
            ii prev = {RA[SA[i - 1]], RA[(SA[i - 1] + (1 << h)) % N]};
            if (cur != prev) ++classes;
            RA_n[SA[i]] = classes - 1;
        }
        RA.swap(RA_n);
    }

    // LCP
    int k = 0, max_LCP = 0;
    vi LCP(N, 0);
    for (int i = 0; i < N; i++) {
        if (RA[i] == N - 1) {
            k = 0;
            continue;
        }
        int j = SA[RA[i] + 1];
        while (i + k < N and j + k < N and line[i + k] == line[j + k]) k++;
        LCP[RA[i]] = k;
        max_LCP = max(max_LCP, k);
        if (k) k--;
    }

    for (int i = 1; i <= max_LCP; i++) {
        int cnt = 0, ans = 0;
        for (int j = 0; j < N; j++) {
            if (LCP[j] >= i) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        if (ans == 0) break;
        cout << ans + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (getline(cin, line)) {
        if (line == "") break;
        solve();
        cout << endl;
    }

    return 0;
}