/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10592.cc
#  Description:     UVa Online Judge - 10592
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

const int MAXN = 105;
int N;
int dfs_state1[MAXN][MAXN], dfs_state2[MAXN][MAXN], dfs_state3[MAXN][MAXN];
vector<string> A;

void floodfill1(int r, int c, char ch, int state) {
    if (dfs_state1[r][c]) return;
    dfs_state1[r][c] = state;

    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) != 1) continue;
            if (r + dr < 0 or r + dr >= A.size()) continue;
            if (c + dc < 0 or c + dc >= A[r + dr].length()) continue;

            if (A[r + dr][c + dc] != '.') floodfill1(r + dr, c + dc, ch, state);
        }
    }
}

void floodfill2(int r, int c, char ch, int state) {
    if (dfs_state2[r][c]) return;
    dfs_state2[r][c] = state;

    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) != 1) continue;
            if (r + dr < 0 or r + dr >= A.size()) continue;
            if (c + dc < 0 or c + dc >= A[r + dr].length()) continue;
            if (A[r + dr][c + dc] != ch) continue;
            floodfill2(r + dr, c + dc, ch, state);
        }
    }
}

void floodfill3(int r, int c, char ch, int state, int &mask) {
    if (dfs_state3[r][c]) return;
    dfs_state3[r][c] = state;

    if (A[r][c] == 'B') mask |= (1 << 0);
    if (A[r][c] == 'P') mask |= (1 << 1);

    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) != 1) continue;
            if (r + dr < 0 or r + dr >= A.size()) continue;
            if (c + dc < 0 or c + dc >= A[r + dr].length()) continue;
            if (A[r + dr][c + dc] != 'B' and A[r + dr][c + dc] != 'P') continue;
            floodfill3(r + dr, c + dc, ch, state, mask);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) {
        if (N == 0) break;

        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        memset(dfs_state1, 0, sizeof(dfs_state1));
        memset(dfs_state2, 0, sizeof(dfs_state2));
        memset(dfs_state3, 0, sizeof(dfs_state3));

        int n_group = 0;
        vi sizes[2];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dfs_state1[i][j]) continue;
                if (A[i][j] != '.') {
                    sizes[0].push_back(0);
                    sizes[1].push_back(0);
                    floodfill1(i, j, A[i][j], sizes[0].size());
                }
            }
        }

        // count B and P
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dfs_state2[i][j]) continue;
                if (A[i][j] == 'B' or A[i][j] == 'P') {
                    floodfill2(i, j, A[i][j], 1);
                    if (A[i][j] == 'B')
                        sizes[0][dfs_state1[i][j] - 1]++;
                    else
                        sizes[1][dfs_state1[i][j] - 1]++;
                }
            }
        }

        for (int i = 0; i < sizes[0].size(); i++) {
            cout << "Sector #" << i + 1 << ": contain " << sizes[0][i]
                 << " freedom fighter group(s) & " << sizes[1][i]
                 << " enemy group(s)" << endl;
        }

        // count BP
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dfs_state3[i][j]) continue;
                if (A[i][j] == 'B' or A[i][j] == 'P') {
                    int tmp = 0;
                    floodfill3(i, j, A[i][j], 1, tmp);
                    if (tmp & (1 << 0) and tmp & (1 << 1)) ans += 2;
                }
            }
        }
        cout << "Total " << ans << " group(s) are in fighting position."
             << endl;
        cout << endl;
    }

    return 0;
}