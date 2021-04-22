/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        871.cc
#  Description:     UVa Online Judge - 871
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

const int MAXN = 30;

vector<string> A;
int dfs_state[MAXN][MAXN];
vi sizes;

void dfs(int r, int c) {
    if (dfs_state[r][c]) return;
    dfs_state[r][c] = sizes.size();
    sizes.back()++;

    for (int dy : {-1, 0, 1}) {
        for (int dx : {-1, 0, 1}) {
            if (dy == 0 and dx == 0) continue;
            if (r + dy < 0 or r + dy >= A.size()) continue;
            if (c + dx < 0 or c + dx >= A[r + dy].size()) continue;
            if (dfs_state[r + dy][c + dx]) continue;
            if (A[r + dy][c + dx] == '1') dfs(r + dy, c + dx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);
    getline(cin, line);
    while (T--) {
        A.clear();
        while (getline(cin, line)) {
            if (line == "") break;
            A.push_back(line);
        }

        memset(dfs_state, 0, sizeof(dfs_state));
        sizes.clear();
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (dfs_state[i][j]) continue;
                if (A[i][j] == '1') {
                    sizes.push_back(0);
                    dfs(i, j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < sizes.size(); i++) ans = max(ans, sizes[i]);
        cout << ans << endl;

        if (T) cout << endl;
    }
    return 0;
}