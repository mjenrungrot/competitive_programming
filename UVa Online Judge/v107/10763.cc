/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10763.cc
#  Description:     UVa Online Judge - 10763
=============================================================================*/
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        if (N == 0) break;

        unordered_map<string, int> M;
        stringstream buffer, inv_buffer;
        for (int i = 1; i <= N; i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;

            buffer.str("");
            buffer << tmp1 << " " << tmp2;

            inv_buffer.str("");
            inv_buffer << tmp2 << " " << tmp1;

            if (M.count(inv_buffer.str()) and M[inv_buffer.str()] > 0) {
                M[inv_buffer.str()]--;
            } else {
                if (not M.count(buffer.str())) M[buffer.str()] = 0;
                M[buffer.str()]++;
            }
        }

        bool possible = true;
        for (auto x : M) {
            if (x.second != 0) {
                possible = false;
                break;
            }
        }
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}