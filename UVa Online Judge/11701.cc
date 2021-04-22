/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11701.cc
#  Description:     UVa Online Judge - 11701
=============================================================================*/
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const double EPS = 1e-6;

int main() {
    string tmp;
    while (cin >> tmp) {
        if (tmp == "END") break;

        istringstream iss;
        iss.clear();
        iss.str(tmp);
        double target;
        iss >> target;

        double curr = 0.0;
        double factor = 1.0 / 3.0;
        for (int i = 0; i < 90; i++) {
            if (curr + 2.0 * factor < target) curr += 2.0 * factor;
            factor /= 3.0;
        }
        if (fabs(curr - target) < EPS)
            cout << "MEMBER" << endl;
        else
            cout << "NON-MEMBER" << endl;
    }

    return 0;
}