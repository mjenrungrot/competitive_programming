/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        234.cpp
#  Description:     UVa Online Judge - 234
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int N, A[10];
int X, tmp[10];

int abs(int x) { return x < 0 ? -x : x; }

int main() {
    // freopen("in","r",stdin);
    int test = 0;
    while (scanf("%d", &N) == 1) {
        if (!N) break;

        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        vector<int> V[10];
        scanf("%d", &X);
        for (int i = 1; i <= X; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            V[a].push_back(b);
        }

        vector<int> ans, tmp_ans;
        vector<int> order;

        vector<int> permu;
        for (int i = 0; i < N; i++) permu.push_back(i);

        do {
            tmp[0] = 0;
            for (int i = 0; i < N; i++) tmp[i + 1] = tmp[i] + A[permu[i]];

            tmp_ans.clear();
            tmp_ans.push_back(0);
            for (int i = 1; i <= 5; i++) {
                int diff = 0;
                for (int j = 0; j < (int)V[i].size(); j++) {
                    int y = lower_bound(tmp, tmp + N + 1, V[i][j]) - tmp;

                    int tt = 1e9;
                    if (y < N + 1) tt = min(tt, abs(V[i][j] - tmp[y]));
                    if (y > 0) tt = min(tt, abs(V[i][j] - tmp[y - 1]));
                    diff += tt;
                }
                tmp_ans.push_back(diff);
            }

            if (ans.empty()) {
                order = permu;
                ans = tmp_ans;
            } else {
                for (int i = 1; i <= 5; i++) {
                    if (tmp_ans[i] != ans[i]) {
                        if (tmp_ans[i] < ans[i]) {
                            order = permu;
                            ans = tmp_ans;
                        }
                        break;
                    }
                }
            }
        } while (next_permutation(permu.begin(), permu.end()));

        printf("Data set %d\n", ++test);
        printf("Order:");
        for (int i = 0; i < (int)order.size(); i++) printf(" %d", A[order[i]]);
        printf("\n");

        int val = 0;
        for (int i = 1; i <= 5; i++) val += ans[i];
        printf("Error: %d\n", val);
    }
    return 0;
}