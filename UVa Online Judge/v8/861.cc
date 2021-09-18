/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        861.cc
#  Description:     UVa Online Judge - 861
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int memo[10][80];
int N, K, ans;
int board[10][10];

void dfs(int curr_idx, int curr_k) {
    if (curr_k == K) {
        ans++;
        return;
    }
    if (curr_idx >= N * N) return;

    int r = curr_idx / N;
    int c = curr_idx % N;
    board[r][c] = 1;
    bool check = true;
    for (int rr = r - 1, cl = c - 1, cr = c + 1; rr >= 0 && check;
         rr--, cl--, cr++) {
        if (cl >= 0 and board[rr][cl]) check = false;
        if (cr < N and board[rr][cr]) check = false;
    }
    if (check) dfs(curr_idx + 1, curr_k + 1);  // place at (r,c)
    board[r][c] = 0;
    dfs(curr_idx + 1, curr_k);  // not place at (r,c)
}

void precompute() {
    memo[1][0] = 1;
    memo[1][1] = 1;
    memo[2][0] = 1;
    memo[2][1] = 4;
    memo[2][2] = 4;
    memo[2][3] = 0;
    memo[2][4] = 0;
    memo[3][0] = 1;
    memo[3][1] = 9;
    memo[3][2] = 26;
    memo[3][3] = 26;
    memo[3][4] = 8;
    memo[3][5] = 0;
    memo[3][6] = 0;
    memo[3][7] = 0;
    memo[3][8] = 0;
    memo[3][9] = 0;
    memo[4][0] = 1;
    memo[4][1] = 16;
    memo[4][2] = 92;
    memo[4][3] = 232;
    memo[4][4] = 260;
    memo[4][5] = 112;
    memo[4][6] = 16;
    memo[4][7] = 0;
    memo[4][8] = 0;
    memo[4][9] = 0;
    memo[4][10] = 0;
    memo[4][11] = 0;
    memo[4][12] = 0;
    memo[4][13] = 0;
    memo[4][14] = 0;
    memo[4][15] = 0;
    memo[4][16] = 0;
    memo[5][0] = 1;
    memo[5][1] = 25;
    memo[5][2] = 240;
    memo[5][3] = 1124;
    memo[5][4] = 2728;
    memo[5][5] = 3368;
    memo[5][6] = 1960;
    memo[5][7] = 440;
    memo[5][8] = 32;
    memo[5][9] = 0;
    memo[5][10] = 0;
    memo[5][11] = 0;
    memo[5][12] = 0;
    memo[5][13] = 0;
    memo[5][14] = 0;
    memo[5][15] = 0;
    memo[5][16] = 0;
    memo[5][17] = 0;
    memo[5][18] = 0;
    memo[5][19] = 0;
    memo[5][20] = 0;
    memo[5][21] = 0;
    memo[5][22] = 0;
    memo[5][23] = 0;
    memo[5][24] = 0;
    memo[5][25] = 0;
    memo[6][0] = 1;
    memo[6][1] = 36;
    memo[6][2] = 520;
    memo[6][3] = 3896;
    memo[6][4] = 16428;
    memo[6][5] = 39680;
    memo[6][6] = 53744;
    memo[6][7] = 38368;
    memo[6][8] = 12944;
    memo[6][9] = 1600;
    memo[6][10] = 64;
    memo[6][11] = 0;
    memo[6][12] = 0;
    memo[6][13] = 0;
    memo[6][14] = 0;
    memo[6][15] = 0;
    memo[6][16] = 0;
    memo[6][17] = 0;
    memo[6][18] = 0;
    memo[6][19] = 0;
    memo[6][20] = 0;
    memo[6][21] = 0;
    memo[6][22] = 0;
    memo[6][23] = 0;
    memo[6][24] = 0;
    memo[6][25] = 0;
    memo[6][26] = 0;
    memo[6][27] = 0;
    memo[6][28] = 0;
    memo[6][29] = 0;
    memo[6][30] = 0;
    memo[6][31] = 0;
    memo[6][32] = 0;
    memo[6][33] = 0;
    memo[6][34] = 0;
    memo[6][35] = 0;
    memo[6][36] = 0;
    memo[7][0] = 1;
    memo[7][1] = 49;
    memo[7][2] = 994;
    memo[7][3] = 10894;
    memo[7][4] = 70792;
    memo[7][5] = 282248;
    memo[7][6] = 692320;
    memo[7][7] = 1022320;
    memo[7][8] = 867328;
    memo[7][9] = 389312;
    memo[7][10] = 81184;
    memo[7][11] = 5792;
    memo[7][12] = 128;
    memo[7][13] = 0;
    memo[7][14] = 0;
    memo[7][15] = 0;
    memo[7][16] = 0;
    memo[7][17] = 0;
    memo[7][18] = 0;
    memo[7][19] = 0;
    memo[7][20] = 0;
    memo[7][21] = 0;
    memo[7][22] = 0;
    memo[7][23] = 0;
    memo[7][24] = 0;
    memo[7][25] = 0;
    memo[7][26] = 0;
    memo[7][27] = 0;
    memo[7][28] = 0;
    memo[7][29] = 0;
    memo[7][30] = 0;
    memo[7][31] = 0;
    memo[7][32] = 0;
    memo[7][33] = 0;
    memo[7][34] = 0;
    memo[7][35] = 0;
    memo[7][36] = 0;
    memo[7][37] = 0;
    memo[7][38] = 0;
    memo[7][39] = 0;
    memo[7][40] = 0;
    memo[7][41] = 0;
    memo[7][42] = 0;
    memo[7][43] = 0;
    memo[7][44] = 0;
    memo[7][45] = 0;
    memo[7][46] = 0;
    memo[7][47] = 0;
    memo[7][48] = 0;
    memo[7][49] = 0;
    memo[8][0] = 1;
    memo[8][1] = 64;
    memo[8][2] = 1736;
    memo[8][3] = 26192;
    memo[8][4] = 242856;
    memo[8][5] = 1444928;
    memo[8][6] = 5599888;
    memo[8][7] = 14082528;
    memo[8][8] = 22522960;
    memo[8][9] = 22057472;
    memo[8][10] = 12448832;
    memo[8][11] = 3672448;
    memo[8][12] = 489536;
    memo[8][13] = 20224;
    memo[8][14] = 256;
    memo[8][15] = 0;
    memo[8][16] = 0;
    memo[8][17] = 0;
    memo[8][18] = 0;
    memo[8][19] = 0;
    memo[8][20] = 0;
    memo[8][21] = 0;
    memo[8][22] = 0;
    memo[8][23] = 0;
    memo[8][24] = 0;
    memo[8][25] = 0;
    memo[8][26] = 0;
    memo[8][27] = 0;
    memo[8][28] = 0;
    memo[8][29] = 0;
    memo[8][30] = 0;
    memo[8][31] = 0;
    memo[8][32] = 0;
    memo[8][33] = 0;
    memo[8][34] = 0;
    memo[8][35] = 0;
    memo[8][36] = 0;
    memo[8][37] = 0;
    memo[8][38] = 0;
    memo[8][39] = 0;
    memo[8][40] = 0;
    memo[8][41] = 0;
    memo[8][42] = 0;
    memo[8][43] = 0;
    memo[8][44] = 0;
    memo[8][45] = 0;
    memo[8][46] = 0;
    memo[8][47] = 0;
    memo[8][48] = 0;
    memo[8][49] = 0;
    memo[8][50] = 0;
    memo[8][51] = 0;
    memo[8][52] = 0;
    memo[8][53] = 0;
    memo[8][54] = 0;
    memo[8][55] = 0;
    memo[8][56] = 0;
    memo[8][57] = 0;
    memo[8][58] = 0;
    memo[8][59] = 0;
    memo[8][60] = 0;
    memo[8][61] = 0;
    memo[8][62] = 0;
    memo[8][63] = 0;
    memo[8][64] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    precompute();

    while (cin >> N >> K) {
        if (!N and !K) break;

        if (memo[N][K] != -1) {
            cout << memo[N][K] << endl;
            continue;
        }

        ans = 0;
        memset(board, 0, sizeof(board));
        dfs(0, 0);
        memo[N][K] = ans;
        cout << memo[N][K] << endl;
        // cout << "memo[" << N << "][" << K << "] = " << memo[N][K] << ";" <<
        // endl;
    }
    return 0;
}