# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10083.py
#  Description:     UVa Online Judge - 10083
# =============================================================================

import math

while True:
    try:
        t, a, b = list(map(int, input().split()))
    except EOFError:
        break

    exp = "({}^{}-1)/({}^{}-1)".format(t, a, t, b)    
    if t == 1:
        print("{} is not an integer with less than 100 digits.".format(exp))
        continue
    if a == b:
        print("{} 1".format(exp))
        continue
    if a % b != 0:
        print("{} is not an integer with less than 100 digits.".format(exp))
        continue

    n_digits = int((a-b) * math.log10(t))
    if n_digits > 99:
        print("{} is not an integer with less than 100 digits.".format(exp))
        continue

    num = t**a - 1
    denom = t**b - 1
    result = num // denom
    if int(math.floor(math.log10(result))) + 1 >= 100:
        print("{} is not an integer with less than 100 digits.".format(exp))
        continue
    else:
        print("{} {}".format(exp, result))