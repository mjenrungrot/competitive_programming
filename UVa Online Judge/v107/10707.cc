/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10707.cc
#  Description:     UVa Online Judge - 10707
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
int board[2][MAXN][MAXN], board2[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int R, C, N;
        cin >> C >> R >> N;

        memset(board, 0, sizeof(board));
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < N; i++) {
                int r, c;
                cin >> c >> r;
                board[k][r][c] = true;
            }
        }

        vi counter[2];
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++) {
                    if (not board[k][i][j]) continue;
                    int amount = 1;
                    for (int dr : {-1, 0, 1})
                        for (int dc : {-1, 0, 1}) {
                            if (abs(dr) + abs(dc) != 1) continue;
                            int kk = 0;
                            int tmp = 0;
                            int new_r = i + kk * dr;
                            int new_c = j + kk * dc;
                            while (0 <= new_r and new_r < R and 0 <= new_c and
                                   new_c < C and board[k][new_r][new_c]) {
                                new_r += dr;
                                new_c += dc;
                                tmp += kk;
                                kk++;
                            }
                            amount += tmp;
                        }
                    counter[k].push_back(amount);
                }
        }

        sort(counter[0].begin(), counter[0].end());
        sort(counter[1].begin(), counter[1].end());

        bool check = counter[0].size() == counter[1].size();
        for (int i = 0; check and i < counter[0].size(); i++)
            if (counter[0][i] != counter[1][i]) {
                check = false;
            }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}