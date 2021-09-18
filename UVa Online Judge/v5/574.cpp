/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        574.cpp
#  Description:     UVa Online Judge - 574
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int V, N, A[20];
int ans[20], len;
bool found;

vector<vector<int> > VV;

void f(int nn, int val) {
    if (val == V) {
        found = true;
        vector<int> xx;
        for (int i = 1; i <= len; i++) xx.push_back(ans[i]);
        VV.push_back(xx);
        return;
    }
    if (nn > N) return;

    len++;
    ans[len] = A[nn];
    f(nn + 1, val + A[nn]);
    len--;
    f(nn + 1, val);
}

int cmp(vector<int> _A, vector<int> _B) {
    for (int i = 0; i < (int)_A.size() and i < (int)_B.size(); i++) {
        if (_A[i] != _B[i]) return _A[i] > _B[i];
    }
    return 0;
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    while (scanf("%d %d", &V, &N) == 2) {
        if (V + N == 0) break;
        printf("Sums of %d:\n", V);
        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
        len = 0;
        found = false;
        VV.clear();
        f(1, 0);

        sort(VV.begin(), VV.end());
        VV.erase(unique(VV.begin(), VV.end()), VV.end());
        sort(VV.begin(), VV.end(), cmp);

        for (int i = 0; i < (int)VV.size(); i++) {
            for (int j = 0; j < (int)VV[i].size(); j++) {
                if (j) printf("+");
                printf("%d", VV[i][j]);
            }
            printf("\n");
        }

        if (not found) printf("NONE\n");
    }

    return 0;
}