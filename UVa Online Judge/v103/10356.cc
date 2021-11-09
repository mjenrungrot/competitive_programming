/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10356.cc
#  Description:     UVa Online Judge - 10356
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
const int MAXN = 505;

int N, M;
vi dist[2];
vii V[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N >> M) {
        for (int i = 0; i < MAXN; i++) V[i].clear();

        for (int i = 1; i <= M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            V[u].emplace_back(v, w);
            V[v].emplace_back(u, w);
        }

        dist[0] = vi(N, INF_INT);
        dist[1] = vi(N, INF_INT);
        dist[0][0] = 0;

        auto cmp = [](iii& x, iii& y) { return get<0>(x) > get<0>(y); };
        priority_queue<iii, vector<iii>, decltype(cmp)> pq(cmp);
        pq.push({dist[0][0], 0, 0});

        while (not pq.empty()) {
            auto u = pq.top();
            auto curr_dist = get<0>(u);
            auto curr_node = get<1>(u);
            auto curr_parity = get<2>(u);
            pq.pop();

            if (curr_dist > dist[curr_parity][curr_node]) continue;

            for (auto& x : V[curr_node]) {
                if (curr_dist + x.second < dist[1 ^ curr_parity][x.first]) {
                    dist[1 ^ curr_parity][x.first] = curr_dist + x.second;
                    pq.push({dist[1 ^ curr_parity][x.first], x.first,
                             1 ^ curr_parity});
                }
            }
        }

        cout << "Set #" << ++n_test << endl;
        if (dist[0][N - 1] == INF_INT)
            cout << "?" << endl;
        else
            cout << dist[0][N - 1] << endl;
    }

    return 0;
}