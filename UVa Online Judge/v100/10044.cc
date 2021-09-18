/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10044.cc
#  Description:     UVa Online Judge - 10044
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
vvi V;
vi visited, dist;
map<string, int> to_idx;

int conv(string x) {
    if (to_idx.count(x)) return to_idx[x];
    return to_idx[x] = to_idx.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);
    int n_test = 0;
    while (T--) {
        cout << "Scenario " << ++n_test << endl;
        to_idx.clear();
        V.clear();

        getline(cin, line);
        vs tokens = split(line, regex("\\s"));
        assert(tokens.size() == 2);

        int n_papers = stoi(tokens[0]);
        int n_queries = stoi(tokens[1]);

        while (n_papers--) {
            getline(cin, line);
            vs names = split(line, regex(":"));
            vs tokens = split(names[0], regex("(,|\\s)"));
            tokens.erase(remove_if(tokens.begin(), tokens.end(),
                                   [](string x) { return x == ""; }),
                         tokens.end());

            assert(tokens.size() % 2 == 0);
            vs actual_names;
            for (int i = 0; i < tokens.size(); i += 2) {
                actual_names.push_back(tokens[i] + ", " + tokens[i + 1]);
                conv(actual_names.back());
            }

            V.resize(to_idx.size());
            for (int i = 0; i < actual_names.size(); i++)
                for (int j = i + 1; j < actual_names.size(); j++) {
                    V[conv(actual_names[i])].push_back(conv(actual_names[j]));
                    V[conv(actual_names[j])].push_back(conv(actual_names[i]));
                }
        }

        visited = vi(V.size(), 0);
        dist = vi(V.size(), -1);

        queue<ii> Q;
        Q.push({conv("Erdos, P."), 0});
        while (not Q.empty()) {
            auto u = Q.front();
            Q.pop();

            if (visited[u.first]) continue;
            visited[u.first] = true;
            dist[u.first] = u.second;

            for (auto& v : V[u.first]) {
                if (visited[v]) continue;
                Q.push({v, u.second + 1});
            }
        }

        while (n_queries--) {
            getline(cin, line);
            vs tokens = split(line, regex("(,|\\s)"));
            tokens.erase(remove_if(tokens.begin(), tokens.end(),
                                   [](string x) { return x == ""; }),
                         tokens.end());

            assert(tokens.size() == 2);
            string name = tokens[0] + ", " + tokens[1];

            int ans;
            if (not to_idx.count(name))
                ans = -1;
            else {
                if (dist[conv(name)] == -1)
                    ans = -1;
                else
                    ans = dist[conv(name)];
            }

            if (ans == -1)
                cout << name << " infinity" << endl;
            else
                cout << name << " " << ans << endl;
        }
    }
    return 0;
}