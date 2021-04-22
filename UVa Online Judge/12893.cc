/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12893.cc
#  Description:     UVa Online Judge - 12893
=============================================================================*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        cout << __builtin_popcountll(N) << endl;
    }
    return 0;
}