/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12207.cpp
#  Description:     UVa Online Judge - 12207
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int P, C, x, tt = 0;
    while (scanf("%d %d", &x, &C) == 2) {
        if (x == 0 and C == 0) break;
        printf("Case %d:\n", ++tt);
        P = min(x, 1000);

        deque<int> Q;
        for (int i = 1; i <= P; i++) Q.push_back(i);

        char str[5];
        for (int i = 1; i <= C; i++) {
            scanf("%s", str);
            if (str[0] == 'N') {
                printf("%d\n", Q.front());
                Q.push_back(Q.front());
                Q.pop_front();
            } else {
                scanf("%d", &x);
                for (int j = 0; j < (int)Q.size(); j++)
                    if (Q[j] == x) {
                        Q.erase(Q.begin() + j);
                        break;
                    }
                Q.push_front(x);
            }
        }
    }
    return 0;
}