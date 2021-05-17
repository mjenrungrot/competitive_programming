/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1223.cc
#  Description:     UVa Online Judge - 1223
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
const int MAXN = 505;

int B, P, d[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) d[i][j] = INF_INT;

        cin >> B >> P;

        for (int i = 0; i <= P; i++) {
            int k;
            cin >> k;
            if (i == 0) {
                while (k--) {
                    int v;
                    cin >> v;
                    d[i][v] = 0;
                }
            } else {
                while (k--) {
                    int w, v;
                    cin >> w >> v;
                    d[i][v] = min(d[i][v], w);
                }
            }
        }

        for (int k = 0; k <= P + 1; k++)
            for (int i = 0; i <= P; i++)
                for (int j = 0; j <= P; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }

        // Find the least n s.t. n*x - (n-1) >= B. The answer is n-1.
        // That is, the smallest n s.t. n*(x-1) >= B-1 or n >= (B-1)/(x-1)

        if (d[0][0] == INF_INT) {
            cout << 0 << endl;
        } else {
            int answer = (B - 1 + (d[0][0] - 2)) / (d[0][0] - 1) - 1;
            cout << answer << endl;
        }
    }

    return 0;
}