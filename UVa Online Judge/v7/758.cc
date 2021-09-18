/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        758.cc
#  Description:     UVa Online Judge - 758
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

int dfs_state[MAXN][MAXN];
vector<string> board, tmp_board;

int floodfill(int r, int c, char ch, int s) {
    if (dfs_state[r][c]) return 0;
    dfs_state[r][c] = s;

    int ans = 1;
    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) != 1) continue;
            if (r + dr < 0 or r + dr >= board.size()) continue;
            if (c + dc < 0 or c + dc >= board[r + dr].size()) continue;
            if (board[r + dr][c + dc] != ch) continue;
            ans += floodfill(r + dr, c + dc, ch, s);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    int n_test = 0;
    getline(cin, line);
    int T = stoi(line);

    getline(cin, line);
    while (T--) {
        cout << "Game " << ++n_test << ":" << endl;
        cout << endl;

        board.clear();
        while (true) {
            getline(cin, line);
            while (line.back() == ' ') line.pop_back();
            if (line == "") break;
            board.push_back(line);
            if (cin.eof()) break;
        }

        int total = 0, n_move = 0, n_balls = board.size() * board[0].length();
        while (true) {
            memset(dfs_state, 0, sizeof(dfs_state));
            int valid = false;
            int best_score = -1;
            int counter = 0;
            ii best_pos(-1, -1);
            vi sizes;

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].length(); j++) {
                    if (dfs_state[i][j]) continue;
                    if (board[i][j] == '0') continue;
                    int val = floodfill(i, j, board[i][j], ++counter);
                    sizes.push_back(val);
                    if (val == 1) continue;
                    valid = true;
                    best_score = max(best_score, val);
                }
            }
            if (not valid) break;

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].length(); j++) {
                    if (board[i][j] == '0') continue;
                    int val = sizes[dfs_state[i][j] - 1];
                    if ((val == best_score and best_pos == ii(-1, -1)) or
                        (val == best_score and j + 1 < best_pos.second + 1) or
                        (val == best_score and j + 1 == best_pos.second + 1 and
                         board.size() - i < board.size() - best_pos.first)) {
                        best_pos = ii(i, j);
                    }
                }
            }

            total += (best_score - 2) * (best_score - 2);
            n_balls -= best_score;
            cout << "Move " << ++n_move << " at ("
                 << board.size() - best_pos.first << "," << best_pos.second + 1
                 << "): ";
            cout << "removed " << best_score << " balls of color "
                 << board[best_pos.first][best_pos.second] << ", got "
                 << (best_score - 2) * (best_score - 2) << " points." << endl;

            int idx = dfs_state[best_pos.first][best_pos.second];
            for (int i = 0; i < board.size(); i++)
                for (int j = 0; j < board[i].size(); j++)
                    if (dfs_state[i][j] == idx) {
                        board[i][j] = '0';
                    }

            tmp_board.resize(board.size());
            for (int i = 0; i < board.size(); i++) {
                tmp_board[i] = string(board[i].length(), '0');
            }

            // update board
            int curr_col = 0, curr_row = board[0].size() - 1;
            for (int col = 0; col < board[0].size(); col++) {
                curr_row = board.size() - 1;

                bool exist_this_col = false;
                for (int row = board.size() - 1; row >= 0; row--) {
                    if (board[row][col] == '0') {
                        continue;
                    } else {
                        exist_this_col = true;
                        tmp_board[curr_row--][curr_col] = board[row][col];
                    }
                }

                if (exist_this_col) {
                    for (; curr_row >= 0; curr_row--)
                        tmp_board[curr_row][curr_col] = '0';
                    curr_col++;
                }
            }

            board = tmp_board;
        }

        if (board.back()[0] == '0') total += 1000;
        cout << "Final score: " << total << ", with " << n_balls
             << " balls remaining." << endl;

        if (T) cout << endl;
    }

    return 0;
}