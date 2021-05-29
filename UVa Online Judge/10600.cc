/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10600.cc
#  Description:     UVa Online Judge - 10600
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
#define what_is(x) cerr << #x << " is " << x << endl;
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
const int MAXLV = 15;

int N, M;
vii V[MAXN];
vector<iii> edges;
int parent[MAXN], ranking[MAXN];

int mst_parent[MAXN][MAXLV], mst_height[MAXN];
ii mst_dist[MAXN][MAXLV];

int findset(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findset(parent[u]);
}

void unionset(int u, int v) {
    if (ranking[u] == ranking[v]) ranking[v]++;
    if (ranking[u] <= ranking[v])
        parent[u] = v;
    else
        parent[v] = u;
}

void dfs(int u, int p, int dis) {
    mst_parent[u][0] = p;
    mst_height[u] = (p == -1 ? 1 : mst_height[p] + 1);
    mst_dist[u][0] = {dis, -1};
    for (auto v : V[u]) {
        if (v.first == p) continue;
        dfs(v.first, u, v.second);
    }
}

ii combine(ii x, ii y) {
    vi v = {x.first, x.second, y.first, y.second};
    int top1 = -2, top2 = -3;
    for (auto c : v) {
        if (c >= top1) {
            top2 = top1;
            top1 = c;
        } else if (c >= top2) {
            top2 = c;
        }
    }
    return {top1, top2};
}

ii lca(int u, int v) {
    ii ans = {-2, -3};
    if (mst_height[u] < mst_height[v]) swap(v, u);

    for (int lv = MAXLV - 1; lv >= 0; lv--) {
        if (mst_height[u] - mst_height[v] >= (1 << lv)) {
            ans = combine(ans, mst_dist[u][lv]);
            u = mst_parent[u][lv];
        }
    }
    if (u == v) return ans;

    for (int lv = MAXLV - 1; lv >= 0; lv--) {
        if (mst_parent[u][lv] != -1 and mst_parent[v][lv] != -1 and
            mst_parent[u][lv] != mst_parent[v][lv]) {
            ans = combine(ans, combine(mst_dist[u][lv], mst_dist[v][lv]));
            u = mst_parent[u][lv];
            v = mst_parent[v][lv];
        }
    }
    ans = combine(ans, combine(mst_dist[u][0], mst_dist[v][0]));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        edges.clear();
        for (int i = 0; i < MAXN; i++) {
            V[i].clear();
            parent[i] = i, ranking[i] = 0;
        }
        memset(mst_parent, 0, sizeof(mst_parent));

        cin >> N >> M;

        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        sort(edges.begin(), edges.end(),
             [](iii& x, iii& y) { return get<2>(x) < get<2>(y); });

        int first_mst = 0;
        vi in_mst(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            int uu = findset(get<0>(edges[i]));
            int vv = findset(get<1>(edges[i]));

            if (findset(uu) == findset(vv)) {
                continue;
            } else {
                int w = get<2>(edges[i]);
                first_mst += w;
                in_mst[i] = true;
                V[uu].push_back(ii(vv, w));
                V[vv].push_back(ii(uu, w));
            }
            unionset(uu, vv);
        }

        // preprocess
        dfs(1, -1, -1);
        for (int lv = 1; lv < MAXLV; lv++) {
            for (int i = 1; i <= N; i++) {
                if (mst_parent[i][lv - 1] != -1) {
                    int middle = mst_parent[i][lv - 1];
                    mst_parent[i][lv] = mst_parent[middle][lv - 1];
                    mst_dist[i][lv] =
                        combine(mst_dist[i][lv - 1], mst_dist[middle][lv - 1]);
                }
            }
        }

        // process each edge
        int second_mst = INF_INT;
        for (int i = 0; i < edges.size(); i++) {
            if (in_mst[i]) continue;
            auto rem = lca(get<0>(edges[i]), get<1>(edges[i]));
            int w = get<2>(edges[i]);

            if (rem.first < 0) continue;
            second_mst = min(second_mst, first_mst + w - rem.first);
            if (w - rem.first < 0) {
                debug(w, rem, w - rem.first);
            }
        }

        cout << first_mst << " " << second_mst << endl;
    }
    return 0;
}