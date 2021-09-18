/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12801.cc
#  Description:     UVa Online Judge - 12801
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int N, C;
int A[100005];

int main() {
    ios::sync_with_stdio(false);
    while (cin >> N >> C) {
        for (int i = 1; i <= C; i++) cin >> A[i];
        A[C + 1] = N + A[1];

        bool ok = false;
        int pizza_size = N / C;
        for (int i = A[1]; i < A[2]; i++) {
            // the first pizza ends at i
            int curr = i;
            bool pass = true;
            for (int j = 2; j <= C + 1; j++) {
                // must be in (i, i+pizza_size]
                if (curr < A[j] and A[j] <= curr + pizza_size) {
                    curr += pizza_size;
                } else {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "S" : "N") << endl;
    }
    return 0;
}