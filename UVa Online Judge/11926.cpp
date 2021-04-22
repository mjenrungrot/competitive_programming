/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11926.cpp
#  Description:     UVa Online Judge - 11926
=============================================================================*/
#include <cstdio>
#include <cstring>
using namespace std;

bool B[1000005];

int main() {
    // freopen("in","r",stdin);
    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 and M == 0) break;
        bool possible = true;

        memset(B, 0, sizeof B);
        for (int i = 1; i <= N; i++) {
            int aa, bb;
            scanf("%d %d", &aa, &bb);
            for (int j = aa; j < bb and possible; j++) {
                if (B[j] == true) {
                    possible = false;
                    break;
                }
                B[j] = true;
            }
        }
        for (int i = 1; i <= M; i++) {
            int aa, bb, cc;
            scanf("%d %d %d", &aa, &bb, &cc);
            for (int j = aa; j <= 1000000 and possible; j += cc) {
                for (int k = j; k < j + bb - aa and k <= 1000000 and possible;
                     k++) {
                    if (B[k] == true) {
                        possible = false;
                        break;
                    }
                    B[k] = true;
                }
            }
        }
        if (possible)
            printf("NO CONFLICT\n");
        else
            printf("CONFLICT\n");
    }
    return 0;
}