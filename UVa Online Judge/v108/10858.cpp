/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10858.cpp
#  Description:     UVa Online Judge - 10858
=============================================================================*/
#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<vector<int> > V;
vector<int> now;

void f(int val, int div) {
    for (int i = div; i * i <= val; i++) {
        if (val % i == 0) {
            now.push_back(i);
            f(val / i, i);
            now.pop_back();
        }
    }
    if (val > 1 and val < N) {
        now.push_back(val);
        V.push_back(now);
        now.pop_back();
    }
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    while (scanf("%d", &N) == 1) {
        if (!N) break;

        V.clear();
        now.clear();
        f(N, 2);

        printf("%d\n", (int)V.size());
        for (int i = 0; i < (int)V.size(); i++) {
            bool space = false;
            for (int j = 0; j < (int)V[i].size(); j++) {
                if (space) printf(" ");
                space = true;
                printf("%d", V[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}