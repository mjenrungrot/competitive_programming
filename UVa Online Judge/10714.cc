/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10714.cc
#  Description:     UVa Online Judge - 10714
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
        int L, N;
        cin >> L >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());

        int min_val = 0;
        int max_val = 0;
        for (auto u : A) {
            min_val = max(min_val, min(u, L - u));
            max_val = max(max_val, max(u, L - u));
        }
        cout << min_val << " " << max_val << endl;
    }
    return 0;
}