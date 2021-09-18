# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12658.py
#  Description:     UVa Online Judge - 12658
# =============================================================================

N = int(input())
A = [input().strip() for i in range(5)]

ans = []
for i in range(N):
    if A[1][4 * i + 1] == "*":
        ans.append(1)
    elif A[3][4 * i] == "*":
        ans.append(2)
    else:
        ans.append(3)

for i in range(N):
    print(ans[i], end="")
print("")
