/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13031.cc
#  Description:     UVa Online Judge - 13031
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<ii> A;
        for (int i = 1; i <= N; i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            A.push_back(ii(tmp1, tmp2));
        }
        sort(A.begin(), A.end(),
             [](ii x, ii y) { return x.second > y.second; });

        long long ans = -1, curr_sum = 0;
        for (auto x : A) {
            curr_sum += (long long)x.first;
            ans = max(ans, curr_sum * (long long)x.second);
        }
        cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}