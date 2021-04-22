/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11835.cpp
#  Description:     UVa Online Judge - 11835
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int G, P, S, K;
vector<vector<int> > V;
vector<int> score;
int point[105];

int main() {
    freopen("in", "r", stdin);
    while (scanf("%d %d", &G, &P) == 2) {
        if (G + P == 0) break;
        V.clear();
        for (int i = 1; i <= G; i++) {
            vector<int> xx;
            for (int j = 1; j <= P; j++) {
                int val;
                scanf("%d", &val);
                xx.push_back(val);
            }
            V.push_back(xx);
        }
        scanf("%d", &S);
        for (int i = 1; i <= S; i++) {
            scanf("%d", &K);
            score.clear();
            for (int j = 1; j <= K; j++) {
                int val;
                scanf("%d", &val);
                score.push_back(val);
            }

            memset(point, 0, sizeof point);
            for (int j = 0; j < V.size(); j++) {
                vector<int> race = V[j];
                for (int k = 0; k < race.size(); k++)
                    if (race[k] <= K) point[k + 1] += score[race[k] - 1];
            }

            int maxpoint = 0;
            for (int i = 1; i <= P; i++) maxpoint = max(maxpoint, point[i]);

            bool space = false;
            for (int i = 1; i <= P; i++) {
                if (point[i] == maxpoint) {
                    if (space) printf(" ");
                    space = true;
                    printf("%d", i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}