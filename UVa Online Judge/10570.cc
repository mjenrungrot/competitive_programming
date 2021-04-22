/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10570.cc
#  Description:     UVa Online Judge - 10570
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int N;
int A[505], target[505], pos[505], pos_target[505];

int count() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        pos[A[i]] = i;
        pos_target[target[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        if (A[i] == target[i]) continue;
        int tmp = target[i], curr = i;
        while (true) {
            target[curr] = A[curr];
            curr = pos_target[A[curr]];
            if (curr == i) break;
            ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    while (cin >> N) {
        if (not N) break;

        for (int i = 1; i <= N; i++) cin >> A[i];
        int ans = 1e9 + 7;

        for (int base = 1; base <= N; base++) {
            int curr = base;
            for (int j = 1; j <= N; j++) {
                target[j] = curr;
                curr = (curr == N) ? 1 : curr + 1;
            }
            ans = min(ans, count());
            curr = base;
            for (int j = 1; j <= N; j++) {
                target[j] = curr;
                curr = (curr == 1) ? N : curr - 1;
            }
            ans = min(ans, count());
        }
        cout << ans << endl;
    }
    return 0;
}