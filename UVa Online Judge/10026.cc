/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10026.cc
#  Description:     UVa Online Judge - 10026
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<int, int, int> iii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<iii> A;
        for (int i = 1; i <= N; i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            A.push_back(iii(tmp1, tmp2, i));
        }

        sort(A.begin(), A.end(), [](iii x, iii y) {
            int cost_x_first = get<0>(x) * get<1>(y);
            int cost_y_first = get<0>(y) * get<1>(x);
            if (cost_x_first != cost_y_first)
                return cost_x_first < cost_y_first;
            return get<2>(x) < get<2>(y);
        });

        for (int i = 0; i < A.size(); i++) {
            if (i) cout << " ";
            cout << get<2>(A[i]);
        }
        cout << endl;

        if (T) cout << endl;
    }

    return 0;
}