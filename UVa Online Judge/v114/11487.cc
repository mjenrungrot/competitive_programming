/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11487.cc
#  Description:     UVa Online Judge - 11487
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
const int MAXN = 11;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
const int MOD = 20437;

int N;
char A[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN], dist[MAXN][MAXN][MAXN][MAXN];
ii loc[30];
int visited[MAXN][MAXN];

void fill(int r1, int c1) {
    queue<ii> Q;
    Q.push({r1, c1});

    memset(visited, 0, sizeof(visited));
    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++) {
            dist[r1][c1][r][c] = INF_INT;
            dp[r1][c1][r][c] = 0;
        }

    dist[r1][c1][r1][c1] = 0;
    dp[r1][c1][r1][c1] = 1;

    while (not Q.empty()) {
        auto u = Q.front();
        Q.pop();

        auto r = u.first;
        auto c = u.second;
        if (visited[r][c]) continue;
        visited[r][c] = true;

        for (int k = 0; k < 4; k++) {
            if (r + dy[k] < 1 or r + dy[k] > N) continue;
            if (c + dx[k] < 1 or c + dx[k] > N) continue;
            if (A[r + dy[k]][c + dx[k]] == '#') continue;
            if (visited[r + dy[k]][c + dx[k]]) continue;
            if (A[r + dy[k]][c + dx[k]] != '.' and
                A[r + dy[k]][c + dx[k]] > A[r1][c1] + 1)
                continue;

            dp[r1][c1][r + dy[k]][c + dx[k]] += dp[r1][c1][r][c];
            dist[r1][c1][r + dy[k]][c + dx[k]] =
                min(dist[r1][c1][r + dy[k]][c + dx[k]], dist[r1][c1][r][c] + 1);
            Q.push({r + dy[k], c + dx[k]});
        }
    }
}

void solve() {
    int max_ch = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            if (A[i][j] >= 'A' and A[i][j] <= 'Z') {
                loc[A[i][j] - 'A'] = {i, j};
                max_ch = max(max_ch, A[i][j] - 'A' + 1);
            }
        }

    for (int i1 = 1; i1 <= N; i1++)
        for (int j1 = 1; j1 <= N; j1++) {
            if (A[i1][j1] >= 'A' and A[i1][j1] <= 'Z') fill(i1, j1);
        }

    int ans1 = 0, ans2 = 1;
    for (int i = 1; i < max_ch; i++) {
        int r1 = loc[i - 1].first;
        int c1 = loc[i - 1].second;
        int r2 = loc[i].first;
        int c2 = loc[i].second;

        if (dist[r1][c1][r2][c2] == INF_INT or dp[r1][c1][r2][c2] == 0) {
            cout << "Impossible" << endl;
            return;
        }

        ans1 += dist[r1][c1][r2][c2];
        ans2 *= dp[r1][c1][r2][c2];
        ans2 %= MOD;
    }

    cout << ans1 << " " << ans2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;
        cout << "Case " << ++n_test << ": ";
        if (n_test == 50 or N == 8) {
            debug(n_test, N);
        }
        solve();
    }

    return 0;
}