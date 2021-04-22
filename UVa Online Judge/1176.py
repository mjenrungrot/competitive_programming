# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1176.py
#  Description:     UVa Online Judge - 1176
# =============================================================================

MAXN = 32770
dp = [0 for i in range(MAXN)]
dp[1] = 0
for i in range(2, MAXN):
    dp[i] = (dp[i-1] + 2) % i

while True:
    try:
        N = int(input())
    except:
        break
    
    sum_payment = 0
    ans = 0
    while True:
        ans = dp[N] + 1
        if ans == N:
            sum_payment += 2*N
            break
        sum_payment += N-ans
        N = ans

    print(sum_payment)
