/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1047.cpp
#  Description:     UVa Online Judge - 1047
=============================================================================*/
#include <cstdio>
#include <vector>
using namespace std;

int N, M, Q;
int A[30], B[20];
vector<int> V[20];

int f(int bitmask) {
    int cc = 0;
    for (int i = 0; i < N; i++)
        if ((1 << i) & bitmask) cc++;
    if (cc > M or cc < M) return 0;

    int ans = 0;
    for (int i = 0; i < N; i++)
        if ((1 << i) & bitmask) ans += A[i];

    for (int i = 1; i <= Q; i++) {
        cc = 0;
        for (int j = 0; j < (int)V[i].size(); j++)
            if (bitmask & (1 << V[i][j])) cc++;
        if (cc > 0) ans -= (cc - 1) * B[i];
    }

    // for(int i=0;i<N;i++) printf("%d",((1<<i)&bitmask) > 0);
    // printf(" = %d\n",ans);
    return ans;
}

int main() {
    // freopen("in","r",stdin);

    int test = 0;
    while (scanf("%d %d", &N, &M) == 2) {
        if (N + M == 0) break;
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        scanf("%d", &Q);
        for (int i = 1; i <= Q; i++) {
            V[i].clear();
            int tt;
            scanf("%d", &tt);
            for (int j = 0; j < tt; j++) {
                int yy;
                scanf("%d", &yy);
                yy--;
                V[i].push_back(yy);
            }
            scanf("%d", &B[i]);
        }

        int ans = 0, bitmask = 0;
        for (int i = 0; i < (1 << N); i++) {
            int val = f(i);
            if (val > ans) {
                ans = val;
                bitmask = i;
            }
        }

        printf("Case Number  %d\n", ++test);
        printf("Number of Customers: %d\n", ans);
        printf("Locations recommended:");
        for (int i = 0; i < N; i++)
            if ((1 << i) & bitmask) printf(" %d", i + 1);
        printf("\n\n");
    }
    return 0;
}