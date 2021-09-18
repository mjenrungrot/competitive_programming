/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13103.cc
#  Description:     UVa Online Judge - 13103
=============================================================================*/
#include <iostream>
using namespace std;

int digits[30], count1;
long long n, k, answer;

void f(int idx, long long curr, int curr_count1) {
    if (curr_count1 > count1) return;
    if (idx == k) {
        if (curr_count1 != count1) return;
        if (curr % 7LL == 0 and curr > answer) answer = curr;
        return;
    }

    f(idx + 1, curr, curr_count1);
    f(idx + 1, curr | (1LL << digits[idx]), curr_count1 + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    while (cin >> n) {
        cin >> k;
        for (int i = 0; i < k; i++) cin >> digits[i];

        answer = 0;
        count1 = 0;
        for (int i = 0; i < k; i++) {
            if (n & (1LL << digits[i])) count1++;
            n &= ~(1LL << digits[i]);
        }
        f(0, n, 0);
        cout << answer << endl;
    }

    return 0;
}