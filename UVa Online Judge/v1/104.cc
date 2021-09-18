/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        104.cc
#  Description:     UVa Online Judge - 104
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

const int MAXN = 30;

int N, p[MAXN][MAXN][MAXN];
double dp[MAXN][MAXN][MAXN];

void print_path(int u, int v, int length) {
    if (length > 0)
        print_path(u, p[u][v][length], length - 1);
    else
        cout << u;

    cout << " " << v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) {
        memset(dp, 0, sizeof(dp));
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                if (i == j)
                    dp[i][j][0] = 1.0;
                else
                    cin >> dp[i][j][0];
            }

        for (int u = 1; u <= N; u++)
            for (int k = 1; k <= N; k++)
                for (int i = 1; i <= N; i++)
                    for (int j = 1; j <= N; j++) {
                        if (dp[i][k][u - 1] * dp[k][j][0] > dp[i][j][u]) {
                            dp[i][j][u] = dp[i][k][u - 1] * dp[k][j][0];
                            p[i][j][u] = k;
                        }
                    }

        bool possible = false;
        for (int length = 1; length <= N and not possible; length++) {
            for (int i = 1; i <= N; i++) {
                if (dp[i][i][length] > 1.01) {
                    print_path(i, i, length);
                    cout << endl;
                    possible = true;
                    break;
                }
            }
        }

        if (not possible) {
            cout << "no arbitrage sequence exists" << endl;
        }
    }

    return 0;
}