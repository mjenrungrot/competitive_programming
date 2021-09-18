/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10094.cc
#  Description:     UVa Online Judge - 10094
=============================================================================*/
#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    while (cin >> N) {
        if (N <= 3) {
            cout << "Impossible" << endl;
            continue;
        }

        vector<int> evens, odds, rows;
        for (int i = 1; i <= N; i++) {
            if (i % 2)
                odds.push_back(i);
            else
                evens.push_back(i);
        }
        if (N % 6 == 0 or N % 6 == 4) {
            for (auto x : evens) rows.push_back(x);
            for (auto x : odds) rows.push_back(x);
        } else if (N % 6 == 5 or N % 6 == 1) {
            for (auto x : odds) rows.push_back(x);
            for (auto x : evens) rows.push_back(x);
        } else {
            bool invalid = false;
            int dist_col, dist_row, row1, row2;
            for (int shift_even = 1; shift_even <= 1; shift_even++) {
                for (int shift_odd = 1; shift_odd <= 3; shift_odd++) {
                    rows.clear();
                    for (int i = 0; i < evens.size(); i++)
                        rows.push_back(evens[(i + shift_even) % evens.size()]);
                    for (int i = 0; i < odds.size(); i++)
                        rows.push_back(odds[(i + shift_odd) % odds.size()]);

                    invalid = false;
                    for (int col1 = 0; col1 < rows.size(); col1++) {
                        for (int col2 = 0; col2 < rows.size(); col2++) {
                            row1 = rows[col1];
                            row2 = rows[col2];
                            if (col1 == col2) continue;
                            if (abs(row1 - row2) == abs(col1 - col2)) {
                                invalid = true;
                                break;
                            }
                        }
                        if (invalid) break;
                    }
                    if (not invalid) break;
                }
                if (not invalid) break;
            }
            if (invalid) {
                cout << "IMPOSSIBLE" << endl;
            }
        }

        for (int i = 0; i < rows.size(); i++) {
            if (i) cout << " ";
            cout << rows[i];
        }
        cout << endl;
    }
    return 0;
}