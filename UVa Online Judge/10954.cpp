/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10954.cpp
#  Description:     UVa Online Judge - 10954
=============================================================================*/
#include <cstdio>
#include <queue>
using namespace std;

int main() {
    // freopen("in","r",stdin);
    int N;
    while (scanf("%d", &N) == 1) {
        if (!N) break;

        priority_queue<int, vector<int>, greater<int> > PQ;
        for (int i = 1; i <= N; i++) {
            int xx;
            scanf("%d", &xx);
            PQ.push(xx);
        }

        int ans = 0;
        for (int i = 1; i <= N - 1; i++) {
            int a = PQ.top();
            PQ.pop();
            int b = PQ.top();
            PQ.pop();
            ans += a + b;
            PQ.push(a + b);
        }
        printf("%d\n", ans);
    }
    return 0;
}