/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10440.cc
#  Description:     UVa Online Judge - 10440
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, T, M;
        cin >> N >> T >> M;

        vector<int> ti(M);
        for (int i = 0; i < M; i++) cin >> ti[i];
        sort(ti.begin(), ti.end());

        int curr_time = 0, n_trips = 0;

        /* Move the first M%N cars

        Note: We argue that if M % N > 0, it is always optimal to
        move the first M % N cars together.

        Let x_1 <= ... <= x_M be the time of arrivals and K = M % N
        where K > 0. We'll prove by contradiction by supposing to
        the contrary that the optimal solution doesn't put the first K
        cars together. Note that our solution has the number of trips
        equal to 1 + (M-K) / N

        This implies that we put T < K cars together, and the remaining
        K - T cars on the later trips. Since (M-K)%N == 0, this number of
        trips will be 2 + (M-K) / N which is not optimal, making a
        contradiction.
        */
        if (M % N) {
            curr_time = ti[M % N - 1] + 2 * T;
            n_trips++;
        }

        // Move the remaining
        for (int i = M % N + N - 1; i < M; i += N) {
            curr_time = max(curr_time, ti[i]) + 2 * T;
            n_trips++;
        }
        curr_time -= T;

        cout << curr_time << " " << n_trips << endl;
    }
    return 0;
}