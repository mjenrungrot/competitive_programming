/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11412.cpp
#  Description:     UVa Online Judge - 11412
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

char str1[10], str2[10];
char ans1[10];
int n11, n12, n21, n22;

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s %d %d", str1, &n11, &n12);
        scanf("%s %d %d", str2, &n21, &n22);

        char tmp[] = {'B', 'G', 'O', 'R', 'V', 'Y'};
        int n_possible = 0;
        do {
            next_permutation(tmp, tmp + 6);
            int tmp1 = 0, tmp2 = 0, mask = 0;
            for (int i = 0; i < 4; i++)
                if (tmp[i] == str1[i]) tmp1++, mask |= (1 << i);
            for (int i = 0; i < 4; i++)
                if (tmp[i] != str1[i]) {
                    for (int j = 0; j < 4; j++) {
                        if (i == j) continue;
                        if (mask & (1 << j)) continue;
                        if (tmp[i] == str1[j]) tmp2++;
                    }
                }

            if (tmp1 != n11 or tmp2 != n12) continue;

            tmp1 = tmp2 = mask = 0;
            for (int i = 0; i < 4; i++)
                if (tmp[i] == str2[i]) tmp1++, mask |= (1 << i);
            for (int i = 0; i < 4; i++)
                if (tmp[i] != str2[i]) {
                    for (int j = 0; j < 4; j++) {
                        if (i == j) continue;
                        if (mask & (1 << j)) continue;
                        if (tmp[i] == str2[j]) tmp2++;
                    }
                }

            if (tmp1 != n21 or tmp2 != n22) continue;
            n_possible++;
        } while (next_permutation(tmp, tmp + 6));
        printf("%s\n", n_possible < 1 ? "Cheat" : "Possible");
    }
    return 0;
}