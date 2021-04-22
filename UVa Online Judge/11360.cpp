/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11360.cpp
#  Description:     UVa Online Judge - 11360
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char T[20][20], str[10];

int main() {
    // freopen("in","r",stdin);
    int TT;
    scanf("%d", &TT);
    for (int i = 1; i <= TT; i++) {
        int N, M, a, b;
        scanf("%d", &N);
        for (int j = 1; j <= N; j++) scanf("%s", &T[j][1]);
        scanf("%d", &M);
        for (int j = 1; j <= M; j++) {
            scanf("%s", str);
            if (!strcmp(str, "row")) {
                scanf("%d %d", &a, &b);
                for (int k = 1; k <= N; k++) swap(T[a][k], T[b][k]);
            } else if (!strcmp(str, "col")) {
                scanf("%d %d", &a, &b);
                for (int k = 1; k <= N; k++) swap(T[k][a], T[k][b]);
            } else if (!strcmp(str, "inc")) {
                for (int k = 1; k <= N; k++)
                    for (int l = 1; l <= N; l++)
                        T[k][l] = (T[k][l] < '9') ? T[k][l] + 1 : '0';
            } else if (!strcmp(str, "dec")) {
                for (int k = 1; k <= N; k++)
                    for (int l = 1; l <= N; l++)
                        T[k][l] = (T[k][l] > '0') ? T[k][l] - 1 : '9';
            } else if (!strcmp(str, "transpose")) {
                for (int k = 1; k <= N; k++)
                    for (int l = k + 1; l <= N; l++) swap(T[k][l], T[l][k]);
            }
        }

        printf("Case #%d\n", i);
        for (int j = 1; j <= N; j++) printf("%s\n", &T[j][1]);
        printf("\n");
    }
    return 0;
}