/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        859.cc
#  Description:     UVa Online Judge - 859
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

class union_find {
    vi parent, sizes;

   public:
    union_find(int n) {
        parent.resize(n);
        sizes.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int find_set(int a) {
        if (a == parent[a]) return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sizes[a] < sizes[b]) swap(a, b);
            parent[b] = a;
            sizes[a] += sizes[b];
        }
    }
};

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

int R, C;
int board[MAXN][MAXN], visited[MAXN][MAXN];
const int dr[] = {0, 1, 0, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool newline = false;

    while (cin >> R >> C) {
        assert(R < MAXN and C < MAXN);
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));

        int P = 2 * C;
        for (int i = 1; i <= 2 * P; i++) {
            int r, c;
            cin >> r >> c;
            board[r][c] = true;
        }

        int st_r, st_c;
        cin >> st_r >> st_c;

        queue<tuple<ii, int, int>> Q;
        vector<iii> ans;
        Q.push({{st_r, st_c}, 3, 0});

        while (not Q.empty()) {
            auto u = Q.front();
            Q.pop();

            auto loc = get<0>(u);
            auto done = get<1>(u);
            auto d = get<2>(u);

            if (visited[loc.first][loc.second]) continue;
            visited[loc.first][loc.second] = true;

            if (d > 0) {
                ans.push_back({loc.first, loc.second, d});
            }

            for (int k = 0; k < 5; k++) {
                int newr = loc.first + dr[k];
                int newc = loc.second + dc[k];
                if (newr <= 0 or newr > R) continue;
                if (newc <= 0 or newc > C) continue;
                if (visited[newr][newc]) continue;

                if (not board[newr][newc]) {
                    if (k >= 3) continue;
                    if (not(done & (1 << 0))) continue;
                    Q.push({{newr, newc}, 0, d + 1});
                } else {
                    newr += dr[k];
                    newc += dc[k];
                    if (newr <= 0 or newr > R) continue;
                    if (newc <= 0 or newc > C) continue;
                    if (visited[newr][newc]) continue;
                    if (board[newr][newc]) continue;
                    if (not(done & (1 << 1))) continue;
                    Q.push({{newr, newc}, (1 << 1), d + 1});
                }
            }
        }

        if (newline) cout << endl;
        newline = true;

        sort(ans.begin(), ans.end(), [](iii& x, iii& y) {
            if (get<0>(x) != get<0>(y)) return get<0>(x) > get<0>(y);
            return get<1>(x) < get<1>(y);
        });
        for (auto& x : ans) {
            cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
        }
    }

    return 0;
}