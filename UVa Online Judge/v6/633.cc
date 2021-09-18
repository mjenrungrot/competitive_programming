/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        633.cc
#  Description:     UVa Online Judge - 633
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
const int MAXN = 43;

int R, C, exist[MAXN][MAXN], visited[MAXN][MAXN];

ii conv(string x) { return {x[0] - 'a', x[1] - '1'}; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        if (N == 0) break;
        memset(visited, false, sizeof(visited));
        memset(exist, false, sizeof(exist));

        R = 2 * N;
        C = 2 * N;

        int st_r, st_c;
        cin >> st_r >> st_c;

        int en_r, en_c;
        cin >> en_r >> en_c;

        int tmp_r, tmp_c;
        while (cin >> tmp_r >> tmp_c) {
            if (tmp_r == 0 and tmp_c == 0) break;
            exist[tmp_r][tmp_c] = true;
        }

        queue<tuple<int, int, int, int>> Q;
        Q.push({st_r, st_c, 0, -1});
        bool found = false;
        while (not Q.empty()) {
            auto uu = Q.front();
            Q.pop();

            int r = get<0>(uu);
            int c = get<1>(uu);
            int d = get<2>(uu);
            int last_type = get<3>(uu);
            if (r == en_r and c == en_c) {
                cout << "Result : " << d << endl;
                found = true;
                break;
            }

            if (visited[r][c] & (1 << last_type)) continue;
            visited[r][c] |= (1 << last_type);

            int dr_ref[] = {-2, -2, -1, -1, 1,  1, 2, 2,
                            2,  2,  -2, -2, -1, 0, 1, 0};
            int dc_ref[] = {-1, 1,  -2, 2,  -2, 2,  -1, 1,
                            2,  -2, 2,  -2, 0,  -1, 0,  1};
            int ty[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3};

            for (int k = 0; k < 14; k++) {
                int newr, newc;
                if (k < 12) {
                    newr = r + dr_ref[k];
                    newc = c + dc_ref[k];
                } else {
                    newr = dr_ref[k] ? 2 * N - r + 1 : r;
                    newc = dc_ref[k] ? 2 * N - c + 1 : c;
                }
                int curr_type = ty[k];
                if (curr_type == last_type) continue;
                if (newr <= 0 or newr > R) continue;
                if (newc <= 0 or newc > C) continue;
                if (visited[newr][newc] & (1 << curr_type)) continue;
                if (exist[newr][newc]) continue;
                Q.push({newr, newc, d + 1, curr_type});
            }
        }

        if (not found) {
            cout << "Solution doesn't exist" << endl;
        }
    }

    return 0;
}