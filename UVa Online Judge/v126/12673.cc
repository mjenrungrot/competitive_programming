/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12673.cc
#  Description:     UVa Online Judge - 12673
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, G;
    while (cin >> N >> G) {
        vector<ii> A;
        for (int i = 0; i < N; i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            A.push_back(ii(tmp1, tmp2));
        }
        sort(A.begin(), A.end(), [](ii x, ii y) {
            return x.second - x.first < y.second - y.first;
        });

        int counter = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (A[i].first > A[i].second) {
                ans += 3;
                continue;
            }

            if (counter + (A[i].second - A[i].first) + 1 <= G) {
                counter += (A[i].second - A[i].first) + 1;
                ans += 3;
            } else if (counter + (A[i].second - A[i].first) <= G) {
                counter += (A[i].second - A[i].first);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}