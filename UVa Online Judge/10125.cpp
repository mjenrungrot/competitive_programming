/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10125.cpp
#  Description:     UVa Online Judge - 10125
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int N;
vector<int> V;

vector<ii> A[1000005];
set<int> S;
map<int, int> M;

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        if (!N) break;

        V.clear();
        for (int i = 1; i <= N; i++) {
            int xx;
            scanf("%d", &xx);
            V.push_back(xx);
        }
        sort(V.begin(), V.end());

        S.clear();
        M.clear();
        for (int i = 0; i < 1000005; i++) A[i].clear();
        int counter = 0;
        for (int i = 0; i < (int)V.size(); i++)
            for (int j = i + 1; j < (int)V.size(); j++) S.insert(V[i] + V[j]);
        for (set<int>::iterator it = S.begin(); it != S.end(); it++)
            M[*it] = ++counter;
        for (int i = 0; i < (int)V.size(); i++)
            for (int j = i + 1; j < (int)V.size(); j++)
                A[M[V[i] + V[j]]].push_back(ii(i, j));

        int ans = -2e9;
        for (int i = V.size() - 1; i >= 0; i--)
            for (int j = 0; j < (int)V.size(); j++) {
                if (i == j) continue;
                if (S.count(V[i] - V[j])) {
                    int id = M[V[i] - V[j]];
                    for (int k = 0; k < (int)A[id].size(); k++) {
                        if (V[i] == V[A[id][k].first] or
                            V[i] == V[A[id][k].second] or
                            V[j] == V[A[id][k].first] or
                            V[j] == V[A[id][k].second])
                            continue;
                        // printf("%d + %d + %d =
                        // %d\n",V[A[id][k].second],V[A[id][k].first],V[j],V[i]);
                        ans = max(ans, V[i]);
                        goto end;
                    }
                }
            }
    end:
        if (ans == -2e9)
            printf("no solution\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}