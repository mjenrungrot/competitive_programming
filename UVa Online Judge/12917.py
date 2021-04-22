# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12917.py
#  Description:     UVa Online Judge - 12917
# =============================================================================

import sys

lines = sys.stdin.readlines()
for line in lines:
    line = line.strip()
    P, H, O = list(map(int, line.split()))

    spares = O - P
    if H > spares: print("Hunters win!")
    else: print("Props win!")