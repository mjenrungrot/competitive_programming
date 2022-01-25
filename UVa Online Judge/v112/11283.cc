/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11283.cc
#  Description:     UVa Online Judge - 11283
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
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
char A[4][4];
int used[4][4];
string query;

int scoring(int len) {
    if (len < 3) return 0;
    if (len <= 4) return 1;
    if (len == 5) return 2;
    if (len == 6) return 3;
    if (len == 7) return 5;
    return 11;
}

void f(int r, int c, int idx, bool& found) {
    if (found) return;
    if (idx == query.length()) {
        found = true;
        return;
    }

    used[r][c] = true;
    for (int k = 0; k < 8; k++) {
        if (r + dy[k] < 0 or r + dy[k] >= 4) continue;
        if (c + dx[k] < 0 or c + dx[k] >= 4) continue;
        if (A[r + dy[k]][c + dx[k]] != query[idx]) continue;
        if (used[r + dy[k]][c + dx[k]]) continue;
        f(r + dy[k], c + dx[k], idx + 1, found);
    }
    used[r][c] = false;
}

void solve() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) cin >> A[i][j];

    int N, total = 0;
    cin >> N;
    while (N--) {
        cin >> query;
        bool found = false;
        for (int i = 0; i < 4 and (not found); i++)
            for (int j = 0; j < 4 and (not found); j++) {
                if (A[i][j] != query[0]) continue;
                memset(used, 0, sizeof(used));
                f(i, j, 1, found);
            }

        if (found) total += scoring(query.length());
    }

    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Score for Boggle game #" << i << ": ";
        solve();
    }

    return 0;
}