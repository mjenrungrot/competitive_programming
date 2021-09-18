/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        868.cc
#  Description:     UVa Online Judge - 868
=============================================================================*/
#include <iostream>
using namespace std;

int T, N, M;
int A[1005][1005];
int best_col;

void f(int row, int col, int k) {
    if (row == N) {
        if (A[row][col] == k) {
            if (best_col == -1 or col < best_col) {
                best_col = col;
            }
        }
    }

    int next_val = (A[row][col] == k ? 1 : A[row][col] + 1);
    int next_k = (A[row][col] == k ? k + 1 : k);

    if (col - 1 >= 1 and A[row][col - 1] == next_val) f(row, col - 1, next_k);
    if (col + 1 <= M and A[row][col + 1] == next_val) f(row, col + 1, next_k);
    if (row + 1 <= N and A[row + 1][col] == next_val) f(row + 1, col, next_k);
    if (row - 1 >= 1 and A[row - 1][col] == next_val) f(row - 1, col, next_k);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) cin >> A[i][j];

        best_col = -1;
        for (int col = 1; col <= M; col++) {
            if (A[1][col] != 1) continue;
            f(1, col, 1);

            if (best_col != -1) {
                cout << 1 << " " << col << endl;
                cout << N << " " << best_col << endl;
                break;
            }
        }

        if (T) cout << endl;
    }
    return 0;
}