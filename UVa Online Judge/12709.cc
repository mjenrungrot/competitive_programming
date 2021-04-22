/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12709.cc
#  Description:     UVa Online Judge - 12709
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

struct Ant {
    int L, W, H;
    Ant() {}
    Ant(int L, int W, int H) : L(L), W(W), H(H) {}
};

int N;
vector<Ant> ants;

int main() {
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        ants.clear();
        int L, W, H;
        for (int i = 1; i <= N; i++) {
            scanf("%d %d %d", &L, &W, &H);
            ants.push_back(Ant(L, W, H));
        }

        sort(ants.begin(), ants.end(), [](Ant our, Ant other) {
            if (our.H != other.H) return our.H > other.H;
            return our.L * our.W * our.H > other.L * other.W * other.H;
        });

        printf("%d\n", ants[0].L * ants[0].W * ants[0].H);
    }
    return 0;
}