/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        601.cc
#  Description:     UVa Online Judge - 601
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

enum state { UNVISITED, WHITE_L, WHITE_R, BLACK_T, BLACK_B };

int N;
int dfs_state[MAXN][MAXN];
vector<string> A;

void floodfill(int r, int c, state S, int &win) {
    if (S == WHITE_L and c == N - 1 and A[r][c] != 'U') {
        win = true;
        return;
    }
    if (S == WHITE_R and (c == 0 or dfs_state[r][c] == WHITE_L)) {
        win = true;
        return;
    }
    if (S == BLACK_T and r == N - 1 and A[r][c] != 'U') {
        win = true;
        return;
    }
    if (S == BLACK_B and (r == 0 or dfs_state[r][c] == BLACK_T)) {
        win = true;
        return;
    }

    if (dfs_state[r][c]) return;
    dfs_state[r][c] = S;

    if (A[r][c] == 'U') return;

    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) != 1) continue;
            if (r + dr < 0 or r + dr >= N) continue;
            if (c + dc < 0 or c + dc >= N) continue;
            if (S == WHITE_L and A[r + dr][c + dc] == 'B') continue;
            if (S == WHITE_R and A[r + dr][c + dc] == 'B') continue;
            if (S == BLACK_T and A[r + dr][c + dc] == 'W') continue;
            if (S == BLACK_B and A[r + dr][c + dc] == 'W') continue;

            floodfill(r + dr, c + dc, S, win);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) {
        if (N == 0) break;

        A.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        memset(dfs_state, UNVISITED, sizeof(dfs_state));

        // check white win
        int win = false;
        for (int i = 0; i < N; i++) {
            if (A[i][0] == 'W') floodfill(i, 0, WHITE_L, win);
            if (win) break;
        }
        if (win) {
            cout << "White has a winning path." << endl;
            continue;
        }

        // check white one move
        for (int i = 0; i < N; i++) {
            if (A[i][N - 1] == 'W' or A[i][N - 1] == 'U')
                floodfill(i, N - 1, WHITE_R, win);
            if (win) break;
        }
        if (win) {
            cout << "White can win in one move." << endl;
            continue;
        }

        // Clear U state
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (A[i][j] == 'U') dfs_state[i][j] = UNVISITED;

        // check black win
        for (int i = 0; i < N; i++) {
            if (A[0][i] == 'B') floodfill(0, i, BLACK_T, win);
            if (win) break;
        }
        if (win) {
            cout << "Black has a winning path." << endl;
            continue;
        }

        // check black one move
        for (int i = 0; i < N; i++) {
            if (A[N - 1][i] == 'B' or A[N - 1][i] == 'U')
                floodfill(N - 1, i, BLACK_B, win);
            if (win) break;
        }
        if (win) {
            cout << "Black can win in one move." << endl;
            continue;
        }

        cout << "There is no winning path." << endl;
    }

    return 0;
}