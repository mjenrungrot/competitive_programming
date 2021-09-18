/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10947.cc
#  Description:     UVa Online Judge - 10947
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
const double INF = 1e9;
const int MAXN = 105;

int N;
double K, M;
int dp[MAXN][MAXN];
vector<tuple<double, double, double>> V;

double find_dist(ddd x, ddd y) {
    return sqrt((get<0>(x) - get<0>(y)) * (get<0>(x) - get<0>(y)) +
                (get<1>(x) - get<1>(y)) * (get<1>(x) - get<1>(y))) -
           get<2>(x) - get<2>(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> K >> M) {
        V.clear();
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) dp[i][j] = (i == j ? true : false);

        double x, y, r;
        cin >> x >> y >> r;
        V.push_back({x, y, r});

        cin >> x >> y >> r;
        V.push_back({x, y, r});

        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> x >> y >> r;
            V.push_back({x, y, r});
        }

        for (int i = 0; i < V.size(); i++)
            for (int j = i + 1; j < V.size(); j++) {
                double raw_dist = find_dist(V[i], V[j]);
                double time_required = raw_dist / M;
                if (time_required > K) {
                    continue;
                } else {
                    dp[i][j] = dp[j][i] = true;
                }
            }

        for (int k = 0; k < V.size(); k++)
            for (int i = 0; i < V.size(); i++)
                for (int j = 0; j < V.size(); j++) {
                    dp[i][j] |= dp[i][k] & dp[k][j];
                }

        if (dp[0][1]) {
            cout << "Larry and Ryan will escape!" << endl;
        } else {
            cout << "Larry and Ryan will be eaten to death." << endl;
        }
    }

    return 0;
}