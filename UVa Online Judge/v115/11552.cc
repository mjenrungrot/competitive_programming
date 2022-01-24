/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11552.cc
#  Description:     UVa Online Judge - 11552
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
const int MAXK = 1005;
const int MAXCH = 26;
int N;
string S;
int cost[MAXK][MAXCH][MAXCH], min_cost[MAXK][MAXCH], dp[MAXK][MAXCH];

void solve() {
    cin >> N >> S;
    assert(S.length() % N == 0);

    int k = S.length() / N;

    vector<map<int, int>> chunks_counter(k);
    for (int nk = 0; nk < k; nk++) {
        for (int i = nk * N; i < (nk + 1) * N; i++) {
            if (not chunks_counter[nk].count(S[i] - 'a'))
                chunks_counter[nk][S[i] - 'a'] = 0;
            chunks_counter[nk][S[i] - 'a']++;
        }
    }

    for (int nk = 0; nk < k; nk++) {
        for (int prevj = 0; prevj < MAXCH; prevj++)
            for (int j = 0; j < MAXCH; j++)
                min_cost[nk][j] = cost[nk][prevj][j] = INF_INT;

        for (auto x1 : chunks_counter[nk]) {
            for (auto x2 : chunks_counter[nk]) {
                if (chunks_counter[nk].size() == 1) {
                    cost[nk][x1.first][x2.first] = 1;
                } else {
                    if (x1.first == x2.first and
                        chunks_counter[nk][x1.first] > 1) {
                        cost[nk][x1.first][x2.first] =
                            chunks_counter[nk].size() + 1;
                    } else if (x1.first == x2.first) {
                        cost[nk][x1.first][x2.first] = INF_INT;
                    } else {
                        cost[nk][x1.first][x2.first] =
                            chunks_counter[nk].size();
                    }
                }
                min_cost[nk][x2.first] =
                    min(min_cost[nk][x2.first], cost[nk][x1.first][x2.first]);
            }
        }
    }

    // init
    for (int i = 0; i < k; i++)
        for (int j = 0; j < MAXCH; j++) dp[i][j] = INF_INT;

    // base case
    for (int j = 0; j < MAXCH; j++) {
        for (int prevj = 0; prevj < MAXCH; prevj++)
            dp[0][j] = min(dp[0][j], cost[0][prevj][j]);
    }

    // inductive case
    for (int nk = 1; nk < k; nk++) {
        for (int prevj = 0; prevj < MAXCH; prevj++) {
            for (int j = 0; j < MAXCH; j++) {
                dp[nk][j] =
                    min(dp[nk][j], dp[nk - 1][prevj] + cost[nk][prevj][j] - 1);

                dp[nk][j] = min(dp[nk][j], dp[nk - 1][prevj] + min_cost[nk][j]);
            }
        }
    }

    int ans = INF_INT;
    for (int ch = 0; ch < MAXCH; ch++) ans = min(ans, dp[k - 1][ch]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}