/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10477.cc
#  Description:     UVa Online Judge - 10477
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
const int MAXN = 22;

int R, C, visited[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    int n_test = 0;
    while (cin >> N >> S) {
        if (N == 0) break;
        cout << "Set " << ++n_test << ":" << endl;
        while (S--) {
            memset(visited, false, sizeof(visited));
            int st, en;
            cin >> st >> en;
            int st_r = (st - 1) / N + 1;
            int st_c = (st - 1) % N + 1;
            int en_r = (en - 1) / N + 1;
            int en_c = (en - 1) % N + 1;

            queue<tuple<int, int, int, int>> Q;
            Q.push({st_r, st_c, 0, 0});
            Q.push({st_r, st_c, 0, 1});
            Q.push({st_r, st_c, 0, 2});
            bool found = false;
            while (not Q.empty()) {
                auto uu = Q.front();
                Q.pop();

                int r = get<0>(uu);
                int c = get<1>(uu);
                int d = get<2>(uu);
                int last_type = get<3>(uu);
                if (r == en_r and c == en_c) {
                    cout << d << endl;
                    found = true;
                    break;
                }

                if (visited[r][c] & (1 << last_type)) continue;
                visited[r][c] |= (1 << last_type);

                int new_type = (last_type + 1) % 3;
                vi dr, dc;

                if (new_type == 0) {
                    dr = {-2, -2, -1, -1, 1, 1, 2, 2};
                    dc = {-1, 1, -2, 2, -2, 2, -1, 1};
                } else if (new_type == 1) {
                    dr = {-3, -3, -1, -1, 1, 1, 3, 3};
                    dc = {-1, 1, -3, 3, -3, 3, -1, 1};
                } else {
                    dr = {-1, 0, 1, 0, -1, -1, 1, 1};
                    dc = {0, -1, 0, 1, -1, 1, -1, 1};
                }
                assert(dr.size() == dc.size());

                for (int di = 0; di < dr.size(); di++) {
                    int newr = r + dr[di];
                    int newc = c + dc[di];
                    if (newr <= 0 or newr > N) continue;
                    if (newc <= 0 or newc > N) continue;
                    if (visited[newr][newc] & (1 << new_type)) continue;
                    if (new_type == 2 and di >= 4 and
                        (newr != en_r or newc != en_c))
                        continue;
                    Q.push({newr, newc, d + 1, new_type});
                }
            }
            if (not found) cout << "?" << endl;
        }
    }

    return 0;
}