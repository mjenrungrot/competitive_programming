/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10459.cc
#  Description:     UVa Online Judge - 10459
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
const int MAXN = 5005;

int N, highest_depth[MAXN];
vi V[MAXN];

vi f(vi start, vi& p) {
    vi dist(MAXN, INF_INT);
    vi visited(MAXN);

    queue<int> Q;
    for (auto& x : start) {
        Q.push(x);
        dist[x] = 0;
    }

    while (not Q.empty()) {
        auto u = Q.front();
        Q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto& v : V[u]) {
            if (visited[v]) continue;
            dist[v] = dist[u] + 1;
            p[v] = u;
            Q.push(v);
        }
    }

    return dist;
}
void solve() {
    for (int i = 1; i <= N; i++) V[i].clear();
    for (int i = 1; i <= N; i++) {
        int n, x;
        cin >> n;
        while (n--) {
            cin >> x;
            V[i].push_back(x);
        }
    }

    vi worst_nodes, best_nodes;
    vi p(MAXN, -1);
    vi dist1 = f({1}, p);

    int max_val = -INF_INT;
    for (int i = 1; i <= N; i++) max_val = max(max_val, dist1[i]);
    for (int i = 1; i <= N; i++)
        if (dist1[i] == max_val) worst_nodes.push_back(i);

    p.assign(MAXN, -1);
    vi dist2 = f({worst_nodes[0]}, p);
    max_val = -INF_INT;

    int curr = -1;
    for (int i = 1; i <= N; i++) max_val = max(max_val, dist2[i]);
    for (int i = 1; i <= N; i++)
        if (dist2[i] == max_val) {
            worst_nodes.push_back(i);
            curr = i;
        }

    sort(worst_nodes.begin(), worst_nodes.end());
    worst_nodes.erase(unique(worst_nodes.begin(), worst_nodes.end()),
                      worst_nodes.end());

    int diameter = max_val;
    int counter = 0;
    while (p[curr] != -1) {
        counter++;
        curr = p[curr];
        if (diameter % 2 == 0) {
            if (counter == diameter / 2) best_nodes.push_back(curr);
        } else {
            if (counter == diameter / 2 or counter == diameter / 2 + 1)
                best_nodes.push_back(curr);
        }
    }
    sort(best_nodes.begin(), best_nodes.end());

    cout << "Best Roots  :";
    for (auto& x : best_nodes) cout << " " << x;
    cout << endl;

    cout << "Worst Roots :";
    for (auto& x : worst_nodes) cout << " " << x;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) solve();

    return 0;
}