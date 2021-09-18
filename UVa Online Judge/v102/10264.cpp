/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10264.cpp
#  Description:     UVa Online Judge - 10264
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 100000;
int N, A[MAXN], P[MAXN];

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < (1 << N); i++) scanf("%d", &A[i]);
        for (int i = 0; i < (1 << N); i++) {
            P[i] = 0;
            for (int j = 0; j < N; j++) P[i] += A[i ^ (1 << j)];
        }
        int ans = 0;
        for (int i = 0; i < (1 << N); i++)
            for (int j = 0; j < N; j++) ans = max(ans, P[i] + P[i ^ (1 << j)]);
        printf("%d\n", ans);
    }
    return 0;
}