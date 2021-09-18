/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        945.cpp
#  Description:     UVa Online Judge - 945
=============================================================================*/
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> container[15], unused;
int n_container, max_weight[15], sum[15], sum_unused;
int n_package;

void print() {
    int max_height = 0;
    for (int i = 1; i <= n_container; i++)
        max_height = max(max_height, (int)container[i].size());
    for (int i = max_height; i >= 1; i--) {
        for (int j = 1; j <= n_container; j++) {
            if (j > 1) printf(" ");

            if (container[j].size() >= i)
                printf("%d", container[j][i - 1]);
            else
                printf(":");
        }
        printf("\n");
    }
    for (int i = 1; i <= n_container * 2 - 1; i++) printf("=");
    printf("\n");
    for (int i = 1; i <= n_container; i++) {
        if (i > 1) printf(" ");
        printf("%d", i);
    }
    printf("\n");

    int a1 = 0, a2 = 0, a3 = 0;
    for (int i = 1; i <= n_container; i++) {
        a1 += sum[i];
        a2 += max_weight[i] - sum[i];
    }
    for (int i = 0; i < (int)unused.size(); i++) a3 += unused[i];
    printf("\n");
    printf("cargo weight: %d\n", a1);
    printf("unused weight: %d\n", a2);
    printf("unloaded weight: %d\n", a3);
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    bool line = false;
    while (scanf("%d", &n_container) == 1) {
        if (line) printf("\n");
        line = true;

        bool done = false;
        for (int i = 1; i <= n_container; i++) {
            scanf("%d", &max_weight[i]);
            container[i].clear();
            sum[i] = 0;
        }
        scanf("%d", &n_package);
        unused.clear();
        sum_unused = 0;
        bool print2 = false;
        while (n_package--) {
            int xx;
            scanf("%d", &xx);
            if (done) {
                unused.push_back(xx);
                continue;
            }

            int min_package = 1e9;
            for (int i = 1; i <= n_container; i++)
                min_package = min(min_package, (int)container[i].size());

            assert(min_package < 1000);

            int capacity = -1, idx = -1;
            for (int i = 1; i <= n_container; i++)
                if ((int)container[i].size() == min_package and
                    max_weight[i] - sum[i] > capacity) {
                    idx = i;
                    capacity = max_weight[i] - sum[i];
                }

            if (sum[idx] + xx <= max_weight[idx]) {
                sum[idx] += xx;
                container[idx].push_back(xx);
            } else {
                unused.push_back(xx);
                sum_unused += xx;
                done = true;
            }
        }
        print();
    }
    return 0;
}