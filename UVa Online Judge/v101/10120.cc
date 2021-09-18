/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10120.cc
#  Description:     UVa Online Judge - 10120
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

int N, M;

int f() {
    queue<ii> Q;
    Q.push(ii(0, 1));

    while (not Q.empty()) {
        ii u = Q.front();
        Q.pop();
        if (u.first == M) return true;

        int jump_amount = 2 * u.second - 1;
        if (u.first + jump_amount <= N)
            Q.push(ii(u.first + jump_amount, u.second + 1));
        if (u.first - jump_amount >= 1)
            Q.push(ii(u.first - jump_amount, u.second + 1));
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;
        if (N >= 49) {
            cout << "Let me try!" << endl;
            continue;
        }

        int ans = f();
        if (ans)
            cout << "Let me try!" << endl;
        else
            cout << "Don't make fun of me!" << endl;
    }

    return 0;
}