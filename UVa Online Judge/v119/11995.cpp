/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11995.cpp
#  Description:     UVa Online Judge - 11995
=============================================================================*/
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int N, a, b;

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        stack<int> S;
        queue<int> Q;
        priority_queue<int> PQ;

        int a1 = 1, a2 = 1, a3 = 1;

        for (int i = 1; i <= N; i++) {
            scanf("%d", &a);
            if (a == 1) {
                scanf("%d", &b);
                S.push(b);
                Q.push(b);
                PQ.push(b);
            } else {
                scanf("%d", &b);
                if (!S.empty() and b != S.top()) a1 = 0;
                if (!Q.empty() and b != Q.front()) a2 = 0;
                if (!PQ.empty() and b != PQ.top()) a3 = 0;

                if (S.empty())
                    a1 = a2 = a3 = 0;
                else
                    S.pop(), Q.pop(), PQ.pop();
            }
        }
        if (a1 + a2 + a3 > 1)
            printf("not sure\n");
        else if (a1 + a2 + a3 == 0)
            printf("impossible\n");
        else if (a1)
            printf("stack\n");
        else if (a2)
            printf("queue\n");
        else if (a3)
            printf("priority queue\n");
    }
    return 0;
}