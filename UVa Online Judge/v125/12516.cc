/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12516.cc
#  Description:     UVa Online Judge - 12516
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int R, C;
    while (cin >> R >> C) {
        if (R == 0 and C == 0) break;

        vector<vector<int> > occupied(R, vector<int>(C + 1));

        int P;
        cin >> P;
        for (int i = 1; i <= P; i++) {
            string pos, type;
            cin >> pos >> type;

            int row = pos[0] - 'A';
            int col = stoi(pos.erase(0, 1)) - 1 + (type == "+");
            occupied[row][col] = true;
        }

        int Z;
        cin >> Z;

        vector<string> query(Z);
        for (int i = 0; i < Z; i++) cin >> query[i];

        sort(query.begin(), query.end(), [](string x, string y) {
            if (x[0] != y[0]) return x[0] < y[0];
            return stoi(x.erase(0, 1)) < stoi(y.erase(0, 1));
        });

        bool possible = true;
        for (auto u : query) {
            int row = u[0] - 'A';
            int col = stoi(u.erase(0, 1)) - 1;

            if (not occupied[row][col]) {
                occupied[row][col] = true;
                continue;
            }

            if (not occupied[row][col + 1]) {
                occupied[row][col + 1] = true;
                continue;
            }

            possible = false;
            break;
        }

        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}