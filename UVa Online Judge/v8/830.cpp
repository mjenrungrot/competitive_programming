/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        830.cpp
#  Description:     UVa Online Judge - 830
=============================================================================*/
#include <cassert>
#include <cstdio>

const int dify[] = {-1, 0, 1, 0};
const int difx[] = {0, -1, 0, 1};

char T[80][80];
int R, C;
int sardine, mackerel, salmon, grouper, turtle, dolphin, whale, shark;

void clear(int y, int x, char ch) {
    T[y][x] = '.';
    for (int i = 0; i < 4; i++) {
        if (y + dify[i] >= 1 and y + dify[i] <= R and x + difx[i] >= 1 and
            x + difx[i] <= C) {
            if (T[y + dify[i]][x + difx[i]] == ch)
                clear(y + dify[i], x + difx[i], ch);
        }
    }
}

void add(int y, int x) {
    int n_col = 1, n_row = 1;
    while (x + n_col <= C and T[y][x] == T[y][x + n_col]) n_col++;
    while (y + n_row <= R and T[y][x] == T[y + n_row][x]) n_row++;

    bool isShark = false;
    for (int i = x; i <= x + n_col - 1; i++) {
        if (y + n_row <= R and T[y + n_row - 1][i] == T[y + n_row][i])
            isShark = true;
        if (y - 1 >= 1 and T[y - 1][i] == T[y][i]) isShark = true;
    }
    for (int i = y; i <= y + n_row - 1; i++) {
        if (x + n_col <= C and T[i][x + n_col - 1] == T[i][x + n_col])
            isShark = true;
        if (x - 1 >= 1 and T[i][x - 1] == T[i][x]) isShark = true;
    }

    if (n_row > n_col) {
        int tmp = n_row;
        n_row = n_col;
        n_col = tmp;
    }

    assert(n_row <= n_col);

    if (isShark)
        shark++;
    else if (n_row == 1 and n_col == 1)
        sardine++;
    else if (n_row == 1 and n_col == 2)
        mackerel++;
    else if (n_row == 1)
        salmon++;
    else if (n_row == n_col)
        turtle++;
    else if (n_row == 2 and n_col > 2)
        grouper++;
    else if (n_row == 3 and n_col > 3)
        dolphin++;
    else if (n_row == 4 and n_col > 4)
        whale++;
    clear(y, x, T[y][x]);
}

void run() {
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++) scanf("%s", &T[i][1]);

    sardine = mackerel = salmon = grouper = turtle = dolphin = whale = shark =
        0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
            if (T[i][j] != '.') add(i, j);
        }
    printf("%d %d %d %d %d %d %d %d\n", sardine, mackerel, salmon, grouper,
           turtle, dolphin, whale, shark);
}
int main() {
    // freopen("in","r",stdin);
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        run();
        if (TT) printf("\n");
    }
    return 0;
}