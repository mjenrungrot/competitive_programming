/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11548.cpp
#  Description:     UVa Online Judge - 11548
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char str[80][80];
int len[80];

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%s", str[i]);
            len[i] = strlen(str[i]);
        }

        int ans = 0;
        for (int i = 1; i <= N - 1; i++)
            for (int j = i + 1; j <= N; j++) {
                for (int k = -len[j] + 1; k <= len[i] - 1; k++) {
                    int start_j = 0, start_i = 0;
                    if (k < 0) start_j = -k;
                    if (k > 0) start_i = k;

                    int tmp = 0;
                    while (start_j < len[j] and start_i < len[i]) {
                        if (str[i][start_i] == str[j][start_j]) tmp++;
                        start_i++;
                        start_j++;
                    }
                    ans = max(ans, tmp);
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}