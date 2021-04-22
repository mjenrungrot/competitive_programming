/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10400.cc
#  Description:     UVa Online Judge - 10400
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

const int MAXN = 102;
const int MAXVAL = 64500;
const int OFFSET = 32000;
int dp[MAXN][MAXVAL];
int backtrack[MAXN][MAXVAL];
vi A;
int target;

int f(int idx, int val) {
    if (idx == A.size()) {
        return (val - OFFSET) == target;
    }

    if (dp[idx][val] != -1) return dp[idx][val];

    if ((val - OFFSET) + A[idx] <= 32000 and
        (val - OFFSET) + A[idx] >= -32000) {
        if (f(idx + 1, ((val - OFFSET) + A[idx]) + OFFSET)) {
            backtrack[idx][val] = '+';
            return dp[idx][val] = true;
        }
    }
    if ((val - OFFSET) - A[idx] <= 32000 and
        (val - OFFSET) - A[idx] >= -32000) {
        if (f(idx + 1, ((val - OFFSET) - A[idx]) + OFFSET)) {
            backtrack[idx][val] = '-';
            return dp[idx][val] = true;
        }
    }
    if ((val - OFFSET) * A[idx] <= 32000 and
        (val - OFFSET) * A[idx] >= -32000) {
        if (f(idx + 1, ((val - OFFSET) * A[idx]) + OFFSET)) {
            backtrack[idx][val] = '*';
            return dp[idx][val] = true;
        }
    }
    if ((val - OFFSET) / A[idx] <= 32000 and
        (val - OFFSET) / A[idx] >= -32000 and (val - OFFSET) % A[idx] == 0) {
        if (f(idx + 1, ((val - OFFSET) / A[idx]) + OFFSET)) {
            backtrack[idx][val] = '/';
            return dp[idx][val] = true;
        }
    }

    return dp[idx][val] = false;
}

void printsol(int idx, int val) {
    if (backtrack[idx][val] == '+') {
        cout << "+" << A[idx];
        printsol(idx + 1, ((val - OFFSET) + A[idx]) + OFFSET);
    } else if (backtrack[idx][val] == '-') {
        cout << "-" << A[idx];
        printsol(idx + 1, ((val - OFFSET) - A[idx]) + OFFSET);
    } else if (backtrack[idx][val] == '*') {
        cout << "*" << A[idx];
        printsol(idx + 1, ((val - OFFSET) * A[idx]) + OFFSET);
    } else if (backtrack[idx][val] == '/') {
        cout << "/" << A[idx];
        printsol(idx + 1, ((val - OFFSET) / A[idx]) + OFFSET);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        cin >> target;

        memset(dp, -1, sizeof(dp));
        memset(backtrack, -1, sizeof(backtrack));
        int possible = f(1, A[0] + OFFSET);

        if (not possible) {
            cout << "NO EXPRESSION" << endl;
        } else {
            cout << A[0];
            printsol(1, A[0] + OFFSET);
            cout << "=" << target << endl;
        }
    }

    return 0;
}