/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13054.cc
#  Description:     UVa Online Judge - 13054
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while (T--) {
        int N, H, Ta, Td;
        cin >> N >> H >> Ta >> Td;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            A[i] = tmp;
        }
        sort(A.begin(), A.end());

        int ans = 0;
        int curr_left = 0, curr_right = N - 1;
        while (curr_left <= curr_right) {
            if (curr_left != curr_right and A[curr_left] + A[curr_right] < H and
                Td < 2 * Ta) {
                ans += Td;
                curr_right--;
                curr_left++;
            } else {
                ans += Ta;
                curr_right--;
            }
        }

        cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}