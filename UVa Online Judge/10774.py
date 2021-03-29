MAXN = 30005
dp = [0 for i in range(MAXN)]
dp[1] = 0
for i in range(2, MAXN):
    dp[i] = (dp[i-1] + 2) % i

T = int(input())
for i in range(T):
    N = int(input())
    
    counter = 0
    ans = None
    while True:
        ans = dp[N] + 1
        if ans == N:
            break
        counter += 1
        N = ans
    
    print("Case {}: {} {}".format(i+1, counter, ans))
