/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11222.cpp
#  Description:     UVa Online Judge - 11222
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<int> V1, V2, V3;

int N1, N2, N3, solved[10005];

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d:\n", i);
        V1.clear();
        V2.clear();
        V3.clear();
        memset(solved, 0, sizeof solved);

        int xx;
        scanf("%d", &N1);
        for (int j = 1; j <= N1; j++) {
            scanf("%d", &xx);
            V1.push_back(xx);
            solved[xx]++;
        }
        scanf("%d", &N2);
        for (int j = 1; j <= N2; j++) {
            scanf("%d", &xx);
            V2.push_back(xx);
            solved[xx]++;
        }
        scanf("%d", &N3);
        for (int j = 1; j <= N3; j++) {
            scanf("%d", &xx);
            V3.push_back(xx);
            solved[xx]++;
        }

        int point1 = 0, point2 = 0, point3 = 0;
        for (int j = 0; j < N1; j++)
            if (solved[V1[j]] == 1) point1++;
        for (int j = 0; j < N2; j++)
            if (solved[V2[j]] == 1) point2++;
        for (int j = 0; j < N3; j++)
            if (solved[V3[j]] == 1) point3++;

        int maxpoint = max(max(point1, point2), point3);

        vector<int> ans;
        if (point1 == maxpoint) {
            printf("1 %d", maxpoint);
            ans.clear();
            for (int j = 0; j < N1; j++)
                if (solved[V1[j]] == 1) ans.push_back(V1[j]);
            sort(ans.begin(), ans.end());
            for (int j = 0; j < (int)ans.size(); j++) printf(" %d", ans[j]);
            printf("\n");
        }
        if (point2 == maxpoint) {
            printf("2 %d", maxpoint);
            ans.clear();
            for (int j = 0; j < N2; j++)
                if (solved[V2[j]] == 1) ans.push_back(V2[j]);
            sort(ans.begin(), ans.end());
            for (int j = 0; j < (int)ans.size(); j++) printf(" %d", ans[j]);
            printf("\n");
        }
        if (point3 == maxpoint) {
            printf("3 %d", maxpoint);
            ans.clear();
            for (int j = 0; j < N3; j++)
                if (solved[V3[j]] == 1) ans.push_back(V3[j]);
            sort(ans.begin(), ans.end());
            for (int j = 0; j < (int)ans.size(); j++) printf(" %d", ans[j]);
            printf("\n");
        }
    }
    return 0;
}