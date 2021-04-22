/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12269.cc
#  Description:     UVa Online Judge - 12269
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int nx, ny;
double w;
vector<double> pos;

int main() {
    double tmp, curr;
    while (scanf("%d %d %lf", &nx, &ny, &w) == 3) {
        if (nx == 0 and ny == 0) break;

        bool check_x = false;
        pos.clear();
        pos.reserve(nx);
        for (int i = 1; i <= nx; i++) {
            scanf("%lf", &tmp);
            pos.push_back(tmp);
        }
        sort(pos.begin(), pos.end());
        curr = 0.0;
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i] - w / 2.0 <= curr) {
                curr = max(curr, pos[i] + w / 2.0);
            }
        }
        if (curr >= 75.0) check_x = true;

        bool check_y = false;
        pos.clear();
        pos.reserve(ny);

        for (int i = 1; i <= ny; i++) {
            scanf("%lf", &tmp);
            pos.push_back(tmp);
        }
        sort(pos.begin(), pos.end());
        curr = 0.0;
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i] - w / 2.0 <= curr) {
                curr = max(curr, pos[i] + w / 2.0);
            }
        }
        if (curr >= 100.0) check_y = true;

        if (check_x and check_y)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}