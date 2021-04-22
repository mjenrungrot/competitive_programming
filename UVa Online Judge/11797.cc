/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11797.cc
#  Description:     UVa Online Judge - 11797
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

map<string, int> nameToIdx;
queue<string> Q[5];
int counter[5];
int M, N;
string name;

int main() {
    nameToIdx["Ja"] = 0;
    nameToIdx["Sam"] = 1;
    nameToIdx["Sha"] = 2;
    nameToIdx["Sid"] = 3;
    nameToIdx["Tan"] = 4;

    int T;
    scanf("%d", &T);
    for (int _i = 1; _i <= T; _i++) {
        printf("Case %d:\n", _i);

        memset(counter, 0, sizeof(counter));
        for (int k = 0; k < 5; k++)
            while (not Q[k].empty()) Q[k].pop();

        scanf("%d %d", &M, &N);
        cin >> name;

        for (int k = 0; k < 5; k++) {
            int x;
            string tmp;
            scanf("%d", &x);
            for (int i = 1; i <= x; i++) {
                cin >> tmp;
                Q[k].push(tmp);
            }
        }

        int curr = 0, curr_idx = nameToIdx[name];
        while (curr < N) {
            curr++;
            counter[curr_idx]++;
            if (curr == M) {
                N -= M;
                N -= 2;
                curr = 0;

                string new_person = Q[curr_idx].front();
                Q[curr_idx].pop();
                Q[curr_idx].push(new_person);
                curr_idx = nameToIdx[new_person];
            }
        }
        printf("Ja %d\n", counter[0]);
        printf("Sam %d\n", counter[1]);
        printf("Sha %d\n", counter[2]);
        printf("Sid %d\n", counter[3]);
        printf("Tan %d\n", counter[4]);
    }
    return 0;
}