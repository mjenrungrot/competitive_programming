/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1368.cc
#  Description:     UVa Online Judge - 1368
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int T, N, K;
char lines[55][1005];
char ans[1005];
int countA, countC, countG, countT;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        for (int i = 1; i <= N; i++) scanf("%s", &lines[i][1]);

        for (int i = 1; i <= K; i++) {
            countA = countC = countG = countT = 0;
            for (int j = 1; j <= N; j++) {
                if (lines[j][i] == 'A')
                    countA++;
                else if (lines[j][i] == 'C')
                    countC++;
                else if (lines[j][i] == 'G')
                    countG++;
                else
                    countT++;
            }
            if (countA >= countC and countA >= countG and countA >= countT) {
                ans[i] = 'A';
            } else if (countC >= countA and countC >= countG and
                       countC >= countT) {
                ans[i] = 'C';
            } else if (countG >= countA and countG >= countC and
                       countG >= countT) {
                ans[i] = 'G';
            } else {
                ans[i] = 'T';
            }
        }

        int dist = 0;
        for (int i = 1; i <= K; i++) {
            printf("%c", ans[i]);
            for (int j = 1; j <= N; j++)
                if (ans[i] != lines[j][i]) dist++;
        }
        printf("\n%d\n", dist);
    }

    return 0;
}