# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10541.py
#  Description:     UVa Online Judge - 10541
# =============================================================================

def solve():
    line = input()
    tokens = line.split()
    N = int(tokens[0])
    K = int(tokens[1])
    lengths = [-1] + [int(x) for x in tokens[2:]]

    dp = [[0 for _ in range(K+1)] for _ in range(N+1)]
    dp[0][0] = 1
    for n in range(N+1):
        for k in range(K+1):
            if n-1 >= 0:
                dp[n][k] += dp[n-1][k]

            if k == 1 and n-lengths[k] >= 0:
                dp[n][k] += dp[n-lengths[k]][k-1]
            elif k > 1 and n-lengths[k]-1 >= 0:
                dp[n][k] += dp[n-lengths[k]-1][k-1]

    print(dp[N][K])


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()
