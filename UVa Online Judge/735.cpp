/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        735.cpp
#  Description:     UVa Online Judge - 735
=============================================================================*/
#include <cstdio>

const int A[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
                 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33,
                 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int N;
    while (scanf("%d", &N) == 1) {
        if (N <= 0) break;

        int permu = 0, combi = 0;

        for (int i = 0; i < 43; i++)
            for (int j = i; j < 43; j++)
                for (int k = j; k < 43; k++) {
                    if (A[i] + A[j] + A[k] == N) {
                        // printf("[%d][%d][%d]\n",vv1,vv2,vv3);
                        if (A[i] == A[j] and A[j] == A[k])
                            permu++;
                        else if (A[i] == A[j] and A[j] != A[k])
                            permu += 3;
                        else if (A[i] == A[k] and A[i] != A[j])
                            permu += 3;
                        else if (A[j] == A[k] and A[i] != A[j])
                            permu += 3;
                        else
                            permu += 6;
                        combi++;
                    }
                }

        if (combi) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", N, combi);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", N, permu);
        } else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", N);
        }
        printf(
            "******************************************************************"
            "****\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}