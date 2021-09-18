/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10436.cc
#  Description:     UVa Online Judge - 10436
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
const int MAXN = 25;

int N, cost[MAXN], dp1[MAXN][MAXN], dp2[MAXN][MAXN], p[MAXN][MAXN];
vs names;
map<string, int> to_idx;

int conv(string x) {
    if (to_idx.count(x)) return to_idx[x];
    names.push_back(x);
    to_idx[x] = to_idx.size();
    return to_idx[x];
}

void print_path(int u, int v) {
    if (u != v) print_path(u, p[u][v]);
    if (u != v) cout << " ";
    cout << names[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        names.clear();
        to_idx.clear();
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                dp1[i][j] = dp2[i][j] = (i == j ? 0 : INF_INT);
                p[i][j] = i;
            }

        cin >> N;
        for (int i = 1; i <= N; i++) {
            string name;
            int val;
            cin >> name >> val;
            cost[conv(name)] = val;
        }

        int M;
        cin >> M;
        for (int i = 1; i <= M; i++) {
            string u, v;
            int len;
            cin >> u >> v >> len;
            dp1[conv(u)][conv(v)] = dp1[conv(v)][conv(u)] = 2 * len;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp2[i][j] = (i == j ? cost[i] : cost[i] + cost[j]);

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int prev = dp1[i][j] + dp2[i][j];
                    int next =
                        dp1[i][k] + dp1[k][j] + dp2[i][k] + dp2[k][j] - cost[k];
                    if (next < prev) {
                        dp1[i][j] = dp1[i][k] + dp1[k][j];
                        dp2[i][j] = dp2[i][k] + dp2[k][j] - cost[k];
                        p[i][j] = p[k][j];
                    }
                }
            }
        }

        if (n_test) cout << endl;
        cout << "Map #" << ++n_test << endl;
        int Q;
        cin >> Q;
        for (int i = 1; i <= Q; i++) {
            cout << "Query #" << i << endl;
            string u, v;
            int n_people;
            cin >> u >> v >> n_people;

            int uu = conv(u);
            int vv = conv(v);
            print_path(uu, vv);
            cout << endl;

            double ans = 1.1 * (dp1[uu][vv] + dp2[uu][vv]) / (double)n_people;
            cout << "Each passenger has to pay : " << fixed << setprecision(2)
                 << ans << " taka" << endl;
        }
    }
    return 0;
}