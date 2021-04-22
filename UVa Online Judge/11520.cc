/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11520.cc
#  Description:     UVa Online Judge - 11520
=============================================================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<string> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << "Case " << ++n_case << ":" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (A[i][j] == '.') {
                    for (int k = 'A'; k <= 'Z'; k++) {
                        if (j + 1 < A[i].length() and A[i][j + 1] == k)
                            continue;
                        if (j - 1 >= 0 and A[i][j - 1] == k) continue;
                        if (i - 1 >= 0 and A[i - 1][j] == k) continue;
                        if (i + 1 < N and A[i + 1][j] == k) continue;
                        A[i][j] = k;
                        break;
                    }
                }
                cout << A[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}