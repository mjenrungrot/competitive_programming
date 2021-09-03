/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        523.cc
#  Description:     UVa Online Judge - 523
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
int d[MAXN][MAXN], tax[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);

    int T = stoi(line);
    getline(cin, line);

    bool newline = false;
    while (T--) {
        memset(d, -1, sizeof(d));

        // read distance array
        getline(cin, line);
        vs tokens = split(line, regex("\\s"));
        int N = (int)tokens.size();
        for (int i = 1; i <= N; i++) {
            d[1][i] = stoi(tokens[i - 1]);
            if (d[1][i] == -1) d[1][i] = INF_INT;
        }

        for (int r = 2; r <= N; r++) {
            getline(cin, line);
            tokens = split(line, regex("\\s"));
            for (int c = 1; c <= N; c++) {
                d[r][c] = stoi(tokens[c - 1]);
                if (d[r][c] == -1) d[r][c] = INF_INT;
            }
        }

        // read tax
        getline(cin, line);
        tokens = split(line, regex("\\s"));
        for (int i = 1; i <= N; i++) {
            tax[i] = stoi(tokens[i - 1]);
        }

        // process query
        while (getline(cin, line)) {
            if (line == "") break;

            tokens = split(line, regex("\\s"));
            int start = stoi(tokens[0]);
            int target = stoi(tokens[1]);

            vi dist(MAXN, INF_INT);
            vi parent(MAXN, -1);
            dist[start] = 0;

            auto cmp = [](ii x, ii y) { return x.first > y.first; };
            priority_queue<ii, vii, decltype(cmp)> pq(cmp);
            pq.push({dist[start], start});
            while (not pq.empty()) {
                auto top_node = pq.top();
                pq.pop();

                auto curr_d = top_node.first;
                auto u = top_node.second;

                if (dist[u] < curr_d) continue;
                if (u == target) break;

                for (int j = 1; j <= N; j++) {
                    if (d[u][j] == INF_INT) continue;
                    if (curr_d + d[u][j] + tax[j] < dist[j]) {
                        parent[j] = u;
                        dist[j] = d[u][j] + tax[j] + curr_d;
                        pq.push({dist[j], j});
                    }
                }
            }

            stack<int> path;
            int curr = target;
            while (curr != -1) {
                path.push(curr);
                curr = parent[curr];
            }

            if (newline) cout << endl;
            newline = true;

            cout << "From " << start << " to " << target << " :" << endl;
            cout << "Path: ";
            while (true) {
                cout << path.top();
                path.pop();
                if (path.empty()) {
                    cout << endl;
                    break;
                } else {
                    cout << "-->";
                }
            }

            int extra_taxation = (start == target ? 0 : tax[target]);
            cout << "Total cost : " << dist[target] - extra_taxation << endl;
        }
    }
    return 0;
}