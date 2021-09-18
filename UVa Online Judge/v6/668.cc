/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        668.cc
#  Description:     UVa Online Judge - 668
=============================================================================*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int max_val = 2;
        while ((max_val - 1) * (max_val + 2) / 2 < N) max_val++;

        int total = (max_val - 1) * (max_val + 2) / 2;
        int rem = total - N;
        bool special = false;
        if (rem == 1) {
            special = true;
            max_val++;
            total = (max_val - 1) * (max_val + 2) / 2;
            rem = total - 2 - N;
        }

        bool space = false;
        for (int i = 2; i <= max_val; i++) {
            if (i == rem) continue;
            if (special and i == 2) continue;
            if (space) cout << " ";
            space = true;
            cout << i;
        }
        cout << endl;
        if (T) cout << endl;
    }
    return 0;
}