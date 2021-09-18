/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11240.cc
#  Description:     UVa Online Judge - 11240
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

        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        vector<int> ans;
        ans.push_back(A[0]);

        for (int i = 1; i < N; i++) {
            if ((int)ans.size() % 2 == 1) {  // just add even case
                if (A[i] >= ans.back()) {
                    ans.back() = A[i];
                } else {
                    ans.push_back(A[i]);
                }
            } else {
                if (A[i] <= ans.back()) {
                    ans.back() = A[i];
                } else {
                    ans.push_back(A[i]);
                }
            }
        }

        cout << ans.size() << endl;
    }

    return 0;
}