/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        540.cpp
#  Description:     UVa Online Judge - 540
=============================================================================*/
#include <cassert>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N;
char str[20];
string S;
int team[1000005];
int occupied[1005];

queue<int> Q_team;
queue<int> Q[1005];

int main() {
    // freopen("in","r",stdin);
    int test = 0;
    while (scanf("%d", &N) == 1) {
        if (!N) break;
        printf("Scenario #%d\n", ++test);

        memset(team, 0, sizeof team);
        memset(occupied, 0, sizeof occupied);
        for (int i = 1; i <= N; i++) {
            int nn;
            scanf("%d", &nn);
            for (int j = 1; j <= nn; j++) {
                int xx;
                scanf("%d", &xx);
                team[xx] = i;
            }
        }
        while (!Q_team.empty()) Q_team.pop();
        for (int i = 1; i <= 1000; i++)
            while (!Q[i].empty()) Q[i].pop();

        while (scanf("%s", str) == 1) {
            S = str;
            if (S == "ENQUEUE") {
                int x;
                scanf("%d", &x);
                if (occupied[team[x]])
                    Q[team[x]].push(x);
                else {
                    occupied[team[x]] = true;
                    Q_team.push(team[x]);
                    Q[team[x]].push(x);
                }
            } else if (S == "DEQUEUE") {
                // assert(!Q_team.empty());

                int a1 = Q_team.front();
                int a2 = Q[a1].front();
                Q[a1].pop();
                if (Q[a1].empty()) {
                    Q_team.pop();
                    occupied[a1] = false;
                }
                printf("%d\n", a2);
            } else if (S == "STOP") {
                break;
            }
        }
        printf("\n");
    }
    return 0;
}