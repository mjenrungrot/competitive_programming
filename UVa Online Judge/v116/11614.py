# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11614.py
#  Description:     UVa Online Judge - 11614
# =============================================================================

import math

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        # find greatest integer k s.t. k(k+1)/2 <= n
        k = -0.5 + math.sqrt(0.5 * 0.5 + 4 * 0.5 * n)
        print(int(math.floor(k)))
