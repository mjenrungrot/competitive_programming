/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13113.cc
#  Description:     UVa Online Judge - 13113
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int n_candidates, n_states;
double percentages[1005][505];
long long n_votes[1005], total_votes;

typedef pair<double, int> p;
p scores[505];

void run() {
    scanf("%d %d", &n_candidates, &n_states);
    total_votes = 0;
    for (int i = 1; i <= n_candidates; i++) scores[i] = p(0, i);
    for (int i = 1; i <= n_states; i++) {
        for (int j = 1; j <= n_candidates; j++)
            scanf("%lf", &percentages[i][j]);
        scanf("%d", &n_votes[i]);
        for (int j = 1; j <= n_candidates; j++) {
            scores[j] = p(scores[j].first +
                              percentages[i][j] * (double)n_votes[i] / 100.0,
                          j);
        }
        total_votes += n_votes[i];
    }

    sort(&scores[1], &scores[n_candidates + 1], [](p our, p other) {
        if (our.first != other.first) return our.first > other.first;
        return our.second < other.second;
    });
    if ((double)scores[1].first / (double)total_votes * 100.0 >= 50.1) {
        printf("%d %.0lf\n", scores[1].second, scores[1].first);
    } else {
        printf("%d %.0lf\n", scores[1].second, scores[1].first);
        printf("%d %.0lf\n", scores[2].second, scores[2].first);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        run();
        if (T) printf("\n");
    }
    return 0;
}