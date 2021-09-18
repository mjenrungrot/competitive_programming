/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10664.cc
#  Description:     UVa Online Judge - 10664
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAXLIMIT = 205;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);
    while (T--) {
        getline(cin, line);

        int total_sum = 0;
        vector<bool> reachable(MAXLIMIT);
        reachable[0] = true;

        string token;
        istringstream iss(line);
        while (getline(iss, token, ' ')) {
            int num = stoi(token);
            total_sum += num;
            for (int j = MAXLIMIT - 1; j >= 0; j--) {
                if (not reachable[j]) continue;
                if (j + num < MAXLIMIT) reachable[j + num] = true;
            }
        }

        if (total_sum % 2 == 0 and reachable[total_sum / 2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}