/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        529.cc
#  Description:     UVa Online Judge - 529
=============================================================================*/
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 10005;
int N, arr[MAXN], best_length, best_arr[MAXN];

void f(int idx) {
    if (idx >= best_length) return;

    if (idx <= 1) {
        arr[idx] = (idx == 0) ? 1 : 2;
        f(idx + 1);
    } else {
        if (arr[idx - 1] > N) return;
        if (arr[idx - 1] == N) {
            best_length = idx;
            for (int i = 0; i < idx; i++) best_arr[i] = arr[i];
            return;
        }

        for (int i = idx - 1; i >= 0; i--) {
            arr[idx] = arr[idx - 1] + arr[i];
            int estimate =
                idx + (int)ceil(log2((double)N / (double)arr[idx - 1]));
            if (estimate >= best_length) return;
            f(idx + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    while (cin >> N) {
        if (!N) break;
        if (N == 1) {
            cout << 1 << endl;
            continue;
        }
        if (N == 2) {
            cout << 1 << " " << 2 << endl;
            continue;
        }
        best_length = 1e9;
        f(0);

        for (int i = 0; i < best_length; i++) {
            if (i) cout << " ";
            cout << best_arr[i];
        }
        cout << endl;
    }
    return 0;
}