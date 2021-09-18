# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        185.py
#  Description:     UVa Online Judge - 185
# =============================================================================
from itertools import permutations

symbol = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
sym_val_dict = dict(zip(symbol, values))


def toInteger(roman):
    sum = 0
    curr = 0
    while curr < len(roman):
        if curr + 1 < len(roman) and roman[curr : curr + 2] in sym_val_dict:
            sum += sym_val_dict[roman[curr : curr + 2]]
            curr += 2
        else:
            sum += sym_val_dict[roman[curr]]
            curr += 1
    return sum


while True:
    line = input()
    if line == "#":
        break

    line_split = line.split("=")
    lhs = line_split[0].split("+")
    rhs = line_split[1]

    lhs_roman = toInteger(lhs[0]) + toInteger(lhs[1])
    rhs_roman = toInteger(rhs)

    unique_chs = set()
    unique_chs.update(set(lhs[0]))
    unique_chs.update(set(lhs[1]))
    unique_chs.update(set(rhs))
    unique_chs = list(unique_chs)
    nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    checked = 0
    for perm in permutations(nums, len(unique_chs)):
        line_replaced = line
        for i, key in enumerate(unique_chs):
            line_replaced = line_replaced.replace(unique_chs[i], "{}".format(perm[i]))

        lhs, rhs = line_replaced.split("=")
        lhs1, lhs2 = lhs.split("+")
        if lhs1[0] == "0" or lhs2[0] == "0" or rhs[0] == "0":
            continue
        if int(lhs1) + int(lhs2) == int(rhs):
            checked += 1
            if checked >= 2:
                break

    if lhs_roman == rhs_roman:
        print("Correct", end="")
    else:
        print("Incorrect", end="")

    if checked == 0:
        print(" impossible")
    elif checked == 1:
        print(" valid")
    else:
        print(" ambiguous")
