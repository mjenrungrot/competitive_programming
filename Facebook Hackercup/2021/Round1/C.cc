/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        C.cc
#  Description:     Facebook Hacker Cup 2021 - Round1 - C
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
   public:
    vi parent, sizes;
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
const long long MOD = 1e9 + 7;
const int MAXN = 800005;
const int MAXK = 22;

long long ans, base;
int N;
vii V[MAXN];
int reachable1[MAXN][MAXK];  // reachable(i,j): nodes within subtree reachable
                             // from i-th node using weight >= j
int reachable2[MAXN][MAXK];  // reachable(i,j): nodes outside subtree reachable
                             // from i-th node using weight >= j

void f1(int u, int p) {
    for (int j = 0; j < MAXK; j++) reachable1[u][j] = 1;

    for (auto x : V[u]) {
        if (x.first == p) continue;
        f1(x.first, u);
        for (int j = 1; j <= x.second; j++)
            reachable1[u][j] += reachable1[x.first][j];
    }
}

void f2(int u, int p) {
    for (auto x : V[u]) {
        if (x.first == p) continue;
        for (int j = 1; j <= x.second; j++)
            reachable2[x.first][j] +=
                reachable2[u][j] + reachable1[u][j] - reachable1[x.first][j];
        f2(x.first, u);
    }
}

void f3(int u, int p) {
    for (auto x : V[u]) {
        if (x.first == p) continue;

        long long tmp = 0LL;
        for (int j = 1; j < MAXK - 1; j++) {
            long long P1 =
                (long long)reachable1[x.first][j] * reachable2[x.first][j];
            long long P2 = (long long)reachable1[x.first][j + 1] *
                           reachable2[x.first][j + 1];
            tmp += (long long)j * (P1 - P2);
        }
        ans = (ans * ((base - tmp) % MOD)) % MOD;
        f3(x.first, u);
    }
}

void run() {
    memset(reachable1, 0, sizeof(reachable1));
    memset(reachable2, 0, sizeof(reachable2));
    for (int i = 0; i < MAXN; i++) V[i].clear();

    cin >> N;
    vector<iii> edges;
    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        V[u].emplace_back(v, c);
        V[v].emplace_back(u, c);
        edges.push_back({u, v, c});
    }
    auto cmp = [](iii& x, iii& y) { return get<2>(x) > get<2>(y); };
    sort(edges.begin(), edges.end(), cmp);

    union_find S(N + 1);
    base = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = get<0>(edges[i]);
        int v = get<1>(edges[i]);
        int c = get<2>(edges[i]);

        if (S.find_set(u) == S.find_set(v)) {
            continue;
        } else {
            base += (long long)c * ((long long)S.sizes[S.find_set(u)] *
                                    S.sizes[S.find_set(v)]);
            assert((long long)c * ((long long)S.sizes[S.find_set(u)] *
                                   S.sizes[S.find_set(v)]) >=
                   0);
            assert(base >= 0);
            S.union_set(u, v);
        }
    }

    f1(1, -1);
    f2(1, -1);

    ans = 1LL;
    f3(1, -1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        run();
    }

    return 0;
}