# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12930.py
#  Description:     UVa Online Judge - 12930
# =============================================================================

nt = 0
while True:
    try:
        line = input()
    except EOFError:
        break

    nt += 1
    line = line.split()
    n_frac1 = len(line[0]) - line[0].find(".") - 1
    n_frac2 = len(line[1]) - line[1].find(".") - 1

    if n_frac1 < max(n_frac1, n_frac2):
        line[0] += "0" * (max(n_frac1, n_frac2) - n_frac1)
    if n_frac2 < max(n_frac1, n_frac2):
        line[1] += "0" * (max(n_frac1, n_frac2) - n_frac2)

    a = int(line[0].replace(".", ""))
    b = int(line[1].replace(".", ""))

    if a < b:
        print("Case {}: Smaller".format(nt))
    elif a > b:
        print("Case {}: Bigger".format(nt))
    else:
        print("Case {}: Same".format(nt))
