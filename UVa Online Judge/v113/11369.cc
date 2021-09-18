/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11369.cc
#  Description:     UVa Online Judge - 11369
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
        int N;
        cin >> N;

        vector<int> A;
        for (int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            A.push_back(tmp);
        }
        sort(A.begin(), A.end(), greater<int>());

        int ans = 0;
        for (int i = 2; i < N; i += 3) ans += A[i];
        cout << ans << endl;
    }

    return 0;
}