/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        334.cc
#  Description:     UVa Online Judge - 334
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

int N;
vvi V, dp;
vs names;
map<string, int> to_idx;

int conv(string x) {
    if (to_idx.count(x)) return to_idx[x];
    to_idx[x] = to_idx.size();
    names.push_back(x);
    V.resize(to_idx.size());
    return to_idx[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;
        names.clear();
        V.clear();
        to_idx.clear();
        dp.clear();

        for (int i = 1; i <= N; i++) {
            int k;
            cin >> k;

            vi nodes;
            for (int i = 0; i < k; i++) {
                string name;
                cin >> name;
                nodes.push_back(conv(name));
            }

            for (int i = 1; i < k; i++) V[nodes[i - 1]].push_back(nodes[i]);
        }

        int M;
        cin >> M;
        for (int i = 1; i <= M; i++) {
            string u, v;
            cin >> u >> v;
            V[conv(u)].push_back(conv(v));
        }

        dp.resize(V.size(), vi(V.size()));
        for (int i = 0; i < V.size(); i++)
            for (int j = 0; j < V.size(); j++) dp[i][j] = (i == j);

        for (int u = 0; u < V.size(); u++) {
            for (auto v : V[u]) {
                dp[u][v] = true;
            }
        }

        for (int k = 0; k < V.size(); k++)
            for (int i = 0; i < V.size(); i++)
                for (int j = 0; j < V.size(); j++) {
                    dp[i][j] |= dp[i][k] & dp[k][j];
                }

        vii ans;
        for (int i = 0; i < V.size(); i++) {
            for (int j = i + 1; j < V.size(); j++) {
                if ((not dp[i][j]) and (not dp[j][i])) {
                    ans.push_back({i, j});
                }
            }
        }

        cout << "Case " << ++n_test;

        if (ans.size() == 0) {
            cout << ", no concurrent events." << endl;
        } else {
            cout << ", " << ans.size() << " concurrent events:" << endl;
            bool space = false;
            for (int i = 0; i < ans.size() and i < 2; i++) {
                auto x = ans[i];
                cout << "(" << names[x.first] << "," << names[x.second] << ") ";
            }
            cout << endl;
        }
    }

    return 0;
}