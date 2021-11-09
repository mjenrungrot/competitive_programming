/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10187.cc
#  Description:     UVa Online Judge - 10187
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
const int MAXN = 1005;

int n_trains;
int ans[MAXN], best_time[MAXN];
vector<iii> G[MAXN];
map<string, int> to_idx;

int conv(string x) {
    if (to_idx.count(x)) return to_idx[x];
    return to_idx[x] = to_idx.size();
}

int canonical_time(int hr) {
    if (18 <= hr and hr <= 24) return hr;
    if (0 <= hr and hr <= 6) return 24 + hr;
    return hr;
}

void solve() {
    // init
    to_idx.clear();
    for (int i = 0; i < MAXN; i++) {
        G[i].clear();
        ans[i] = INF_INT;
        best_time[i] = -1;
    }

    // read graph
    cin >> n_trains;
    for (int i = 0; i < n_trains; i++) {
        string u, v;
        int start_hr, n_hours;
        cin >> u >> v >> start_hr >> n_hours;

        start_hr %= 24;
        int end_hr = (start_hr + n_hours) % 24;
        if (start_hr > 6 and start_hr < 18) continue;
        if (end_hr > 6 and end_hr < 18) continue;
        if (n_hours > 12) continue;

        G[conv(u)].emplace_back(conv(v), start_hr, end_hr);
    }

    string tmp;
    cin >> tmp;
    int start = conv(tmp);

    cin >> tmp;
    int target = conv(tmp);

    // pq
    auto cmp = [](iii& x, iii& y) {
        if (get<0>(x) != get<0>(y)) {
            return get<0>(x) > get<0>(y);
        }
        return canonical_time(get<1>(x)) > canonical_time(get<1>(y));
    };
    priority_queue<iii, vector<iii>, decltype(cmp)> pq(
        cmp);  // (n_liters, arrival_time, node)
    ans[start] = 0;
    best_time[start] = 18;
    pq.push({ans[start], best_time[start], start});

    while (not pq.empty()) {
        auto n_liters = get<0>(pq.top());
        auto curr_time = get<1>(pq.top());
        auto u = get<2>(pq.top());
        pq.pop();

        if (n_liters > ans[u]) continue;
        if (u == target) break;

        for (auto& x : G[u]) {
            auto v = get<0>(x);
            auto start_hr = get<1>(x);
            auto end_hr = get<2>(x);

            int new_val, new_time;
            if (canonical_time(curr_time) <= canonical_time(start_hr)) {
                new_val = ans[u];
                new_time = end_hr;
            } else {
                new_val = ans[u] + 1;
                new_time = end_hr;
            }

            if (new_val < ans[v] or
                (new_val == ans[v] and
                 canonical_time(new_time) < canonical_time(best_time[v]))) {
                ans[v] = new_val;
                best_time[v] = new_time;
                pq.push({ans[v], best_time[v], v});
            }
        }
    }

    if (ans[target] == INF_INT) {
        cout << "There is no route Vladimir can take." << endl;
    } else {
        cout << "Vladimir needs " << ans[target] << " litre(s) of blood."
             << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Test Case " << i << "." << endl;
        solve();
    }

    return 0;
}