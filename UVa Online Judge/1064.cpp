/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1064.cpp
#  Description:     UVa Online Judge - 1064
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int N, M, permu[10];
int A[1005][5], B[10];
;

int main() {
    // freopen("in","r",stdin);
    int test = 0;
    while (scanf("%d %d", &N, &M) == 2) {
        if (N + M == 0) break;
        for (int i = 1; i <= N; i++) permu[i] = i;
        for (int i = 1; i <= N; i++) scanf("%d", &B[i]);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= 3; j++) scanf("%d", &A[i][j]);

        int ans = 1e9, tmp, nowid, nowval, buffer;
        do {
            buffer = 0;
            tmp = 0;
            nowval = 1;
            nowid = 1;
            priority_queue<ii, vector<ii>, greater<ii> > PQ[8];
            // for(int i=1;i<=N;i++) printf("[%d]",permu[i]);
            // printf("\n");

            for (int i = 1; i <= M; i++) {
                while (!PQ[permu[nowid]].empty() and
                       PQ[permu[nowid]].top().first == nowval) {
                    nowval = PQ[permu[nowid]].top().second + 1;
                    tmp -= PQ[permu[nowid]].top().second -
                           PQ[permu[nowid]].top().first + 1;
                    // printf("\tpop [%d] (%d,%d)
                    // [%d]\n",permu[nowid],PQ[permu[nowid]].top().first,PQ[permu[nowid]].top().second,nowval);
                    PQ[permu[nowid]].pop();

                    if (nowval > B[permu[nowid]]) {
                        nowid++;
                        nowval = 1;
                    }
                }

                if (A[i][1] == permu[nowid] and A[i][2] == nowval) {
                    // printf("pass [%d] (%d,%d)\n",A[i][1],A[i][2],A[i][3]);
                    nowval = A[i][3] + 1;
                    if (nowval > B[permu[nowid]]) {
                        nowid++;
                        nowval = 1;
                    }
                } else {
                    tmp += A[i][3] - A[i][2] + 1;
                    PQ[A[i][1]].push(ii(A[i][2], A[i][3]));
                    // printf("\tpush [%d] (%d,%d)
                    // {%d}\n",A[i][1],A[i][2],A[i][3],tmp);
                }
                buffer = max(tmp, buffer);
            }
            ans = min(ans, buffer);
            // printf("\n");
        } while (next_permutation(permu + 1, permu + 1 + N));
        printf("Case %d: %d\n\n", ++test, ans);
    }
    return 0;
}