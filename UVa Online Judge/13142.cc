/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13142.cc
#  Description:     UVa Online Judge - 13142
=============================================================================*/
#include <cmath>
#include <iostream>
using namespace std;

const double N_SECONDS_PER_DAY = 60.0 * 60.0 * 24.0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        double time_to_impact, speed, distance;
        cin >> time_to_impact >> speed >> distance;

        double to_add = -distance / (time_to_impact * N_SECONDS_PER_DAY) * 1e9 /
                        1e3;  // mm / s
        int to_add_integer = (int)fabs(to_add);
        if (distance > 0 and to_add_integer > 0) {
            cout << "Remove " << to_add_integer << " tons" << endl;
        } else {
            cout << "Add " << to_add_integer << " tons" << endl;
        }
    }
    return 0;
}