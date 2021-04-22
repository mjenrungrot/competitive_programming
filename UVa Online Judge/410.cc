/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        410.cc
#  Description:     UVa Online Judge - 410
=============================================================================*/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    int n_test = 0;
    while (cin >> K >> N) {
        cout << "Set #" << (++n_test) << endl;
        vector<int> vi;

        double avg = 0.0;
        for (int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            vi.push_back(tmp);
            avg += (double)tmp;
        }
        avg /= (double)K;
        for (int i = N + 1; i <= 2 * K; i++) vi.push_back(0);

        sort(vi.begin(), vi.end());

        double ans = 0.0;
        for (int i = 0, j = 2 * K - 1; i < j; i++, j--) {
            ans += fabs((double)(vi[i] + vi[j]) - avg);

            cout << " " << i << ":";
            if (vi[i] > 0) cout << " " << vi[i];
            if (vi[j] > 0) cout << " " << vi[j];
            cout << endl;
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << ans << endl;
        cout << endl;
    }
    return 0;
}