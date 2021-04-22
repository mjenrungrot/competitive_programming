/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10718.cc
#  Description:     UVa Online Judge - 10718
=============================================================================*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned int N, L, U;
    while (cin >> N >> L >> U) {
        unsigned int curr = 0LL;
        for (int i = 31; i >= 0; i--) {
            if (curr + (1U << i) < L)
                curr |= (1U << i);
            else {
                if (curr + (1U << i) > U) continue;

                if ((1U << i) & N) {
                    if (curr + (1U << i) - 1 < L) curr |= (1U << i);
                    continue;
                } else {
                    curr |= (1U << i);
                }
            }
        }
        cout << curr << endl;
    }
    return 0;
}