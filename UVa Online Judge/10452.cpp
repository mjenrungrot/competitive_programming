/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10452.cpp
#  Description:     UVa Online Judge - 10452
=============================================================================*/
#include <cstdio>

char str[] = "IEHOVA#";

int R, C;
char T[10][10];
int A[30];
bool found;

void f(int r, int c, int len) {
    if (len == 7) {
        found = true;
        return;
    }

    A[len] = 1;
    if (c - 1 >= 1 and T[r][c - 1] == str[len]) f(r, c - 1, len + 1);
    if (found) return;

    A[len] = 2;
    if (r + 1 <= R and T[r + 1][c] == str[len]) f(r + 1, c, len + 1);
    if (found) return;

    A[len] = 3;
    if (c + 1 <= C and T[r][c + 1] == str[len]) f(r, c + 1, len + 1);
    if (found) return;
}

int main() {
    // freopen("in","r",stdin);
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        scanf("%d %d", &R, &C);
        for (int i = R; i >= 1; i--) scanf("%s", &T[i][1]);

        found = false;
        for (int i = 1; i <= C; i++)
            if (T[1][i] == '@') {
                f(1, i, 0);
                break;
            }
        for (int i = 0; i < 7; i++) {
            if (i) printf(" ");
            if (A[i] == 1) printf("left");
            if (A[i] == 2) printf("forth");
            if (A[i] == 3) printf("right");
        }
        printf("\n");
    }
    return 0;
}