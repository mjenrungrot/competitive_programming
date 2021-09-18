/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        657.cc
#  Description:     UVa Online Judge - 657
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

const int MAXN = 55;

int N, M;
int dfs_state[MAXN][MAXN];
vector<string> A;
vii candidates;

void dfs(int r, int c, int flag) {
    if (dfs_state[r][c]) return;
    dfs_state[r][c] = 1;

    if (not flag and A[r][c] == 'X') {
        candidates.push_back(ii(r, c));
    }

    for (int dy : {-1, 0, 1}) {
        for (int dx : {-1, 0, 1}) {
            if (dy == 0 and dx == 0) continue;
            if (abs(dy) + abs(dx) == 2) continue;
            if (r + dy < 0 or r + dy >= A.size()) continue;
            if (c + dx < 0 or c + dx >= A[r + dy].length()) continue;
            if (flag) {
                if (A[r + dy][c + dx] == '.') continue;
                if (A[r + dy][c + dx] == '*') continue;
            } else {
                if (A[r + dy][c + dx] == '.') continue;
            }
            if (dfs_state[r + dy][c + dx]) continue;
            dfs(r + dy, c + dx, flag);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> M >> N) {
        if (N == 0 and M == 0) break;

        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        memset(dfs_state, 0, sizeof(dfs_state));

        vi ans;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (dfs_state[i][j]) continue;
                if (A[i][j] == '*' or A[i][j] == 'X') {
                    candidates.clear();
                    dfs(i, j, false);

                    for (auto candidate : candidates) {
                        dfs_state[candidate.first][candidate.second] = 0;
                    }

                    int counter = 0;
                    for (auto candidate : candidates) {
                        if (dfs_state[candidate.first][candidate.second])
                            continue;
                        counter++;
                        dfs(candidate.first, candidate.second, true);
                    }
                    ans.push_back(counter);
                }
            }

        sort(ans.begin(), ans.end());

        cout << "Throw " << ++n_test << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}