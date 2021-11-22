/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        757.cc
#  Description:     UVa Online Judge - 757
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
const int MAXT = 16 * 12 + 5;
const int MAXN = 27;

int N, H, T;
int f[MAXN], d[MAXN], t[MAXN];
int dp[MAXN][MAXT], p[MAXN][MAXT];

void print_sol(int n, int tt) {
    if (n > 1) {
        print_sol(n - 1, p[n][tt]);
        cout << ", ";
    }
    cout << (tt - t[n - 1] - p[n][tt]) * 5;
}

void solve() {
    cin >> H;
    T = H * 12;

    for (int i = 1; i <= N; i++) cin >> f[i];
    for (int i = 1; i <= N; i++) cin >> d[i];

    t[0] = 0;
    for (int i = 1; i < N; i++) cin >> t[i];

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= T; j++) dp[i][j] = -INF_INT;

    dp[0][0] = 0;
    p[0][0] = -1;
    for (int i = 1; i <= N; i++) {
        for (int tt = 0; tt <= T; tt++) {
            for (int prevt = 0; prevt <= tt - t[i - 1]; prevt++) {
                int our_time = tt - t[i - 1] - prevt;
                int maxt = (d[i] > 0) ? (f[i] + d[i] - 1) / d[i] : INF_INT;
                int start_val = f[i];
                int end_val, total;

                if (our_time <= maxt) {
                    end_val = f[i] - (our_time - 1) * d[i];
                    total = our_time * (start_val + end_val) / 2;
                } else {
                    end_val = f[i] - (maxt - 1) * d[i];
                    total = maxt * (start_val + end_val) / 2;
                }

                if (dp[i - 1][prevt] + total >= dp[i][tt]) {
                    dp[i][tt] = dp[i - 1][prevt] + total;
                    p[i][tt] = prevt;
                }
            }
        }
    }

    int best_ans = -INF_INT;
    int best_ans_idx = -1;
    for (int i = 1; i <= N; i++) {
        if (dp[i][T] > best_ans) {
            best_ans = dp[i][T];
            best_ans_idx = i;
        }
    }

    print_sol(best_ans_idx, T);
    for (int i = best_ans_idx + 1; i <= N; i++) {
        cout << ", 0";
    }
    cout << endl;
    cout << "Number of fish expected: " << best_ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool newline = false;
    while (cin >> N) {
        if (N == 0) break;
        if (newline) cout << endl;
        newline = true;
        solve();
    }
    return 0;
}