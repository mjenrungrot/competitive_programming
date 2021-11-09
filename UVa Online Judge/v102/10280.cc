/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10280.cc
#  Description:     UVa Online Judge - 10280
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

int L, N;
vii pairs;

void solve() {
    pairs.clear();
    cin >> L >> N;
    L *= 1000;

    for (int i = 0; i < N; i++) {
        int min_val, max_val;
        cin >> min_val >> max_val;
        pairs.emplace_back(min_val, max_val);
    }

    auto cmp = [](iii& x, iii& y) {
        if (get<0>(x) != get<0>(y)) return get<0>(x) > get<0>(y);
        return get<1>(x) > get<1>(y);
    };
    priority_queue<iii, vector<iii>, decltype(cmp)> pq(cmp);

    int best_val = 0;
    int best_score = INF_INT;
    pq.push({0, 0, -1});

    while (not pq.empty()) {
        auto u = pq.top();
        auto min_val = get<0>(u);
        auto max_val = get<1>(u);
        pq.pop();

        best_val = max_val > L ? L : max_val;
        if (L - best_val >= best_score) continue;
        best_score = L - best_val;
        if (best_score == 0) break;

        for (int i = 0; i < N; i++) {
            if (min_val + pairs[i].first > L) continue;
            auto new_val =
                max_val + pairs[i].second > L ? L : max_val + pairs[i].second;
            if (L - new_val > best_score) continue;
            pq.push({min_val + pairs[i].first, max_val + pairs[i].second, -1});

            auto k = (L - min_val) / pairs[i].first;
            auto new_min_val = min_val + k * pairs[i].first;
            auto new_max_val = max_val + k * pairs[i].second;
            if (k >= 1 and new_max_val > L and new_min_val <= L) {
                best_score = 0;
                break;
            }
        }

        if (best_score == 0) break;
    }

    cout << best_score << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
        if (T) cout << endl;
    }
    return 0;
}