/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1583.cc
#  Description:     UVa Online Judge - 1583
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int T, N;
int smallest_generators[100005];

int sum_digit(int x) {
    if (x < 10) return x;
    return (x % 10) + sum_digit(x / 10);
}

int main() {
    for (int i = 1; i <= 100000; i++) smallest_generators[i] = INF;
    for (int i = 1; i <= 100000; i++) {
        int generator = i + sum_digit(i);
        smallest_generators[generator] = min(smallest_generators[generator], i);
    }
    for (int i = 1; i <= 100000; i++)
        if (smallest_generators[i] == INF) smallest_generators[i] = 0;

    cin >> T;
    while (T--) {
        cin >> N;
        cout << smallest_generators[N] << endl;
    }
    return 0;
}