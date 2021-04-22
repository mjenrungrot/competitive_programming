/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11203.cc
#  Description:     UVa Online Judge - 11203
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

string line;
int length;
int L, M, R;
int Mpos, Epos;
int MM, EE, QQ, OO;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        cin >> line;
        L = M = R = 0;
        Mpos = Epos = -1;
        length = line.length();
        MM = EE = QQ = OO = 0;

        for (int i = 0; i < length; i++) {
            if (Mpos == -1 and line[i] == '?')
                L++;
            else if (Mpos != -1 and Epos == -1 and line[i] == '?')
                M++;
            else if (line[i] == '?')
                R++;

            if (line[i] == 'M' and Mpos == -1)
                Mpos = i, MM++;
            else if (line[i] == 'E' and Epos == -1)
                Epos = i, EE++;
            else if (line[i] == '?')
                QQ++;
            else
                OO++;
        }

        if (((L + M) != R) or (OO >= 1) or (MM != 1) or (EE != 1) or
            ((Epos - Mpos) < 2) or (Mpos == 0) or (Epos == length - 1)) {
            printf("no-theorem\n");
        } else {
            printf("theorem\n");
        }
    }
    return 0;
}