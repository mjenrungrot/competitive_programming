/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        869.cc
#  Description:     UVa Online Judge - 869
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

int N, M;
int dp1[MAXN][MAXN], dp2[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));

        for (int i = 0; i < MAXN; i++) dp1[i][i] = dp2[i][i] = true;

        cin >> N;
        for (int i = 0; i < N; i++) {
            char u, v;
            cin >> u >> v;
            dp1[u - 'A'][v - 'A'] = dp1[v - 'A'][u - 'A'] = true;
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            char u, v;
            cin >> u >> v;
            dp2[u - 'A'][v - 'A'] = dp2[v - 'A'][u - 'A'] = true;
        }

        for (int k = 0; k < MAXN; k++) {
            for (int i = 0; i < MAXN; i++) {
                for (int j = 0; j < MAXN; j++) {
                    dp1[i][j] |= dp1[i][k] & dp1[k][j];
                    dp2[i][j] |= dp2[i][k] & dp2[k][j];
                }
            }
        }

        bool check = true;
        for (int i = 0; i < MAXN and check; i++)
            for (int j = 0; j < MAXN and check; j++) {
                if (dp1[i][j] == dp2[i][j])
                    continue;
                else
                    check = false;
            }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        if (T) cout << endl;
    }
    return 0;
}