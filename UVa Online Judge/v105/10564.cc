/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10564.cc
#  Description:     UVa Online Judge - 10564
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
const int MAXN = 21;
const int MAXS = 505;

int N, S;
int A[MAXN * 2][MAXN];
long long dp[MAXN * 2][MAXN][MAXS], ord[MAXN * 2][MAXN][MAXS];
int p[MAXN * 2][MAXN][MAXS], st[MAXN * 2][MAXN][MAXS];

void print_sol(int r, int c, int s) {
    if (p[r][c][s] == -1) {
        cout << c - 1 << " ";
        return;
    } else {
        print_sol(r - 1, p[r][c][s], s - A[r][c]);
        if (r <= N) {
            if (p[r][c][s] == c + 1)
                cout << "L";
            else
                cout << "R";
        } else {
            if (p[r][c][s] == c)
                cout << "L";
            else
                cout << "R";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> S) {
        if (N == 0 and S == 0) break;

        memset(dp, 0, sizeof(dp));
        memset(ord, 0, sizeof(ord));
        memset(p, -1, sizeof(p));
        memset(st, -1, sizeof(st));

        for (int i = 1, k = N; i <= N; i++, k--) {
            for (int j = 1; j <= k; j++) {
                cin >> A[i][j];
            }
        }
        for (int i = N + 1, k = 2; i <= 2 * N - 1; i++, k++) {
            for (int j = 1; j <= k; j++) {
                cin >> A[i][j];
            }
        }

        for (int i = 1; i <= N; i++) {
            dp[1][i][A[1][i]] = 1;
            p[1][i][A[1][i]] = -1;
            st[1][i][A[1][i]] = i;
            ord[1][i][A[1][i]] = 0;
        }
        for (int r = 2, k = N - 1; r <= N; r++, k--) {
            for (int c = 1; c <= k; c++) {
                for (int s = S; s >= 0; s--) {
                    dp[r][c][s] += dp[r - 1][c][s - A[r][c]];
                    if (c + 1 <= k + 1)
                        dp[r][c][s] += dp[r - 1][c + 1][s - A[r][c]];

                    if (c + 1 <= k + 1 and dp[r - 1][c + 1][s - A[r][c]] and
                        dp[r - 1][c][s - A[r][c]]) {
                        if (st[r - 1][c + 1][s - A[r][c]] !=
                            st[r - 1][c][s - A[r][c]]) {
                            if (st[r - 1][c + 1][s - A[r][c]] <
                                st[r - 1][c][s - A[r][c]]) {
                                st[r][c][s] = st[r - 1][c + 1][s - A[r][c]];
                                p[r][c][s] = c + 1;
                                ord[r][c][s] =
                                    2 * ord[r - 1][c + 1][s - A[r][c]];
                            } else {
                                st[r][c][s] = st[r - 1][c][s - A[r][c]];
                                p[r][c][s] = c;
                                ord[r][c][s] =
                                    2 * ord[r - 1][c][s - A[r][c]] + 1;
                            }
                        } else {
                            if (ord[r - 1][c + 1][s - A[r][c]] <
                                ord[r - 1][c][s - A[r][c]]) {
                                st[r][c][s] = st[r - 1][c + 1][s - A[r][c]];
                                p[r][c][s] = c + 1;
                                ord[r][c][s] =
                                    2 * ord[r - 1][c + 1][s - A[r][c]];
                            } else {
                                st[r][c][s] = st[r - 1][c][s - A[r][c]];
                                p[r][c][s] = c;
                                ord[r][c][s] =
                                    2 * ord[r - 1][c][s - A[r][c]] + 1;
                            }
                        }
                    } else {
                        if (c + 1 <= k + 1 and
                            dp[r - 1][c + 1][s - A[r][c]]) {  // L
                            p[r][c][s] = c + 1;
                            st[r][c][s] = st[r - 1][c + 1][s - A[r][c]];
                            ord[r][c][s] = 2 * ord[r - 1][c + 1][s - A[r][c]];
                        } else if (dp[r - 1][c][s - A[r][c]]) {  // R
                            p[r][c][s] = c;
                            st[r][c][s] = st[r - 1][c][s - A[r][c]];
                            ord[r][c][s] = 2 * ord[r - 1][c][s - A[r][c]] + 1;
                        }
                    }
                }
            }
        }

        for (int r = N + 1, k = 2; r <= 2 * N - 1; r++, k++) {
            for (int c = 1; c <= k; c++) {
                for (int s = S; s >= 0; s--) {
                    if (c - 1 >= 1)
                        dp[r][c][s] += dp[r - 1][c - 1][s - A[r][c]];
                    if (c <= k - 1) dp[r][c][s] += dp[r - 1][c][s - A[r][c]];

                    if (c - 1 >= 1 and c <= k - 1 and
                        dp[r - 1][c - 1][s - A[r][c]] and
                        dp[r - 1][c][s - A[r][c]]) {
                        if (st[r - 1][c - 1][s - A[r][c]] !=
                            st[r - 1][c][s - A[r][c]]) {
                            if (st[r - 1][c - 1][s - A[r][c]] <
                                st[r - 1][c][s - A[r][c]]) {
                                st[r][c][s] = st[r - 1][c - 1][s - A[r][c]];
                                p[r][c][s] = c - 1;
                                ord[r][c][s] =
                                    2 * ord[r - 1][c - 1][s - A[r][c]] + 1;
                            } else {
                                st[r][c][s] = st[r - 1][c][s - A[r][c]];
                                p[r][c][s] = c;
                                ord[r][c][s] = 2 * ord[r - 1][c][s - A[r][c]];
                            }
                        } else {
                            if (ord[r - 1][c - 1][s - A[r][c]] <
                                ord[r - 1][c][s - A[r][c]]) {
                                st[r][c][s] = st[r - 1][c - 1][s - A[r][c]];
                                p[r][c][s] = c - 1;
                                ord[r][c][s] =
                                    2 * ord[r - 1][c - 1][s - A[r][c]] + 1;
                            } else {
                                st[r][c][s] = st[r - 1][c][s - A[r][c]];
                                p[r][c][s] = c;
                                ord[r][c][s] = 2 * ord[r - 1][c][s - A[r][c]];
                            }
                        }
                    } else {
                        if (c <= k - 1 and dp[r - 1][c][s - A[r][c]]) {  // L
                            p[r][c][s] = c;
                            st[r][c][s] = st[r - 1][c][s - A[r][c]];
                            ord[r][c][s] = 2 * ord[r - 1][c][s - A[r][c]];
                        } else if (c - 1 >= 1 and
                                   dp[r - 1][c - 1][s - A[r][c]]) {  // R
                            p[r][c][s] = c - 1;
                            st[r][c][s] = st[r - 1][c - 1][s - A[r][c]];
                            ord[r][c][s] =
                                2 * ord[r - 1][c - 1][s - A[r][c]] + 1;
                        }
                    }
                }
            }
        }

        long long n_ans = 0;
        for (int c = 1; c <= N; c++) {
            n_ans += dp[2 * N - 1][c][S];
        }

        cout << n_ans << endl;

        if (n_ans == 0)
            cout << endl;
        else {
            int best_start = INF_INT, best_pos;
            long long best_order = 1e18;
            for (int c = 1; c <= N; c++) {
                if (dp[2 * N - 1][c][S]) {
                    if (st[2 * N - 1][c][S] < best_start) {
                        best_start = st[2 * N - 1][c][S];
                        best_order = ord[2 * N - 1][c][S];
                        best_pos = c;
                    } else if (st[2 * N - 1][c][S] == best_start and
                               ord[2 * N - 1][c][S] < best_order) {
                        best_order = ord[2 * N - 1][c][S];
                        best_pos = c;
                    }
                }
            }
            print_sol(2 * N - 1, best_pos, S);
            cout << endl;
        }
    }

    return 0;
}