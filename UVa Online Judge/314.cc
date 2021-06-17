/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        314.cc
#  Description:     UVa Online Judge - 314
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
const int MAXN = 55;

int R, C;
int input[MAXN][MAXN], visited[MAXN][MAXN][4], possible[MAXN][MAXN];

// S W N E
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> R >> C) {
        if (R == 0 and C == 0) break;
        memset(input, 0, sizeof(input));
        memset(possible, 0, sizeof(possible));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) cin >> input[i][j];

        for (int i = 0; i < R - 1; i++)
            for (int j = 0; j < C - 1; j++) {
                if (input[i][j] or input[i + 1][j] or input[i][j + 1] or
                    input[i + 1][j + 1]) {
                    possible[i][j] = false;
                } else {
                    possible[i][j] = true;
                }
            }

        int st_r, st_c;
        int en_r, en_c;
        string di_str;

        cin >> st_r >> st_c >> en_r >> en_c >> di_str;
        st_r--, st_c--, en_r--, en_c--;

        int di_num;
        if (di_str == "south")
            di_num = 0;
        else if (di_str == "west")
            di_num = 1;
        else if (di_str == "north")
            di_num = 2;
        else
            di_num = 3;

        queue<tuple<ii, int, int>> Q;
        Q.push({{st_r, st_c}, di_num, 0});

        int ans = -1;
        while (not Q.empty()) {
            auto u = Q.front();
            Q.pop();

            auto loc = get<0>(u);
            auto di = get<1>(u);
            auto d = get<2>(u);
            if (visited[loc.first][loc.second][di]) continue;
            visited[loc.first][loc.second][di] = true;

            if (loc == ii(en_r, en_c)) {
                ans = d;
                break;
            }

            // rotate
            if (not visited[loc.first][loc.second][(di + 1) % 4]) {
                Q.push({loc, (di + 1) % 4, d + 1});
            }
            if (not visited[loc.first][loc.second][(di + 3) % 4]) {
                Q.push({loc, (di + 3) % 4, d + 1});
            }

            // move
            for (int k = 1; k <= 3; k++) {
                int newr = loc.first + k * dr[di];
                int newc = loc.second + k * dc[di];
                if (newr < 0 or newr >= R - 1) continue;
                if (newc < 0 or newc >= C - 1) continue;
                if (not possible[newr][newc]) break;
                if (visited[newr][newc][di]) continue;
                Q.push({{newr, newc}, di, d + 1});
            }
        }
        cout << ans << endl;
    }
    return 0;
}