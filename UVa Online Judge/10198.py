dp = [0 for _ in range(1005)]
dp[0] = 1
for i in range(1, 1001):
    for k in [1, 2, 3, 1]:
        if i - k < 0: continue
        dp[i] += dp[i - k]

while True:
    try:
        N = int(input())
    except EOFError:
        break

    print(dp[N])