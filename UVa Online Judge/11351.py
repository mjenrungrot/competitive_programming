def run():
    N, K = list(map(int, input().split()))

    dp = [0 for _ in range(N+1)]
    dp[1] = 0
    for i in range(2, N+1):
        dp[i] = (dp[i-1] + K) % i
    
    return dp[N]+1

T = int(input())

for i in range(T):
    res = run()
    print("Case {}: {}".format(i+1, res))