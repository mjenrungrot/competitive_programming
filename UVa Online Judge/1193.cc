/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1193.cc
#  Description:     UVa Online Judge - 1193
=============================================================================*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, n_case = 0;
    double D;
    while (cin >> N >> D) {
        if (N == 0 and D == 0) break;

        vector<tuple<double, double> > A;
        bool possible = true;
        for (int i = 1; i <= N; i++) {
            int tmp_x, tmp_y;
            cin >> tmp_x >> tmp_y;

            if (tmp_y > D) possible = false;
            if (possible) {
                double left = tmp_x - sqrt(D * D - tmp_y * tmp_y);
                double right = tmp_x + sqrt(D * D - tmp_y * tmp_y);
                A.push_back(tuple<double, double>(left, right));
            }
        }
        sort(A.begin(), A.end(),
             [](tuple<double, double> x, tuple<double, double> y) {
                 if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
                 return get<1>(x) > get<1>(y);
             });

        int ans = 0;
        for (int i = 0; i < (int)A.size() and possible; i++) {
            double left = get<0>(A[i]);
            double right = get<1>(A[i]);

            int k = i + 1;
            double best_right = right;
            while (k < (int)A.size() and get<0>(A[k]) <= best_right) {
                best_right = min(best_right, get<1>(A[k]));
                k++;
            }
            i = k - 1;
            ans++;
        }
        if (possible)
            cout << "Case " << ++n_case << ": " << ans << endl;
        else
            cout << "Case " << ++n_case << ": -1" << endl;
    }

    return 0;
}