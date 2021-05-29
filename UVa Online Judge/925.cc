/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        925.cc
#  Description:     UVa Online Judge - 925
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
const int MAXN = 125;

vs names;
map<string, int> to_idx;
int dp[MAXN][MAXN];

int conv(string x) {
    if (to_idx.count(x)) return to_idx[x];
    names.push_back(x);
    to_idx[x] = to_idx.size();
    return to_idx[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        names.clear();
        to_idx.clear();
        memset(dp, 0, sizeof(dp));

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            string x;
            cin >> x;
            conv(x);
        }

        int M;
        cin >> M;
        for (int i = 1; i <= M; i++) {
            string u, v;
            int k;
            cin >> v >> k;
            while (k--) {
                cin >> u;
                dp[conv(u)][conv(v)] = 1;
            }
        }

        set<ii> S;
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++) {
                    if (dp[i][k] and dp[k][j]) {
                        dp[i][j] |= dp[i][k] & dp[k][j];
                        S.insert({i, j});
                    }
                }

        for (auto x : S) {
            dp[x.first][x.second] = false;
        }

        vector<pair<string, vs>> ans;
        for (int i = 0; i < N; i++) {
            vs tmp;
            for (int j = 0; j < N; j++) {
                if (dp[j][i]) tmp.push_back(names[j]);
            }
            sort(tmp.begin(), tmp.end());
            ans.push_back({names[i], tmp});
        }
        sort(ans.begin(), ans.end(),
             [](pair<string, vs> x, pair<string, vs> y) {
                 return x.first < y.first;
             });

        for (auto x : ans) {
            if (x.second.size() == 0) continue;
            cout << x.first << " " << x.second.size();
            for (auto y : x.second) {
                cout << " " << y;
            }
            cout << endl;
        }
    }
    return 0;
}