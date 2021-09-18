/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10935.cpp
#  Description:     UVa Online Judge - 10935
=============================================================================*/
#include <cstdio>
#include <queue>
using namespace std;
int main() {
    // freopen("in","r",stdin);
    int N;
    while (scanf("%d", &N) == 1) {
        if (!N) break;

        if (N == 1) {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }

        queue<int> Q;
        for (int i = 1; i <= N; i++) Q.push(i);

        Q.pop();
        printf("Discarded cards: 1");
        while ((int)Q.size() >= 2) {
            int a = Q.front();
            Q.pop();
            int b = Q.front();
            Q.pop();
            Q.push(a);
            printf(", %d", b);
        }
        printf("\nRemaining card: %d\n", Q.front());
    }
    return 0;
}