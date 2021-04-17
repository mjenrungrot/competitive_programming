#include <bits/stdc++.h>
using namespace std;

const int MAXN = 70;
const int MAXK = 70;
unsigned long long memo[MAXN][MAXK];

unsigned long long f(int N, int K) {
    if (N <= 0) return 1;
    if (N == 1) return 1;
    if (memo[N][K] != -1) return memo[N][K];

    unsigned long long ans = 1;
    for (int i = 1; i <= K; i++) {
        ans += f(N - i, K);
    }
    return memo[N][K] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    int N, K, n_case = 0;
    while (cin >> N >> K) {
        if (N > 60) break;
        cout << "Case " << ++n_case << ": " << f(N, K) << endl;
    }
    return 0;
}