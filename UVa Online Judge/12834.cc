/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12834.cc
#  Description:     UVa Online Judge - 12834
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
        int N, K;
        cin >> N >> K;

        vector<ii> A(N);
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            A[i] = ii(tmp, 0);
        }
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            A[i] = ii(A[i].first, tmp);
        }
        sort(A.begin(), A.end(), [](ii x, ii y) {
            return x.second - x.first < y.second - y.first;
        });

        long long ans = 0, n_skip = 0;
        for (int i = 0; i < N; i++) {
            if (n_skip < K and A[i].second < A[i].first) {
                n_skip++;
            } else {
                ans += A[i].second - A[i].first;
            }
        }
        if (ans <= 0)
            cout << "Case " << ++n_case << ": No Profit" << endl;
        else
            cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}