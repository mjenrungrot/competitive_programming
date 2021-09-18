/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        274.cc
#  Description:     UVa Online Judge - 274
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
const int MAXN = 105;

int N, M, C;
int old_dp_m[MAXN][MAXN], dp_m[MAXN][MAXN], dp_c[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);

    getline(cin, line);
    while (T--) {
        getline(cin, line);
        vs tokens = split(line, regex("\\s"));
        N = stoi(tokens[0]);
        C = stoi(tokens[1]);
        M = stoi(tokens[2]);

        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                old_dp_m[i][j] = dp_m[i][j] = dp_c[i][j] = (i == j);
            }

        bool flag = false;
        while (getline(cin, line)) {
            if (line == "") break;
            tokens = split(line, regex("\\s"));
            int u = stoi(tokens[0]);
            int v = stoi(tokens[1]);
            if (u == -1 and v == -1) {
                flag = true;
                continue;
            }

            if (not flag) {
                dp_c[u][v] = true;
            } else {
                old_dp_m[u][v] = dp_m[u][v] = true;
            }
        }

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++) {
                    dp_c[i][j] |= dp_c[i][k] & dp_c[k][j];
                    dp_m[i][j] |= dp_m[i][k] & dp_m[k][j];
                }

        int ans1 = false;
        for (int i = 1; i <= N and not ans1; i++) {
            if (dp_m[M][i] and dp_c[C][i]) {
                ans1 = true;
            }
        }

        memset(dp_m, 0, sizeof(dp_m));
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) dp_m[i][j] = old_dp_m[i][j];
        for (int i = 1; i <= N; i++) {
            if (dp_c[C][i]) {
                for (int j = 1; j <= N; j++) dp_m[i][j] = dp_m[j][i] = false;
            }
        }
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++) {
                    dp_m[i][j] |= dp_m[i][k] & dp_m[k][j];
                }

        int ans2 = false;
        for (int i = 1; i <= N and not ans2; i++) {
            if (i != M and dp_m[M][i] and dp_m[i][M]) ans2 = true;
        }

        cout << (ans1 ? "Y" : "N") << " " << (ans2 ? "Y" : "N") << endl;
        if (T) cout << endl;
    }

    return 0;
}
