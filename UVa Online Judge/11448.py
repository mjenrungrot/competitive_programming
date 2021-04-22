# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11448.py
#  Description:     UVa Online Judge - 11448
# =============================================================================

T = int(input())

while T > 0:
    T -= 1
    A, B = list(map(int, input().split()))
    print(A-B)