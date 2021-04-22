/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12100.cpp
#  Description:     UVa Online Judge - 12100
=============================================================================*/
#include <cstdio>
#include <deque>
using namespace std;

typedef pair<int, int> ii;

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        deque<ii> Q;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            Q.push_back(ii(x, i));
        }
        int tt = 0;
        while (true) {
            bool have_greater = false;
            for (int i = 1; i < (int)Q.size(); i++) {
                if (Q[i].first > Q[0].first) {
                    Q.push_back(Q[0]);
                    Q.pop_front();
                    have_greater = true;
                    break;
                }
            }
            if (have_greater)
                continue;
            else {
                ++tt;
                if (Q[0].second == M) {
                    printf("%d\n", tt);
                    break;
                }
                Q.pop_front();
            }
        }
    }
    return 0;
}