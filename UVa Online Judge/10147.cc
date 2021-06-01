/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10147.cc
#  Description:     UVa Online Judge - 10147
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
int N, M;
vii points;
vector<tuple<int, int, double>> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> N;

        points.clear();
        points.resize(N);
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
        }

        edges.clear();
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                double dist = hypot(get<0>(points[i]) - get<0>(points[j]),
                                    get<1>(points[i]) - get<1>(points[j]));
                edges.push_back({i, j, dist});
            }

        cin >> M;
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            edges.push_back({u, v, 0});
        }

        union_find S(N);
        sort(edges.begin(), edges.end(),
             [](tuple<int, int, double>& x, tuple<int, int, double>& y) {
                 return get<2>(x) < get<2>(y);
             });

        double total_length = 0;
        vii ans;
        for (int i = 0; i < edges.size(); i++) {
            int u = get<0>(edges[i]);
            int v = get<1>(edges[i]);
            auto w = get<2>(edges[i]);
            if (S.find_set(u) == S.find_set(v)) continue;
            S.union_set(u, v);
            if (w > 0) {
                total_length += w;
                ans.push_back({u + 1, v + 1});
            }
        }

        if (ans.size() == 0) {
            cout << "No new highways need" << endl;
        } else {
            for (auto x : ans) {
                cout << x.first << " " << x.second << endl;
            }
        }
        if (T) cout << endl;
    }

    return 0;
}