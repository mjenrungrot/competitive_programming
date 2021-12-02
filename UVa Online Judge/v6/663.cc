/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        663.cc
#  Description:     UVa Online Judge - 663
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

struct window {
    int x_min, y_min, x_max, y_max;

    window(int x_min, int y_min, int x_max, int y_max)
        : x_min(x_min), y_min(y_min), x_max(x_max), y_max(y_max) {}
};

int N;

int MCBM(int u, vi& visited, vi& match, vvi& V) {
    if (visited[u]) return 0;
    visited[u] = true;

    for (auto& v : V[u]) {
        if (match[v] == -1 or MCBM(match[v], visited, match, V)) {
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }

    return 0;
}

int matching(vvi& V) {
    vi visited(V.size());
    vi match(V.size(), -1);
    int n_pairs = 0;
    for (int i = 0; i < N; i++) {
        visited.assign(V.size(), 0);
        n_pairs += MCBM(i, visited, match, V);
    }
    return n_pairs;
}

void solve() {
    vector<window> windows;
    vector<ii> points;

    for (int i = 0; i < N; i++) {
        int x_min, y_min, x_max, y_max;
        cin >> x_min >> x_max >> y_min >> y_max;
        windows.emplace_back(x_min, y_min, x_max, y_max);
    }

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    vvi V(2 * N);
    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++) {
            if (windows[u].x_min <= points[v].first and
                points[v].first <= windows[u].x_max and
                windows[u].y_min <= points[v].second and
                points[v].second <= windows[u].y_max) {
                V[u].push_back(N + v);
            }
        }

    int possible = false;
    vi match(N, -1);
    for (int u = 0; u < N; u++) {
        for (int j = 0; j < V[u].size(); j++) {
            int v = V[u][0];
            V[u].erase(V[u].begin());
            int xx = matching(V);
            if (xx != N) {
                possible = true;
                match[u] = v;
            }
            V[u].push_back(v);
        }
    }

    if (not possible) {
        cout << "none" << endl;
    } else {
        bool space = false;
        for (int i = 0; i < N; i++) {
            if (match[i] == -1) continue;
            char ch = i + 'A';
            if (space) cout << " ";
            space = true;
            cout << "(" << ch << "," << (match[i] - N + 1) << ")";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;
        cout << "Heap " << ++n_test << endl;
        solve();
        cout << endl;
    }

    return 0;
}