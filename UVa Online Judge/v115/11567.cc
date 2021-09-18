/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11567.cc
#  Description:     UVa Online Judge - 11567
=============================================================================*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long S;
    while (cin >> S) {
        int ans = 0;
        while (S > 0) {
            // base case
            if (S <= 3) {
                ans += S;
                S = 0;
                break;
            }

            if (S & 1LL) {
                if ((S + 1LL) / 2LL % 2LL == 0) {
                    S++;
                } else {
                    S--;
                }
            } else {
                S /= 2LL;
            }
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}