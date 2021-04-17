#include <bits/stdc++.h>
using namespace std;

const int MAXN = 18;
const int MAXMASK = (1 << 18);
int A[MAXN], N;
long long dp[MAXMASK];

long long f(int mask) {
    if (mask == 0) {
        return 1;
    }

    if (dp[mask] != -1) return dp[mask];

    int killable = A[0];
    int curr_mask = ((1 << N) - 1) - mask;
    while (curr_mask) {
        int next_bit = __builtin_ctz(curr_mask & -curr_mask);
        killable |= A[next_bit + 1];
        curr_mask -= curr_mask & -curr_mask;
    }

    long long ans = 0;
    curr_mask = mask;
    while (curr_mask) {
        int next_bit = __builtin_ctz(curr_mask & -curr_mask);
        if (killable & (1 << next_bit)) {
            ans += f(mask - (1 << next_bit));
        }
        curr_mask -= curr_mask & -curr_mask;
    }

    return dp[mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while (T--) {
        cin >> N;

        for (int r = 0; r < N + 1; r++) {
            string line;
            cin >> line;

            int mask = 0;
            for (int c = 1; c <= N; c++) {
                if (line[c - 1] == '1') mask |= (1 << (c - 1));
            }
            A[r] = mask;
        }

        memset(dp, -1, sizeof(dp));
        long long ans = f((1 << N) - 1);  // N monsters to kill
        cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}