/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11695.cc
#  Description:     UVa Online Judge - 11695
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
const int MAXN = 2505;

int N;
vi V[MAXN];

vi dfs(int start, int ban_u, int ban_v, vi& p) {
    vi dist(N + 1, INF_INT);
    vi visited(N + 1);

    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

    while (not Q.empty()) {
        auto u = Q.front();
        Q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto& v : V[u]) {
            if (visited[v]) continue;
            if (min(u, v) == min(ban_u, ban_v) and
                max(u, v) == max(ban_u, ban_v))
                continue;

            dist[v] = dist[u] + 1;
            p[v] = u;
            Q.push(v);
        }
    }

    return dist;
}

void extra(vi& dist, vi& p, int& far, int& c) {
    int best_val = -INF_INT;
    for (int i = 1; i <= N; i++) {
        if (dist[i] < INF_INT and dist[i] > best_val) {
            far = i;
            best_val = dist[i];
        }
    }

    int curr = far;
    for (int i = 1; i <= dist[far] / 2; i++) curr = p[curr];
    c = curr;
}

void f(int u, int v, int& d, ii& old_pair, ii& new_pair) {
    int far1_1, c1_1, far1_2, c1_2;
    int far2_1, c2_1, far2_2, c2_2;

    vi p(N + 1, -1);
    vi dist_u1 = dfs(u, u, v, p);
    extra(dist_u1, p, far1_1, c1_1);

    p.assign(N + 1, -1);
    vi dist_u2 = dfs(far1_1, u, v, p);
    extra(dist_u2, p, far1_2, c1_2);

    p.assign(N + 1, -1);
    vi dist_v1 = dfs(v, u, v, p);
    extra(dist_v1, p, far2_1, c2_1);

    p.assign(N + 1, -1);
    vi dist_v2 = dfs(far2_1, u, v, p);
    extra(dist_v2, p, far2_2, c2_2);

    int d1 = dist_u2[far1_2];
    int d2 = dist_v2[far2_2];

    d = max(max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
    old_pair = {u, v};
    new_pair = {c1_2, c2_2};
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) V[i].clear();

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    int best_d = INF_INT;
    ii best_old_pair, best_new_pair, old_pair, new_pair;
    for (int u = 1; u <= N; u++) {
        for (auto& v : V[u]) {
            if (u < v) {
                int d;
                ii old_pair, new_pair;
                f(u, v, d, old_pair, new_pair);

                if (d < best_d) {
                    best_d = d;
                    best_old_pair = old_pair;
                    best_new_pair = new_pair;
                }
            }
        }
    }

    cout << best_d << endl;
    cout << best_old_pair.first << " " << best_old_pair.second << endl;
    cout << best_new_pair.first << " " << best_new_pair.second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}