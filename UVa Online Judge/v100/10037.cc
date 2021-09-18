/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10037.cc
#  Description:     UVa Online Judge - 10037
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
Assume N people and the speed is given by
    x_1 <= x_2 <= ... <= x_n

Base case: N <= 2
    x_1 x_2 or x_1

Base case: N = 3
    x_1 x_2
    x_1
    x_1 x_3
    cost = x_2 + x_1 + x_3

There are 2 strategies:

Strategy 1:
    x_1 x_2
    x_1
    x_n x_{n-1}
    x_2
    ==> cost = x_2 + x_1 + x_n + x_2

Strategy 2:
    x_1 x_n
    x_1
    x_1 x_{n-1}
    x_1
    ==> cost = x_n + x_1 + x_{n-1} + x_1

We'll show that these 2 strategies are optimal.

Case 1: If 2*x_2 <= x_{n-1} + x_1,
We'll show by contradiction that strategy 1 is optimal. Suppose to the contrary
that there are ways to cross x_n and x_{n-1} better than strategy 1. Note that
the strategy 1 costs x_1 + 2*x_2 + x_n. This suggest that x_n and x_{n-1} must
go on separate trips. The cost of the transfers must be at least x_n + x_{n-1} +
2*x_1. If this new strategy is optimal, then it must be the case that

x_n + x_{n-1} + 2*x_1 < x_1 + 2*x_2 + x_n, or
x_{n-1} + x_1 < 2*x_2

causing a contradiction.

Case 2: If 2*x_2 > x_{n-1} + x_1,
Similar to case 1. The new optimal solution must put x_n and x_{n-1} together.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        vector<int> A;

        cin >> N;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            A.push_back(tmp);
        }
        sort(A.begin(), A.end());

        int curr_n = N;
        vector<vector<int> > ans;
        int total_time = 0;
        while (curr_n > 0) {
            if (curr_n == 1) {
                ans.push_back({A[0]});
                total_time += A[0];
                curr_n--;
            } else if (curr_n == 2) {
                ans.push_back({A[0], A[1]});
                total_time += A[1];
                curr_n -= 2;
            } else if (curr_n == 3) {
                ans.push_back({A[0], A[1]});
                ans.push_back({A[0]});
                ans.push_back({A[0], A[2]});
                total_time += A[0] + A[1] + A[2];
                curr_n -= 3;
            } else {
                if (2 * A[1] <= A[0] + A[curr_n - 2]) {
                    ans.push_back({A[0], A[1]});
                    ans.push_back({A[0]});
                    ans.push_back({A[curr_n - 2], A[curr_n - 1]});
                    ans.push_back({A[1]});
                    total_time += A[1] + A[0] + A[curr_n - 1] + A[1];
                } else {
                    ans.push_back({A[0], A[curr_n - 2]});
                    ans.push_back({A[0]});
                    ans.push_back({A[0], A[curr_n - 1]});
                    ans.push_back({A[0]});
                    total_time += A[curr_n - 1] + A[0] + A[curr_n - 2] + A[0];
                }
                curr_n -= 2;
            }
        }

        cout << total_time << endl;
        for (auto row : ans) {
            for (int i = 0; i < row.size(); i++) {
                if (i) cout << " ";
                cout << row[i];
            }
            cout << endl;
        }
        if (T) cout << endl;
    }
    return 0;
}