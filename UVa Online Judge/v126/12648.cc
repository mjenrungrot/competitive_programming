/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12648.cc
#  Description:     UVa Online Judge - 12648
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
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

int N, M, I;
int memo[MAXN][2];
vi ages(MAXN), mapping(MAXN), V[MAXN];

int query(int num, int root) {
    if (memo[num][root] != -1) return memo[num][root];

    int ans = root ? INF_INT : ages[num];
    for (auto v : V[num]) ans = min(ans, query(v, false));
    return memo[num][root] = ans;
}

void update(int num1, int num2) {
    int tmp = mapping[num1];
    mapping[num1] = mapping[num2];
    mapping[num2] = tmp;

    tmp = ages[mapping[num1]];
    ages[mapping[num1]] = ages[mapping[num2]];
    ages[mapping[num2]] = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M >> I) {
        for (int i = 0; i < MAXN; i++) V[i].clear();
        memset(memo, -1, sizeof(memo));

        for (int i = 1; i <= N; i++) {
            cin >> ages[i];
            mapping[i] = i;
        }

        for (int i = 1; i <= M; i++) {
            int u, v;
            cin >> u >> v;
            V[v].push_back(u);
        }

        for (int i = 1; i <= I; i++) {
            string type;
            cin >> type;
            if (type == "P") {
                int num;
                cin >> num;
                memset(memo, -1, sizeof(memo));
                int ans = query(mapping[num], true);
                if (ans == INF_INT)
                    cout << "*" << endl;
                else
                    cout << ans << endl;
            } else if (type == "T") {
                int num1, num2;
                cin >> num1 >> num2;
                update(num1, num2);
            }

            // for (int k = 1; k <= N; k++)
            //     cout << k << ": " << mapping[k] << endl;
        }
    }

    return 0;
}