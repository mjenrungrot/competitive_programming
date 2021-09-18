# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10906.py
#  Description:     UVa Online Judge - 10906
# =============================================================================


def f(exp, vars, right=False, precedence=0):
    if "+" in exp:
        lhs, rhs = exp.split("+")
        if (right and precedence == 1) or (precedence == 2):
            print("(", end="")
        f(lhs, vars, right=False, precedence=1)
        print("+", end="")
        f(rhs, vars, right=True, precedence=1)
        if (right and precedence == 1) or (precedence == 2):
            print(")", end="")
    elif "*" in exp:
        lhs, rhs = exp.split("*")
        if right and precedence == 2:
            print("(", end="")
        f(lhs, vars, right=False, precedence=2)
        print("*", end="")
        f(rhs, vars, right=True, precedence=2)
        if right and precedence == 2:
            print(")", end="")
    elif exp in vars:
        tmp = vars[exp]
        f(tmp, vars, right, precedence)
    else:
        print("{}".format(exp), end="")


def run():
    N = int(input())

    vars = {}
    for i in range(N - 1):
        var, exp = input().replace(" ", "").split("=")
        vars[var] = exp

    var, exp = input().replace(" ", "").split("=")
    f(exp, vars)
    print("")


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        print("Expression #{}: ".format(i + 1), end="")
        run()
