# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1226.py
#  Description:     UVa Online Judge - 1226
# =============================================================================

T = int(input())
while T > 0:
    N = int(input())
    P = int(input())
    print(P % N)
    T -= 1