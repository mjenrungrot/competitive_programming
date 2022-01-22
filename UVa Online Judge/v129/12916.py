# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12916.py
#  Description:     UVa Online Judge - 12916
# =============================================================================
N = int(input())

for _ in range(N):
    S = input()

    lim = len(S) // 2
    found = False
    for k in range(1, lim+1):
        if len(S) % k != 0:
            continue

        prefix = S[:k]
        if prefix * (len(S) // k) == S:
            print(k)
            found = True
            break
    
    if not found:
        print(len(S))