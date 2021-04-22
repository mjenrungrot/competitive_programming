# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10700.py
#  Description:     UVa Online Judge - 10700
# =============================================================================

import functools
import operator

T = int(input())

for _ in range(T):
    S = input()

    # find max: do plus first, then do multiply
    max_val = functools.reduce(operator.mul, list(map(eval, S.split('*'))))

    # find min: do multiply first, then do plus
    min_val = functools.reduce(operator.add, list(map(eval, S.split('+'))))

    print("The maximum and minimum are {} and {}.".format(max_val, min_val))