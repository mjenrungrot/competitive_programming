/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12108.cc
#  Description:     UVa Online Judge - 12108
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

struct state {
    int c[15];
    state() { memset(c, 0, sizeof(c)); }

    bool operator<(const state o) const {
        return memcmp(c, o.c, sizeof(state)) < 0;
    }
};

int N;
int a[15], b[15], c[15];

int main() {
    int nt = 0;
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        set<state> record;

        nt++;
        for (int i = 1; i <= N; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);

        int curr_time = 1;
        int n_sleep, n_awake;
        while (true) {
            state q;
            for (int i = 1; i <= N; i++) q.c[i] = c[i];
            if (record.find(q) != record.end()) {
                printf("Case %d: -1\n", nt);
                break;
            }
            record.insert(q);

            n_sleep = 0;
            for (int i = 1; i <= N; i++)
                if (c[i] > a[i]) n_sleep++;
            n_awake = N - n_sleep;

            if (n_sleep == 0) {
                printf("Case %d: %d\n", nt, curr_time);
                break;
            }

            for (int i = 1; i <= N; i++) {
                c[i]++;
                if (c[i] == a[i] + b[i] + 1) c[i] = 1;
                if (c[i] == a[i] + 1 and n_awake >= n_sleep) c[i] = 1;
            }
            curr_time++;
        }
    }
    return 0;
}