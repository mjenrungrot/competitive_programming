/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11585.cc
#  Description:     UVa Online Judge - 11585
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

int R, C, N;
string board[MAXN];
int arr[MAXN][MAXN];
int dfs_state[MAXN][MAXN];

int floodfill(int r, int c, char ch, bool diagonal, int &tmp, int &border) {
    if (dfs_state[r][c]) return 0;
    dfs_state[r][c] = 1;

    if (r == 0 or r == R - 1 or c == 0 or c == C - 1) {
        border = 1;
    }

    if (tmp == -1) {
        if (arr[r][c]) tmp = arr[r][c];
    } else {
        if (arr[r][c]) tmp = -1;
    }

    int ans = 1;
    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (dr == 0 and dc == 0) continue;
            if ((not diagonal) and abs(dr) + abs(dc) == 2) continue;
            if (r + dr < 0 or r + dr >= R) continue;
            if (c + dc < 0 or c + dc >= C) continue;
            if (board[r + dr][c + dc] != ch) continue;
            ans += floodfill(r + dr, c + dc, ch, diagonal, tmp, border);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> R >> C >> N;

        memset(arr, 0, sizeof(arr));
        memset(dfs_state, 0, sizeof(dfs_state));

        int total_unfilled = 0;
        for (int i = 1; i <= N; i++) {
            int r, c, n;
            cin >> r >> c >> n;
            arr[r][c] = n;
            total_unfilled += n;
        }

        for (int i = 0; i < R; i++) cin >> board[i];

        // check number of unfilled
        int count_unfilled = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) count_unfilled += board[i][j] == '.';

        if (total_unfilled != count_unfilled) {
            cout << "not solved" << endl;
            continue;
        }

        // check if the filled area is connected
        bool done = false;
        for (int i = 0; i < R and not done; i++) {
            for (int j = 0; j < C and not done; j++) {
                if (dfs_state[i][j]) continue;
                if (board[i][j] == '#') {
                    int tmp1 = -1;
                    int tmp2 = -1;
                    int val = floodfill(i, j, '#', false, tmp1, tmp2);
                    if (val + count_unfilled != R * C) {
                        cout << "not solved" << endl;
                        done = true;
                        break;
                    }
                }
            }
        }
        if (done) continue;

        // check if the area is correct and only has one number in it
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (dfs_state[i][j]) continue;
                if (board[i][j] == '.') {
                    int tmp1 = -1;
                    int tmp2 = -1;
                    int val = floodfill(i, j, '.', false, tmp1, tmp2);
                    if (tmp1 == -1 or val != tmp1) {
                        cout << "not solved" << endl;
                        done = true;
                        continue;
                    }
                }
            }
        if (done) continue;

        // check if each unfilled is reachable
        memset(dfs_state, 0, sizeof(dfs_state));
        for (int i = 0; i < R and not done; i++)
            for (int j = 0; j < C and not done; j++) {
                if (dfs_state[i][j]) continue;
                if (board[i][j] == '.') {
                    int tmp1 = -1;
                    int tmp2 = -1;
                    int val = floodfill(i, j, '.', true, tmp1, tmp2);
                    if (tmp2 == -1) {
                        cout << "not solved" << endl;
                        done = true;
                        continue;
                    }
                }
            }

        if (done) continue;

        for (int i = 0; i < R - 1 and not done; i++)
            for (int j = 0; j < C - 1 and not done; j++) {
                if (board[i][j] == '#' and board[i][j + 1] == '#' and
                    board[i + 1][j] == '#' and board[i + 1][j + 1] == '#') {
                    cout << "not solved" << endl;
                    done = true;
                    continue;
                }
            }
        if (done) continue;

        cout << "solved" << endl;
    }

    return 0;
}