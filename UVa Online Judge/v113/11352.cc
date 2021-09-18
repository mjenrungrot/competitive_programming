/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11352.cc
#  Description:     UVa Online Judge - 11352
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
const int MAXN = 105;

int R, C;
int visited[MAXN][MAXN], possible[MAXN][MAXN];
string board[MAXN];

const int dr_knight[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc_knight[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dr_king[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc_king[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        memset(possible, 0, sizeof(possible));
        memset(visited, 0, sizeof(visited));

        cin >> R >> C;
        for (int i = 0; i < R; i++) cin >> board[i];

        int st_r = -1, st_c, en_r = -1, en_c;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'A' or board[i][j] == 'B') {
                    if (board[i][j] == 'A') st_r = i, st_c = j;
                    if (board[i][j] == 'B') en_r = i, en_c = j;
                    possible[i][j] = true;
                } else if (board[i][j] == 'Z')
                    possible[i][j] = false;
                else {
                    bool check = false;

                    for (int k = 0; k < 8 and not check; k++) {
                        if (i + dr_knight[k] < 0 or i + dr_knight[k] >= R)
                            continue;
                        if (j + dc_knight[k] < 0 or j + dc_knight[k] >= C)
                            continue;
                        if (board[i + dr_knight[k]][j + dc_knight[k]] == 'Z')
                            check = true;
                    }
                    possible[i][j] = not check;
                }
            }
        }
        assert(st_r != -1 and en_r != -1);

        queue<tuple<ii, int>> Q;
        Q.push({{st_r, st_c}, 0});
        int ans = -1;
        while (not Q.empty()) {
            auto u = Q.front();
            Q.pop();

            auto node = get<0>(u);
            auto d = get<1>(u);
            if (visited[node.first][node.second]) continue;
            visited[node.first][node.second] = true;

            if (node == ii(en_r, en_c)) {
                ans = d;
                break;
            }

            for (int k = 0; k < 8; k++) {
                if (node.first + dr_king[k] < 0 or node.first + dr_king[k] >= R)
                    continue;
                if (node.second + dc_king[k] < 0 or
                    node.second + dc_king[k] >= C)
                    continue;
                if (possible[node.first + dr_king[k]]
                            [node.second + dc_king[k]]) {
                    if (visited[node.first + dr_king[k]]
                               [node.second + dc_king[k]])
                        continue;
                    Q.push({{node.first + dr_king[k], node.second + dc_king[k]},
                            d + 1});
                }
            }
        }

        if (ans == -1)
            cout << "King Peter, you can't go now!" << endl;
        else
            cout << "Minimal possible length of a trip is " << ans << endl;
    }
    return 0;
}