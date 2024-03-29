/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        157.cc
#  Description:     UVa Online Judge - 157
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
const int MAXN = 300;

int N;
vii V[MAXN];
tuple<char, char> lookup[MAXN];
map<tuple<char, char>, int> to_idx;

int conv(char a, char b) {
    if (to_idx.count({a, b})) return to_idx[{a, b}];
    lookup[to_idx.size()] = {a, b};
    return to_idx[{a, b}] = to_idx.size();
}
int conv_wrapper(tuple<char, char> x) { return conv(get<0>(x), get<1>(x)); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;

        char curr_line = line[0];
        tuple<char, char> curr, next;
        curr = {curr_line, line[2]};
        for (int j = 3; j < line.length(); j++) {
            if (line[j] != '=') {
                next = {curr_line, line[j]};
                V[conv_wrapper(curr)].emplace_back(conv_wrapper(next), 1);
                V[conv_wrapper(next)].emplace_back(conv_wrapper(curr), 1);

                curr = next;
            } else {
                vector<tuple<char, char>> stations;
                stations.push_back(curr);
                while (j < line.length() and line[j] == '=') {
                    stations.push_back({line[j + 1], line[j + 2]});
                    j += 3;
                }
                j--;

                for (int k1 = 0; k1 < stations.size(); k1++)
                    for (int k2 = k1 + 1; k2 < stations.size(); k2++) {
                        V[conv_wrapper(stations[k1])].push_back(
                            {conv_wrapper(stations[k2]), 3});
                        V[conv_wrapper(stations[k2])].push_back(
                            {conv_wrapper(stations[k1]), 3});
                    }
            }
        }
    }

    string query;
    while (cin >> query) {
        if (query == "#") break;

        tuple<char, char> start, target;
        start = {query[0], query[1]};
        target = {query[2], query[3]};

        auto cmp = [](ii x, ii y) { return x.first > y.first; };
        priority_queue<ii, vii, decltype(cmp)> pq(cmp);

        vi dist(MAXN, INF_INT);
        vi parent(MAXN, -1);

        dist[conv_wrapper(start)] = 0;
        pq.push({0, conv_wrapper(start)});

        while (not pq.empty()) {
            auto top_node = pq.top();
            auto u = get<1>(top_node);
            auto curr_d = get<0>(top_node);
            pq.pop();

            if (curr_d > dist[u]) continue;
            if (u == conv_wrapper(target)) {
                break;
            }

            for (auto next_node : V[u]) {
                auto v = get<0>(next_node);
                auto d = get<1>(next_node);

                if (parent[u] != -1 and
                    get<0>(lookup[u]) != get<0>(lookup[v]) and
                    get<0>(lookup[parent[u]]) != get<0>(lookup[u])) {
                    d = 0;
                }

                if (curr_d + d < dist[v]) {
                    dist[v] = curr_d + d;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        int curr = conv_wrapper(target);
        vector<tuple<char, char>> stations;

        while (curr != -1) {
            stations.push_back(lookup[curr]);
            curr = parent[curr];
        }

        cout << setw(3) << dist[conv_wrapper(target)] << ": ";

        char curr_line = get<0>(stations.back());
        cout << curr_line << get<1>(stations.back());
        for (int i = stations.size() - 2; i >= 0; i--) {
            if (get<0>(stations[i]) == curr_line) {
                cout << get<1>(stations[i]);
            } else {
                // lookahead for multiple changes
                if (i - 1 >= 0 and
                    get<0>(stations[i - 1]) != get<0>(stations[i])) {
                    continue;
                }

                cout << "=" << get<0>(stations[i]) << get<1>(stations[i]);
                curr_line = get<0>(stations[i]);
            }
        }
        cout << endl;
    }
    return 0;
}