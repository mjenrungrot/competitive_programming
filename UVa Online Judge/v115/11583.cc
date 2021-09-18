/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11583.cc
#  Description:     UVa Online Judge - 11583
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int ans = 0;
        int mask = (1 << 26) - 1;
        for (int i = 1; i <= N; i++) {
            string tmp;
            cin >> tmp;

            int curr_mask = 0;
            for (int j = 0; j < tmp.length(); j++)
                curr_mask |= (1 << (tmp[j] - 'a'));

            if (mask & curr_mask) {
                mask &= curr_mask;
            } else {
                mask = curr_mask;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}