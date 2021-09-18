/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10013.cc
#  Description:     UVa Online Judge - 10013
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int T, N;
int num1[1000005], num2[1000005];
int result[1000005], carry[1000005];

int main() {
    int out;
    scanf("%d", &T);
    while (T--) {
        memset(result, 0, sizeof(result));
        memset(carry, 0, sizeof(carry));

        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d %d", &num1[i], &num2[i]);
            result[i] = (num1[i] + num2[i]) % 10;
            carry[i - 1] = (num1[i] + num2[i]) / 10;
        }

        for (int i = N - 1; i >= 0; i--) {
            out = (result[i] + carry[i]);
            result[i] = out % 10;
            if (i - 1 >= 0) carry[i - 1] += out / 10;
        }

        int start_i = 0;
        while (result[start_i] == 0) start_i++;

        for (int i = start_i; i <= N; i++) printf("%d", result[i]);
        printf("\n");
        if (T) printf("\n");
    }
    return 0;
}