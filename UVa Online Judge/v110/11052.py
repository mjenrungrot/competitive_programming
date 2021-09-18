# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11052.py
#  Description:     UVa Online Judge - 11052
# =============================================================================

while True:
    N = int(input())
    if N == 0:
        break

    A = []
    year = []
    dp = []
    for i in range(N):
        tt, num, keep = input().split()
        time_tuple = list(map(int, tt.split(":")))
        A.append((time_tuple, keep))
        year.append(-1)
        dp.append(-1)

    year[-1] = 0
    for i in range(N - 2, -1, -1):
        next_t = A[i + 1][0]
        curr_t = A[i][0]
        if curr_t < next_t:
            year[i] = year[i + 1]
        else:
            year[i] = year[i + 1] - 1

    # initialization
    last = -1
    earliest = -1
    for i in range(N - 1, -1, -1):
        if last == -1 and year[i] == 0:
            dp[i] = 1
        else:
            dp[i] = N - i

        if last == -1 and (A[i][1] == "+" or year[i] != 0):
            last = i
        if A[i][1] == "+":
            earliest = i

    for i in range(last, earliest - 1, -1):
        for j in range(i + 1, N):
            if year[i] == year[j]:
                dp[i] = min(dp[i], dp[j] + 1)
            elif A[i][0] >= A[j][0] and year[i] + 1 == year[j]:
                dp[i] = min(dp[i], dp[j] + 1)
            else:
                break
            if A[j][1] == "+":
                break
    print(dp[earliest])
