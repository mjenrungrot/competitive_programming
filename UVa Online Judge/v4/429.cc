/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        429.cc
#  Description:     UVa Online Judge - 429
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
const int MAXN = 205;

vs vocab;
map<string, int> to_idx;
vi V[MAXN];

int conv(string x) {
    if (to_idx.count(x)) return to_idx[x];
    return to_idx[x] = to_idx.size();
}

int diff(string x, string y) {
    assert(x.length() == y.length());
    int ans = 0;
    for (int i = 0; i < x.length(); i++) ans += (x[i] != y[i]);
    return ans;
}

int run(int st, int en) {
    queue<int> Q;
    vi dist(MAXN, INF_INT);
    vi visited(MAXN);

    Q.push(st);
    dist[st] = 0;

    while (not Q.empty()) {
        auto u = Q.front();
        Q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        if (u == en) return dist[u];

        for (auto v : V[u]) {
            if (visited[v]) continue;
            dist[v] = min(dist[v], dist[u] + 1);
            Q.push(v);
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);
    getline(cin, line);  // empty line

    while (T--) {
        vocab.clear();
        to_idx.clear();
        for (int i = 0; i < MAXN; i++) V[i].clear();

        while (getline(cin, line)) {
            if (line == "*") break;
            vocab.push_back(line);
            conv(line);
        }

        // build graph
        for (int i = 0; i < vocab.size(); i++) {
            for (int j = i + 1; j < vocab.size(); j++) {
                if (vocab[i].length() == vocab[j].length() and
                    diff(vocab[i], vocab[j]) == 1) {
                    V[i].push_back(j);
                    V[j].push_back(i);
                }
            }
        }

        // queries
        while (getline(cin, line)) {
            if (line == "") break;

            vs tokens = split(line, regex("\\s"));
            cout << tokens[0] << " " << tokens[1] << " "
                 << run(conv(tokens[0]), conv(tokens[1])) << endl;
        }

        if (T) cout << endl;
    }

    return 0;
}