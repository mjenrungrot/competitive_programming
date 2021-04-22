/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10134.cpp
#  Description:     UVa Online Judge - 10134
=============================================================================*/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string S;
char ss[100];

int f(string ss) {
    if (ss == "fish\n" or ss == "fish") return 1;
    if (ss == "bait\n" or ss == "bait") return 2;
    if (ss == "lunch\n" or ss == "lunch") return 3;
    return 0;
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int T;
    scanf("%d", &T);
    bool line = false;
    fgets(ss, sizeof(ss), stdin);
    fgets(ss, sizeof(ss), stdin);
    while (T--) {
        if (line) printf("\n");
        line = true;

        int n_fish = 0;
        int no_bait = 0, now = 0, fish = 0;
        while (fgets(ss, sizeof(ss), stdin)) {
            if (ss[0] == ' ' or ss[0] == '\n') break;
            int vv = f(S = ss);

            if (vv == 1) {
                if (no_bait >= 2 and
                    ((now >= 7 and fish >= 2) or n_fish == 0)) {
                    n_fish++;
                    fish = 0;
                    now = 0;
                    no_bait -= 2;
                } else {
                    fish++;
                }
                now++;
            } else if (vv == 2) {
                no_bait = min(no_bait + 1, 6);
                now++;
            } else if (vv == 3)
                now++;
        }
        printf("%d\n", n_fish);
    }
    return 0;
}