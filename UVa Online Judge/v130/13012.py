# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13012.py
#  Description:     UVa Online Judge - 13012
# =============================================================================

import sys

while True:
    line = sys.stdin.readline()
    if line == "":
        break
    N = int(line)

    line = sys.stdin.readline()
    X = list(map(int, line.strip().split()))
    ans = 0
    for a in X:
        if a == N:
            ans += 1
    print(ans)
