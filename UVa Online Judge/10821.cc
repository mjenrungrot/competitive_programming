/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10821.cc
#  Description:     UVa Online Judge - 10821
=============================================================================*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void f(int L, int R, int possible_height, vector<int> &ans) {
    if (L > R) return;
    if (L == R) {
        ans.push_back(L);
        return;
    }
    int left = L, right = R + 1, mid;
    while (left < right) {
        mid = (left + right) / 2;

        int right_side = R - mid;
        int right_min_height = 1 + (int)floor(log2((double)right_side));
        int possible = (right_min_height <= possible_height - 1);

        if (possible)
            right = mid;
        else
            left = mid + 1;
    }
    ans.push_back(left);
    f(L, left - 1, possible_height - 1, ans);
    f(left + 1, R, possible_height - 1, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, H, n_case = 0;
    while (cin >> N >> H) {
        if (N == 0 and H == 0) break;
        cout << "Case " << ++n_case << ":";

        int min_depth = 1 + (int)floor(log2((double)N));
        if (min_depth > H) {
            cout << " Impossible." << endl;
            continue;
        }

        vector<int> ans;
        f(1, N, H, ans);
        for (auto u : ans) cout << " " << u;
        cout << endl;
    }
    return 0;
}