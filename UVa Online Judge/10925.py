# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10925.py
#  Description:     UVa Online Judge - 10925
# =============================================================================

nt = 0
while True:
    N, F = list(map(int, input().split()))
    if N == F == 0:
        break

    total = 0
    for i in range(N):
        total += int(input())

    nt += 1
    print(
        "Bill #{} costs {}: each friend should pay {}\n".format(nt, total, total // F)
    )
