/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10177.cpp
#  Description:     UVa Online Judge - 10177
=============================================================================*/
#include <cstdio>
int main() {
    // freopen("in","r",stdin);
    int N;
    while (scanf("%d", &N) == 1) {
        int S2 = N * (N + 1) * (2 * N + 1) / 6;
        int S3 = (N * (N + 1)) / 2;
        S3 *= S3;

        int R2 = (N + 1) * (N) / 2;
        R2 *= R2;
        R2 -= S2;

        long long R3 = (N + 1) * N / 2;
        R3 *= R3 * R3;
        R3 -= S3;

        long long S4 = N * (N + 1) * (2 * N + 1);
        S4 *= (long long)(3 * N * N + 3 * N - 1);
        S4 /= 30;

        long long R4 = (N + 1) * N / 2;
        R4 *= R4 * R4 * R4;
        R4 -= S4;

        printf("%d %d %d %lld %lld %lld\n", S2, R2, S3, R3, S4, R4);
    }
    return 0;
}