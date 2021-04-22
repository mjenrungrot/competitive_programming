/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13007.cc
#  Description:     UVa Online Judge - 13007
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

int N, M;
int ans;
int B, C1, Cj;
int sum, curr, best;

int main() {
    while (scanf("%d %d", &N, &M) == 2) {
        ans = 0;
        for (int i = 1; i <= M; i++) {
            scanf("%d %d", &B, &C1);

            sum = 0;
            for (int j = 2; j <= N; j++) {
                scanf("%d", &Cj);
                sum += Cj;
            }

            if (sum + C1 <= B)
                curr = C1;
            else
                curr = 0;

            if (sum + 10000 <= B)
                best = 10000;
            else if (sum + 1000 <= B)
                best = 1000;
            else if (sum + 100 <= B)
                best = 100;
            else if (sum + 10 <= B)
                best = 10;
            else if (sum + 1 <= B)
                best = 1;
            else
                best = 0;

            ans += (best - curr);
        }
        printf("%d\n", ans);
    }
    return 0;
}