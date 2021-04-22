/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        617.cpp
#  Description:     UVa Online Judge - 617
=============================================================================*/
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

const double EPS = 1e-9;

int A[10][4], N;
double dist[10];

void print(vector<int> V) {
    if (V.empty()) {
        printf("No acceptable speeds.");
        return;
    }

    int L = V[0], R = V[0];
    bool print = false;
    for (int i = 1; i < (int)V.size(); i++) {
        if (V[i] == V[i - 1] + 1) {
            R = V[i];
        } else {
            if (print) printf(", ");
            print = true;
            if (L != R)
                printf("%d-%d", L, R);
            else
                printf("%d", L);
            L = R = V[i];
        }
    }
    if (print) printf(", ");
    if (L != R)
        printf("%d-%d", L, R);
    else
        printf("%d", L);
}

bool check(int val) {
    for (int i = 1; i <= N; i++) {
        double tt = dist[i] * 3600.0 / (double)val;
        // printf("tt = %lf\n",tt);

        double interval = (double)A[i][1] + (double)A[i][2] + (double)A[i][3];
        double times = floor(tt / interval);

        double remain = tt - times * interval;
        // printf("remain = %lf\n",remain);

        if (remain < (double)A[i][1] + (double)A[i][2])
            continue;
        else if (fabs(remain - (double)A[i][1] - (double)A[i][2]) < EPS)
            continue;
        else if (fabs(remain - interval) < EPS)
            continue;
        else
            return false;
    }
    return true;
}

int main() {
    // freopen("in","r",stdin);
    int test = 0;
    while (scanf("%d", &N) == 1) {
        if (N == -1) break;
        for (int i = 1; i <= N; i++)
            scanf("%lf %d %d %d", &dist[i], &A[i][1], &A[i][2], &A[i][3]);

        vector<int> ans;
        for (int i = 30; i <= 60; i++)
            if (check(i)) ans.push_back(i);

        printf("Case %d: ", ++test);
        print(ans);
        printf("\n");
    }
    return 0;
}