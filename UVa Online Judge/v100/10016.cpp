/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10016.cpp
#  Description:     UVa Online Judge - 10016
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int A[105][105], N;

void upside_down(int ring) {
    for (int i = ring; i <= N - ring + 1; i++)
        swap(A[ring][i], A[N - ring + 1][i]);
    for (int i = ring + 1, j = N - ring; i < j; i++, j--)
        swap(A[i][ring], A[j][ring]),
            swap(A[i][N - ring + 1], A[j][N - ring + 1]);
}
void left_right(int ring) {
    for (int i = ring; i <= N - ring + 1; i++)
        swap(A[i][ring], A[i][N - ring + 1]);
    for (int i = ring + 1, j = N - ring; i < j; i++, j--)
        swap(A[ring][i], A[ring][j]),
            swap(A[N - ring + 1][i], A[N - ring + 1][j]);
}
void main_diagonal(int ring) {
    swap(A[ring][N - ring + 1], A[N - ring + 1][ring]);
    for (int i = N - ring; i >= ring; i--) swap(A[i][ring], A[ring][i]);
    for (int i = ring + 1; i <= N - ring; i++)
        swap(A[N - ring + 1][i], A[i][N - ring + 1]);
}
void inverse_main_diagonal(int ring) {
    swap(A[ring][ring], A[N - ring + 1][N - ring + 1]);
    for (int i = ring + 1, j = N - ring; i <= N - ring + 1; i++, j--)
        swap(A[ring][i], A[j][N - ring + 1]),
            swap(A[i][ring], A[N - ring + 1][j]);
}

void run() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) scanf("%d", &A[i][j]);
    for (int i = 1; i <= (N + 1) / 2; i++) {
        int xx;
        scanf("%d", &xx);
        for (int j = 1; j <= xx; j++) {
            int yy;
            scanf("%d", &yy);
            if (yy == 1)
                upside_down(i);
            else if (yy == 2)
                left_right(i);
            else if (yy == 3)
                main_diagonal(i);
            else if (yy == 4)
                inverse_main_diagonal(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j > 1) printf(" ");
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) run();
    return 0;
}