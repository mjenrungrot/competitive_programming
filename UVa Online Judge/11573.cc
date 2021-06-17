/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11573.cc
#  Description:     UVa Online Judge - 11573
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
const int MAXR = 1005;

int R, C, visited[MAXR][MAXR];
string lines[MAXR];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) cin >> lines[i];

    int N;
    cin >> N;
    while (N--) {
        ii st, en;
        int r, c;
        cin >> r >> c;
        st = ii(r - 1, c - 1);

        cin >> r >> c;
        en = ii(r - 1, c - 1);

        deque<tuple<ii, int>> Q;
        memset(visited, 0, sizeof(visited));
        Q.push_back({st, 0});
        while (not Q.empty()) {
            auto u = Q.front();
            Q.pop_front();

            ii loc = get<0>(u);
            int d = get<1>(u);

            if (visited[loc.first][loc.second]) continue;
            visited[loc.first][loc.second] = true;

            if (loc == en) {
                cout << d << endl;
                break;
            }

            const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
            const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
            int curr_val = lines[loc.first][loc.second] - '0';

            for (int k = 0; k < 8; k++) {
                int newr = loc.first + dr[k];
                int newc = loc.second + dc[k];
                if (newr < 0 or newr >= R) continue;
                if (newc < 0 or newc >= C) continue;
                if (visited[newr][newc]) continue;
                if (k == curr_val) {
                    Q.push_front({{newr, newc}, d});
                } else {
                    Q.push_back({{newr, newc}, d + 1});
                }
            }
        }
    }

    return 0;
}