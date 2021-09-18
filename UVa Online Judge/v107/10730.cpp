/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10730.cpp
#  Description:     UVa Online Judge - 10730
=============================================================================*/
#include <cstdio>
#include <cstring>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

const int MAXN = 10005;
int N, A[MAXN], memo[MAXN];
char str[5];

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        if (!N) break;
        scanf("%s", str);
        memset(memo, 0, sizeof memo);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
            memo[A[i]]++;
        }

        for (int i = 1; i < N; i++) {
            memo[A[i]]--;
            for (int j = i + 1; j < N; j++) {
                memo[A[j]]--;
                int val = 2 * A[j] - A[i];
                if (val >= 0 and val <= N and memo[val] > 0) goto end;
            }
            for (int j = i + 1; j < N; j++) memo[A[j]]++;
        }

        printf("yes\n");
        continue;

    end:
        printf("no\n");
    }
    return 0;
}