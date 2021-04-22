/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11034.cpp
#  Description:     UVa Online Judge - 11034
=============================================================================*/
#include <cstdio>
#include <queue>
using namespace std;

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int L, N, x;
        char str[20];
        scanf("%d %d", &L, &N);
        L *= 100;

        queue<int> Q1, Q2;
        for (int i = 1; i <= N; i++) {
            scanf("%d %s", &x, str);
            if (str[0] == 'l')
                Q1.push(x);
            else
                Q2.push(x);
        }

        int now = 0, cap = 0, ans = 0;
        while (!Q1.empty() or !Q2.empty()) {
            if (now == 0) {
                while (!Q1.empty() and cap + Q1.front() <= L) {
                    cap += Q1.front();
                    Q1.pop();
                }
                ans++;
                now = 1;
                cap = 0;
            } else {
                while (!Q2.empty() and cap + Q2.front() <= L) {
                    cap += Q2.front();
                    Q2.pop();
                }
                ans++;
                now = 0;
                cap = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}