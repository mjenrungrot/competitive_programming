/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11742.cpp
#  Description:     UVa Online Judge - 11742
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int N, M;
int A[30][3], B[30];

int abs(int x) { return x < 0 ? -x : x; }

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 and M == 0) break;
        for (int i = 1; i <= M; i++)
            scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
        for (int i = 0; i < N; i++) B[i] = i;

        int ans = 0;
        do {
            int id1, id2, val;
            for (int i = 1; i <= M; i++) {
                for (int j = 0; j < N; j++) {
                    if (B[j] == A[i][0]) id1 = j;
                    if (B[j] == A[i][1]) id2 = j;
                }

                if (A[i][2] > 0) {
                    if (abs(id1 - id2) <= A[i][2])
                        continue;
                    else
                        goto fail;
                } else {
                    if (abs(id1 - id2) >= -A[i][2])
                        continue;
                    else
                        goto fail;
                }
            }

            ans++;
        // for(int j=0;j<N;j++) printf("[%d]",B[j]); printf("\n");
        fail:;
        } while (next_permutation(B, B + N));
        printf("%d\n", ans);
    }
    return 0;
}