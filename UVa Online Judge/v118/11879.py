# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11879.py
#  Description:     UVa Online Judge - 11879
# =============================================================================

while True:
    N = int(input())
    if N == 0:
        break
    if N % 17 == 0:
        print("1")
    else:
        print("0")
