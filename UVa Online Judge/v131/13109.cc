/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13109.cc
#  Description:     UVa Online Judge - 13109
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
        int N, W;
        cin >> N >> W;

        vector<int> A;
        for (int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            A.push_back(tmp);
        }
        sort(A.begin(), A.end());

        int curr_sum = 0, curr_num = 0;
        for (auto x : A) {
            if (curr_sum + x <= W) {
                curr_sum += x;
                curr_num++;
            }
        }
        cout << curr_num << endl;
    }
    return 0;
}