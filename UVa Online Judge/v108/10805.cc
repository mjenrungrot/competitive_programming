/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10805.cc
#  Description:     UVa Online Judge - 10805
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

vs split(string line) {
    vs output;
    istringstream iss(line);
    string tmp;
    while (iss >> tmp) {
        output.push_back(tmp);
    }
    return output;
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
const int MAXN = 30;

int N, M;
map<ii, int> to_idx;
map<int, ii> inv_to_idx;

vi bfs(vi start, vvi& V, vi& p) {
    vi dist(V.size(), INF_INT), visited(V.size());
    queue<int> Q;

    for (auto& x : start) {
        dist[x] = 0;
        Q.push(x);
    }

    while (not Q.empty()) {
        auto u = Q.front();
        Q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto& v : V[u]) {
            if (visited[v]) continue;
            dist[v] = min(dist[v], dist[u] + 1);
            p[v] = u;
            Q.push(v);
        }
    }

    int max_val = *max_element(dist.begin(), dist.end());
    for (int i = 0; i < dist.size(); i++) {
        ii uv = inv_to_idx[i];
        if (uv.first != uv.second and dist[i] == max_val) dist[i] = max_val - 1;
    }

    return dist;
}

int f(int start, vvi& V) {
    vi p(V.size(), -1);
    vvi BFS_tree(V.size());

    vi dist1 = bfs({start}, V, p);
    for (int i = 0; i < V.size(); i++) {
        if (p[i] != -1) {
            BFS_tree[i].push_back(p[i]);
            BFS_tree[p[i]].push_back(i);
        }
    }

    p.assign(V.size(), -1);
    vi dist2 = bfs({start}, BFS_tree, p);
    int far = max_element(dist2.begin(), dist2.end()) - dist2.begin();

    p.assign(V.size(), -1);
    vi dist3 = bfs({far}, BFS_tree, p);
    far = max_element(dist3.begin(), dist3.end()) - dist3.begin();
    int diameter = dist3[far];

    return diameter / 2;
}

int conv(int u, int v) {
    if (u > v) swap(u, v);
    if (to_idx.count({u, v})) return to_idx[{u, v}];
    inv_to_idx[to_idx.size()] = {u, v};
    return to_idx[{u, v}] = to_idx.size();
}

void solve() {
    to_idx.clear();
    inv_to_idx.clear();

    vii edge_list;

    cin >> N >> M;
    for (int i = 0; i < N; i++) conv(i, i);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edge_list.emplace_back(u, v);
        conv(u, v);
    }

    vvi V(to_idx.size());
    for (auto& edge : edge_list) {
        int u = edge.first;
        int v = edge.second;
        int id_uu = conv(u, u);
        int id_uv = conv(u, v);
        int id_vv = conv(v, v);

        V[id_uu].push_back(id_uv);
        V[id_uv].push_back(id_vv);
        V[id_uv].push_back(id_uu);
        V[id_vv].push_back(id_uv);
    }

    int best_val = INF_INT;
    for (int i = 0; i < V.size(); i++) {
        int val = f(i, V);
        best_val = min(best_val, val);
    }

    cout << best_val << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":" << endl;
        solve();
        cout << endl;
    }
    return 0;
}