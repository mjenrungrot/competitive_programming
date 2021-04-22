# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12459.py
#  Description:     UVa Online Judge - 12459
# =============================================================================

ans = [1, 1]
for i in range(2, 85):
    ans.append(ans[-1] + ans[-2])

while True:
    N = int(input())
    if N == 0: 
        break
    print(ans[N])