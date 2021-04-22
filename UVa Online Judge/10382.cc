/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10382.cc
#  Description:     UVa Online Judge - 10382
=============================================================================*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<double, double> dd;

const double EPS = 1e-8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    double L, W;
    while (cin >> N >> L >> W) {
        vector<dd> A;

        for (int i = 0; i < N; i++) {
            double tmp_x, tmp_r;
            cin >> tmp_x >> tmp_r;

            if (W / 2.0 > tmp_r) continue;

            double left = tmp_x - sqrt(tmp_r * tmp_r - (W / 2.0) * (W / 2.0));
            double right = tmp_x + sqrt(tmp_r * tmp_r - (W / 2.0) * (W / 2.0));

            A.push_back(dd(left, right));
        }

        sort(A.begin(), A.end(), [](dd x, dd y) {
            if (fabs(x.first - y.first) > EPS) return x.first < y.first;
            return x.second > y.second;
        });

        bool possible = true;
        int ans = 0;
        double curr_right = 0.0;
        int curr_idx = 0;
        while (curr_idx < A.size()) {
            if (A[curr_idx].second < curr_right + EPS) {
                curr_idx++;
                continue;
            }

            if (A[curr_idx].first < curr_right + EPS) {
                int next_idx = curr_idx;
                int best_idx = -1;
                double best = -1e9;

                while (next_idx < A.size() and
                       A[next_idx].first < curr_right + EPS) {
                    if (A[next_idx].second > best) {
                        best = A[next_idx].second;
                        best_idx = next_idx;
                    }
                    next_idx++;
                }
                if (best_idx == -1) {
                    possible = false;
                    break;
                }

                ans++;
                curr_right = best;
                if (L < curr_right + EPS) break;

                curr_idx = next_idx;
            } else {
                possible = false;
                break;
            }
        }
        if (curr_right < L) possible = false;

        if (possible)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}