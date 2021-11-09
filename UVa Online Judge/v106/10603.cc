/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10603.cc
#  Description:     UVa Online Judge - 10603
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

struct node {
    int x, y, z, total;

    node(int total, int x, int y, int z) : total(total), x(x), y(y), z(z) {}
};

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 202;
int a, b, c, d;
int memo1[MAXN][MAXN][MAXN], memo2[MAXN];

void solve() {
    cin >> a >> b >> c >> d;

    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            for (int k = 0; k <= c; k++) memo1[i][j][k] = INF_INT;
    for (int i = 0; i <= d; i++) memo2[i] = INF_INT;

    auto cmp = [](node& x, node& y) {
        return x.total > y.total;
    };  // higer move has lower priority
    priority_queue<node, vector<node>,
                   decltype(cmp)> pq(cmp);  // (x, y, z)
    pq.push(node(0, 0, 0, c));

    int can;
    while (not pq.empty()) {
        node u = pq.top();
        int n_moves = u.total;
        int x1 = u.x;
        int x2 = u.y;
        int x3 = u.z;
        pq.pop();

        if (n_moves >= memo2[d]) continue;
        if (n_moves >= memo1[x1][x2][x3]) continue;
        memo1[x1][x2][x3] = n_moves;

        memo2[x1] = min(memo2[x1], n_moves);
        memo2[x2] = min(memo2[x2], n_moves);
        memo2[x3] = min(memo2[x3], n_moves);

        // c -> a
        can = min(a - x1, x3);
        if (can) pq.push(node(n_moves + can, x1 + can, x2, x3 - can));

        // c -> b
        can = min(b - x2, x3);
        if (can) pq.push(node(n_moves + can, x1, x2 + can, x3 - can));

        // a -> b
        can = min(b - x2, x1);
        if (can) pq.push(node(n_moves + can, x1 - can, x2 + can, x3));

        // a -> c
        can = min(c - x3, x1);
        if (can) pq.push(node(n_moves + can, x1 - can, x2, x3 + can));

        // b -> a
        can = min(a - x1, x2);
        if (can) pq.push(node(n_moves + can, x1 + can, x2 - can, x3));

        // b -> c
        can = min(c - x3, x2);
        if (can) pq.push(node(n_moves + can, x1, x2 - can, x3 + can));
    }

    int best_n_moves = INF_INT;
    int best_ans = -INF_INT;
    for (int i = d; i >= 0; i--) {
        if (memo2[i] != INF_INT) {
            best_n_moves = memo2[i];
            best_ans = i;
            break;
        }
    }
    cout << best_n_moves << " " << best_ans << endl;
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