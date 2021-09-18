/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13082.cc
#  Description:     UVa Online Judge - 13082
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n_case = 0;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        int curr = 1;
        for (int i = 0; i < N; i++) {
            if (A[i] == curr) {
                curr++;
            }
        }

        int ans = N - curr + 1;
        cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}