# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11070.py
#  Description:     UVa Online Judge - 11070
# =============================================================================
while True:
    try:
        s = input()
        print("{:.3f}".format(eval(s)))
    except EOFError:
        break
