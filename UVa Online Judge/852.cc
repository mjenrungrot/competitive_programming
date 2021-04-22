/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        852.cc
#  Description:     UVa Online Judge - 852
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

const int N = 9;
const int BLACK = 0;
const int WHITE = 1;

vector<string> A;
int scores[2];
int dfs_state[N][N];

int floodfill(int r, int c, int &type) {
    if (A[r][c] == 'O') {
        type |= (1 << WHITE);
        return 0;
    }
    if (A[r][c] == 'X') {
        type |= (1 << BLACK);
        return 0;
    }

    if (dfs_state[r][c]) return 0;
    dfs_state[r][c] = 1;

    int ans = 1;
    for (int dy : {-1, 0, 1}) {
        for (int dx : {-1, 0, 1}) {
            if (dx == 0 and dy == 0) continue;
            if (abs(dy) + abs(dx) == 2) continue;
            if (r + dy < 0 or r + dy >= N) continue;
            if (c + dx < 0 or c + dx >= N) continue;
            if (dfs_state[r + dy][c + dx]) continue;
            ans += floodfill(r + dy, c + dx, type);
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
        A.clear();
        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        memset(scores, 0, sizeof(scores));
        memset(dfs_state, 0, sizeof(dfs_state));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                scores[WHITE] += (A[i][j] == 'O');
                scores[BLACK] += (A[i][j] == 'X');
                if (dfs_state[i][j]) continue;
                if (A[i][j] == '.') {
                    int type = 0;
                    int val = floodfill(i, j, type);
                    if (type == (1 << BLACK)) {
                        scores[BLACK] += val;
                    } else if (type == (1 << WHITE)) {
                        scores[WHITE] += val;
                    }
                }
            }
        cout << "Black " << scores[BLACK] << " White " << scores[WHITE] << endl;
    }

    return 0;
}