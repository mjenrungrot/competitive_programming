# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12952.py
#  Description:     UVa Online Judge - 12952
# =============================================================================

import sys

while True:
    line = sys.stdin.readline()

    if line == "": break

    A, B = list(map(int, line.strip().split()))

    if A == B: print(A)
    else: print(max(A, B))