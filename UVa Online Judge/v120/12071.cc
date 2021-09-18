/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12071.cc
#  Description:     UVa Online Judge - 12071
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int N, nt;
vector<int> nums;

int main() {
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        nums.clear();

        int tmp;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &tmp);
            nums.push_back(tmp);
        }

        int ans = N * (N - 1) / 2;
        sort(nums.begin(), nums.end());

        int curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                curr++;
            } else {
                ans -= curr * (curr - 1) / 2;
                curr = 1;
            }
        }
        ans -= curr * (curr - 1) / 2;

        printf("Case %d: %d\n", ++nt, ans);
    }
    return 0;
}