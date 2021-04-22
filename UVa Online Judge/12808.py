# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12808.py
#  Description:     UVa Online Judge - 12808
# =============================================================================

import math

def run():
    line = input()
    L, D, H, V = list(map(float, line.split()))
    t = math.sqrt(2.0 * (H / 1000.0) / 9.81)
    x = (V / 1000.0) * t

    if x < D/1000.0 - 0.5 or x > (D+L) / 1000.0 + 0.5:
        print("FLOOR")
    elif x <= D/1000.0 + 0.5 or x >= (D+L) / 1000.0 - 0.5:
        print("EDGE")
    else:
        print("POOL")


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()