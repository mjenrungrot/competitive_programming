/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11377.cc
#  Description:     UVa Online Judge - 11377
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
const int MAXN = 2005;

int N, M, K, has_airport[MAXN];
vi V[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        memset(has_airport, 0, sizeof(has_airport));
        for (int i = 0; i < MAXN; i++) V[i].clear();

        for (int i = 1; i <= K; i++) {
            int x;
            cin >> x;
            has_airport[x] = true;
        }

        for (int i = 1; i <= M; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);
        }

        cout << "Case " << ++n_test << ":" << endl;

        int NQ;
        cin >> NQ;
        while (NQ--) {
            int st, en;
            cin >> st >> en;

            if (st == en) {
                cout << 0 << endl;
                continue;
            }

            deque<tuple<int, int>> Q;
            vi visited(MAXN);

            Q.push_back({st, not has_airport[st]});
            int ans = -1;
            while (not Q.empty()) {
                auto u = Q.front();
                Q.pop_front();

                auto node = get<0>(u);
                auto d = get<1>(u);

                if (visited[node]) continue;
                visited[node] = true;

                if (node == en) {
                    ans = d;
                    break;
                }

                for (auto& v : V[node]) {
                    if (visited[v]) continue;
                    if (has_airport[v])
                        Q.push_front({v, d});
                    else
                        Q.push_back({v, d + 1});
                }
            }
            cout << ans << endl;
        }
        cout << endl;
    }
    return 0;
}