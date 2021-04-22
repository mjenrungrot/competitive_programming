/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11300.cc
#  Description:     UVa Online Judge - 11300
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> nums;

int main() {
    long long x;
    while (scanf("%d", &N) == 1) {
        if (N == 0) {
            printf("0\n");
            continue;
        }

        long long sum = 0;

        nums.clear();
        nums.reserve(N);
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &x);
            nums.push_back(x);
            sum += x;
        }
        long long M = sum / (long long)N;

        long long curr = 0;
        vector<long long> c;
        c.reserve(N);
        c.push_back(0);                    // case n->1
        for (int i = 0; i < N - 1; i++) {  // case i+1->i+2
            curr += nums[i] - M;
            c.push_back(curr);
        }

        int n_median = N / 2;
        nth_element(c.begin(), c.begin() + n_median, c.end());
        long long median = c[n_median];

        long long ans = 0;
        for (int i = 0; i < N; i++) ans += llabs(median - c[i]);
        printf("%lld\n", ans);
    }
    return 0;
}