/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12845.cc
#  Description:     UVa Online Judge - 12845
=============================================================================*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        vector<int> A;

        int sum = 0;
        for (int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            A.push_back(tmp);
            sum += tmp;
        }
        if (sum % N != 0) {
            cout << -1 << endl;
            continue;
        }

        int ans = 0;
        int target = sum / N;
        for (int i = 0; i < N; i++) ans += abs(A[i] - target);
        ans /= 2;
        cout << ans + 1 << endl;
    }
    return 0;
}