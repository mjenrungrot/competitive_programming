/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11991.cpp
#  Description:     UVa Online Judge - 11991
=============================================================================*/
#include <cstdio>
#include <vector>
using namespace std;

vector<int> V[1000005];

int main() {
    // freopen("in","r",stdin);
    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        for (int i = 0; i <= 1000000; i++) V[i].clear();

        for (int i = 1; i <= N; i++) {
            int xx;
            scanf("%d", &xx);
            V[xx].push_back(i);
        }

        for (int i = 1; i <= M; i++) {
            int k, v;
            scanf("%d %d", &k, &v);
            if ((int)V[v].size() >= k)
                printf("%d\n", V[v][k - 1]);
            else
                printf("0\n");
        }
    }
    return 0;
}