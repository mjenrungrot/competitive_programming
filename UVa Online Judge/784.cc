/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        784.cc
#  Description:     UVa Online Judge - 784
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

const int MAXN = 100;

int R, C;
vector<string> A;
int dfs_state[MAXN][MAXN];

int floodfill(int r, int c, char ch) {
    if (dfs_state[r][c]) return 0;
    dfs_state[r][c] = 1;

    int ans = 1;
    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) != 1) continue;
            if (r + dr < 0 or r + dr >= A.size()) continue;
            if (c + dc < 0 or c + dc >= A[r + dr].length()) continue;
            if (A[r + dr][c + dc] == ch) {
                ans += floodfill(r + dr, c + dc, ch);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);

    while (T--) {
        A.clear();
        while (true) {
            getline(cin, line);
            if (line[0] == '_') break;
            A.push_back(line);
        }

        memset(dfs_state, 0, sizeof(dfs_state));
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[i].length(); j++) {
                if (dfs_state[i][j]) continue;
                if (A[i][j] == '*') {
                    floodfill(i, j, ' ');
                }
            }

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (dfs_state[i][j])
                    cout << "#";
                else
                    cout << A[i][j];
            }
            cout << endl;
        }
        cout << line << endl;
    }
    return 0;
}