/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10426.cc
#  Description:     UVa Online Judge - 10426
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
const int MAXN = 17;

int R, C, pos[4][2];
int d[4][MAXN][MAXN][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string name;
    int n_test = 0;
    while (cin >> name) {
        memset(d, -1, sizeof(d));

        cout << "Set#" << ++n_test << endl;
        cin >> R >> C;

        const int K = 4;
        for (int i = 0; i < K; i++) cin >> pos[i][0] >> pos[i][1];

        int mon_r, mon_c;
        cin >> mon_r >> mon_c;

        for (int i = 0; i < K; i++) {
            for (int ty = 0; ty < 2; ty++) {
                bool visited[MAXN][MAXN];
                memset(visited, 0, sizeof(visited));
                queue<iii> Q;
                Q.push({pos[i][0], pos[i][1], 0});
                while (not Q.empty()) {
                    auto u = Q.front();
                    Q.pop();

                    int r = get<0>(u);
                    int c = get<1>(u);
                    int dist = get<2>(u);

                    if (visited[r][c]) continue;
                    visited[r][c] = true;
                    d[i][r][c][ty] = dist;

                    int dr_ref[] = {-2, -2, -1, -1, 1, 1, 2, 2};
                    int dc_ref[] = {-1, 1, -2, 2, -2, 2, -1, 1};

                    for (int di = 0; di < 8; di++) {
                        int newr = r + dr_ref[di];
                        int newc = c + dc_ref[di];
                        if (newr <= 0 or newr > R) continue;
                        if (newc <= 0 or newc > C) continue;

                        if (ty == 0 and newr == mon_r and newc == mon_c)
                            continue;

                        Q.push({newr, newc, dist + 1});
                    }
                }
            }
        }

        int ans = INF_INT;
        for (int r = 1; r <= R; r++)
            for (int c = 1; c <= C; c++) {
                if (r == mon_r and c == mon_c) continue;
                int base = 0;
                int best_gain = 0;
                int n_imp = 0;
                for (int k = 0; k < K; k++) {
                    base += d[k][r][c][0];
                    best_gain = max(best_gain, d[k][r][c][0] - d[k][r][c][1]);
                    n_imp += (d[k][r][c][0] == -1);
                }

                int val;
                if (n_imp == 0) {
                    val = base - best_gain;
                } else if (n_imp == 1) {
                    for (int k = 0; k < K; k++) {
                        if (d[k][r][c][0] == -1)
                            best_gain = d[k][r][c][0] - d[k][r][c][1];
                        if (d[k][r][c][1] == -1) best_gain = -INF_INT;
                        val = base - best_gain;
                    }
                }
                ans = min(ans, val);
            }

        if (ans == INF_INT)
            cout << "Meeting is impossible." << endl;
        else
            cout << "Minimum time required is " << ans << " minutes." << endl;
    }

    return 0;
}