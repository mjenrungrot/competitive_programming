/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        598.cpp
#  Description:     UVa Online Judge - 598
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

char str[1000];
string name[30];
int L, R, A[30], idx, lim;
int ans[30];

void f(int id, int have) {
    if (have == lim) {
        for (int i = 0; i < have; i++) {
            if (i) printf(", ");
            printf("%s", name[ans[i]].c_str());
        }
        printf("\n");
        return;
    }
    if (id == idx) return;
    ans[have] = id;
    f(id + 1, have + 1);
    f(id + 1, have);
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int T;
    scanf("%d", &T);
    fgets(str, sizeof str, stdin);
    fgets(str, sizeof str, stdin);
    while (T--) {
        fgets(str, sizeof str, stdin);
        bool special = false;
        if (str[0] == '*')
            special = true;
        else {
            char *p = strtok(str, " \n");
            int cc = 0;
            while (p != NULL) {
                if (cc == 0)
                    L = R = atoi(p), cc++;
                else
                    R = atoi(p);
                p = strtok(NULL, " \n");
            }
        }

        idx = 0;
        while (fgets(str, sizeof str, stdin)) {
            if (str[0] == '\n') break;
            char *p = strtok(str, "\n");
            name[idx++] = p;
        }
        if (special) L = 1, R = idx;

        for (lim = L; lim <= R; lim++) {
            printf("Size %d\n", lim);
            f(0, 0);
            printf("\n");
        }

        if (T) printf("\n");
    }
    return 0;
}