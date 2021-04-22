/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        165.cc
#  Description:     UVa Online Judge - 165
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int H, K;
int curr[10], sol[10];
int sol_n;

bool check(int curr_n, int l, int ll, int hh) {
    if (curr_n < 0) return false;
    if (curr_n == 0) return true;
    if (hh < H) {
        bool ret = check(curr_n - curr[l], l, ll, hh + 1);
        for (int d = l + 1; d <= ll and !ret; d++) {
            ret = ret || check(curr_n - curr[d], d, ll, hh + 1);
        }
        return ret;
    }
    return false;
}

void dfs(int curr_n, int l) {
    if (l == K) {
        if (curr_n > sol_n) {
            sol_n = curr_n;
            for (int i = 0; i < K; i++) sol[i] = curr[i];
        }
    } else {
        for (int i = curr[l - 1] + 1; i < curr_n + 2; i++) {
            curr[l] = i;
            int j = curr_n + 1;
            while (check(j, 0, l, 0)) j++;
            dfs(j - 1, l + 1);
        }
    }
}

int main() {
    int h, k;
    while (cin >> H >> K) {
        if (!H and !K) break;
        curr[0] = 1;
        sol_n = 0;
        dfs(H, 1);
        for (int i = 0; i < K; i++) printf("%3d", sol[i]);
        printf(" ->%3d\n", sol_n);
    }
    return 0;
}