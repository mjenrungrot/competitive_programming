/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1192.cc
#  Description:     UVa Online Judge - 1192
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
string query, seq;
vector<string> ans;
int best_score = -INF_INT;

int LCS() {
    vvi dp(query.length() + 1, vi(seq.length() + 1, -INF_INT));
    dp[0][0] = 0;

    for (int i = 0; i <= query.length(); i++)
        for (int j = 0; j <= seq.length(); j++) {
            if (i - 1 >= 0 and j - 1 >= 0 and query[i - 1] == seq[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 5);
            } else {
                if (i - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] - 7);
                if (j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] - 7);
                if (i - 1 >= 0 and j - 1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 4);
            }
        }

    return dp.back().back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string tmp;
    cin >> tmp;
    cin >> query;

    while (cin >> tmp) {
        cin >> seq;
        int score = LCS();
        if (score > best_score) {
            best_score = score;
            ans.clear();
        }
        if (score == best_score) ans.emplace_back(seq);
    }

    cout << "The query sequence is:" << endl;
    cout << query << endl;
    cout << endl;
    cout << "The most similar sequences are:" << endl;
    for (auto& x : ans) {
        cout << endl;
        cout << x << endl;
        cout << "The similarity score is: " << best_score << endl;
    }

    return 0;
}