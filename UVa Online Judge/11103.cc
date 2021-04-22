/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11103.cc
#  Description:     UVa Online Judge - 11103
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    while (cin >> S) {
        if (S == "0") break;

        vector<char> operands, operators, not_operators;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'p' or S[i] == 'q' or S[i] == 'r' or S[i] == 's' or
                S[i] == 't') {
                operands.push_back(S[i]);
            } else if (S[i] == 'K' or S[i] == 'A' or S[i] == 'C' or
                       S[i] == 'E') {
                operators.push_back(S[i]);
            } else if (S[i] == 'N') {
                not_operators.push_back(S[i]);
            }
        }

        if (operands.size() == 0) {
            cout << "no WFF possible" << endl;
        } else {
            int n_operands = min(operands.size(), operators.size() + 1);
            int n_operators = min(operands.size() - 1, operators.size());

            for (int i = 0; i < not_operators.size(); i++)
                cout << not_operators[i];
            for (int i = 0; i < n_operators; i++) cout << operators[i];
            for (int i = 0; i < n_operands; i++) cout << operands[i];
            cout << endl;
        }
    }
    return 0;
}