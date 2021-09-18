/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10978.cpp
#  Description:     UVa Online Judge - 10978
=============================================================================*/
#include <cstdio>
#include <cstring>

char str1[30], str2[30];
char ans[60][30];
int N, isOpen[60];

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        if (!N) break;
        int now = -1;
        memset(isOpen, false, sizeof isOpen);
        for (int i = 1; i <= N; i++) {
            scanf("%s %s", str1, str2);
            int len = strlen(str2);

            while (len > 0) {
                now++;
                now %= N;
                if (not isOpen[now]) len--;
            }
            isOpen[now] = true;
            strcpy(ans[now], str1);
        }
        for (int i = 0; i < N; i++) {
            if (i) printf(" ");
            printf("%s", ans[i]);
        }
        printf("\n");
    }
    return 0;
}