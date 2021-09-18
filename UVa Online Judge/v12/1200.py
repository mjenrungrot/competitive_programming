# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1200.py
#  Description:     UVa Online Judge - 1200
# =============================================================================

import re


def process(x, A=0, B=0):
    if len(x) == 0:
        return A, B

    token = ""
    i = 0
    while i < len(x):
        if x[i] == "+":
            i += 1
            break
        elif i > 0 and x[i] == "-":
            break
        token += x[i]
        i += 1

    if token[-1] == "x":
        if token == "x":
            A += 1
        elif token == "-x":
            A -= 1
        else:
            A += eval(token[:-1])
    else:
        B += eval(token)
    # print(token, "rem = [{}]".format(x[i:]), A, B)
    return process(x[i:], A, B)


def run():
    line = input().split("=")
    lhs = process(line[0], 0, 0)
    rhs = process(line[1], 0, 0)

    if lhs[0] == rhs[0] and lhs[1] == rhs[1]:
        print("IDENTITY")
    elif lhs[0] == rhs[0] and lhs[1] != rhs[1]:
        print("IMPOSSIBLE")
    else:
        coeff = lhs[0] - rhs[0]
        target = rhs[1] - lhs[1]
        print(target // coeff)


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        run()
