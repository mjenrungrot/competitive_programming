/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10653.cc
#  Description:     UVa Online Judge - 10653
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

int R, C, bomb[MAXN][MAXN], visited[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> R >> C) {
        if (R == 0 and C == 0) break;

        memset(bomb, 0, sizeof(bomb));
        memset(visited, 0, sizeof(visited));

        int n_rows;
        cin >> n_rows;
        while (n_rows--) {
            int r, n;
            cin >> r >> n;
            while (n--) {
                int c;
                cin >> c;
                bomb[r][c] = true;
            }
        }
        int st_r, st_c;
        cin >> st_r >> st_c;

        int en_r, en_c;
        cin >> en_r >> en_c;

        queue<iii> Q;
        Q.push({st_r, st_c, 0});
        while (not Q.empty()) {
            auto u = Q.front();
            Q.pop();

            int r = get<0>(u);
            int c = get<1>(u);
            int d = get<2>(u);
            if (r == en_r and c == en_c) {
                cout << d << endl;
                break;
            }

            if (visited[r][c]) continue;
            visited[r][c] = true;

            for (auto dr : {-1, 0, 1}) {
                for (auto dc : {-1, 0, 1}) {
                    if (abs(dr) + abs(dc) != 1) continue;
                    if (r + dr < 0 or r + dr >= R) continue;
                    if (c + dc < 0 or c + dc >= C) continue;
                    if (visited[r + dr][c + dc]) continue;
                    Q.push({r + dr, c + dc, d + 1});
                }
            }
        }
    }

    return 0;
}