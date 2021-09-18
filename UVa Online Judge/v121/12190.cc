/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12190.cc
#  Description:     UVa Online Judge - 12190
=============================================================================*/
#include <iostream>
using namespace std;

long long f(long long amount) {
    long long cost = 0;

    if (amount > 1000000) {
        cost += 7 * (amount - 1000000);
        amount = 1000000;
    }
    if (amount > 10000) {
        cost += 5 * (amount - 10000);
        amount = 10000;
    }
    if (amount > 100) {
        cost += 3 * (amount - 100);
        amount = 100;
    }
    cost += 2 * amount;
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long A, B;
    while (cin >> A >> B) {
        if (A == 0 and B == 0) break;

        long long left = 0, right = A + 1, mid;
        while (left < right) {
            mid = (left + right) >> 1LL;
            if (f(mid) > A)
                right = mid;
            else
                left = mid + 1;
        }
        long long total_amount = left - 1LL;

        left = 0, right = total_amount + 1;
        while (left < right) {
            mid = (left + right) >> 1LL;
            if (f(total_amount - mid) - f(mid) > B)
                left = mid + 1;
            else
                right = mid;
        }
        cout << f(left) << endl;
    }
    return 0;
}