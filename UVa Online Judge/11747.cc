/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11747.cc
#  Description:     UVa Online Judge - 11747
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
const int MAXN = 1005;

struct union_find {
    vi parent, height;

    union_find(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) parent[i] = i;
    }

    int find_root(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find_root(parent[u]);
    }

    void union_set(int u, int v) {
        u = find_root(u);
        v = find_root(v);
        parent[u] = v;
    }
};

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;

        union_find UF(N);

        vector<iii> edges;
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        sort(edges.begin(), edges.end(),
             [](iii x, iii y) { return get<2>(x) < get<2>(y); });

        vi ans;
        for (int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];
            int u = get<0>(edge);
            int v = get<1>(edge);
            int w = get<2>(edge);

            u = UF.find_root(u);
            v = UF.find_root(v);
            if (u == v) {
                ans.push_back(w);
                continue;
            }
            UF.union_set(u, v);
        }

        if (ans.size() == 0)
            cout << "forest" << endl;
        else {
            sort(ans.begin(), ans.end());
            bool space = false;
            for (auto& x : ans) {
                if (space) cout << " ";
                space = true;
                cout << x;
            }
            cout << endl;
        }
    }

    return 0;
}