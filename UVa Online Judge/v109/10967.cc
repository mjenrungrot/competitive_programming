/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10967.cc
#  Description:     UVa Online Judge - 10967
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
const int MAXR = 105;
const int MAXC = 105;

int R, C;
string A[MAXR];
int door_cost[MAXR][MAXC];
int memo[MAXR][MAXC];

int dist(char c1, char c2) {
    if (c1 > c2) swap(c1, c2);
    if (c1 == c2) return 0;
    if (c1 == 'E' and c2 == 'W') return 2;
    if (c1 == 'N' and c2 == 'S') return 2;
    return 1;
}

void solve() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) cin >> A[i];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (A[i][j] != '.' and A[i][j] != '#') {
                cin >> door_cost[i][j];
            }
            memo[i][j] = INF_INT;
        }

    auto cmp = [](iii& x, iii& y) { return get<0>(x) > get<0>(y); };

    // (total, r, c)
    priority_queue<iii, vector<iii>, decltype(cmp)> pq(cmp);
    if (A[R - 1][0] != '#') pq.push({0, R - 1, 0});

    int ans = INF_INT;
    while (not pq.empty()) {
        auto u = pq.top();
        auto total = get<0>(u);
        auto r = get<1>(u);
        auto c = get<2>(u);
        pq.pop();

        if (total >= memo[r][c]) continue;
        memo[r][c] = total;

        if (r == 0 and c == C - 1) {
            ans = total;
            break;
        }

        // NESW : (dr, dc, direction, opp)
        for (auto& d : {tuple<int, int, int, int>(-1, 0, 'N', 'S'),
                        {1, 0, 'S', 'N'},
                        {0, -1, 'W', 'E'},
                        {0, 1, 'E', 'W'}}) {
            int newr = r + get<0>(d);
            int newc = c + get<1>(d);
            if (newr < 0 or newr >= R) continue;
            if (newc < 0 or newc >= C) continue;
            if (A[newr][newc] == '#') continue;
            if (A[newr][newc] != '.' and A[newr][newc] != get<3>(d)) continue;

            int add = 1;
            if (A[r][c] != '.') {
                add += (dist(A[r][c], get<2>(d))) * door_cost[r][c];
            }

            if (total + add < memo[newr][newc]) {
                pq.push({total + add, newr, newc});
            }
        }
    }

    if (ans == INF_INT) {
        cout << "Poor Kianoosh" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}