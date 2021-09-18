# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13130.py
#  Description:     UVa Online Judge - 13130
# =============================================================================

T = int(input())

for i in range(T):
    A = list(map(int, input().split()))

    ans = "Y"
    for i in range(len(A) - 1):
        if A[i] + 1 != A[i + 1]:
            ans = "N"
            break

    print(ans)
