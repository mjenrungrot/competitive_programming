/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12192.cc
#  Description:     UVa Online Judge - 12192
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int> > A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;

        A.clear();
        for (int i = 0; i < N; i++) {
            vector<int> tmp_vec;
            for (int j = 0; j < M; j++) {
                int tmp_val;
                cin >> tmp_val;
                tmp_vec.push_back(tmp_val);
            }
            A.push_back(tmp_vec);
        }

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            int L, R;
            cin >> L >> R;
            int ans = 0;
            for (int r = 0; r < N; r++) {
                int left_c =
                    lower_bound(A[r].begin(), A[r].end(), L) - A[r].begin();

                for (int size = ans + 1; size <= N; size++) {
                    if (left_c + size - 1 >= M) break;
                    if (r + size - 1 >= N) break;
                    if (A[r + size - 1][left_c + size - 1] > R) break;
                    ans = size;
                }
            }
            cout << ans << endl;
        }
        cout << "-" << endl;
    }

    return 0;
}