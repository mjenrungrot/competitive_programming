# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10494.py
#  Description:     UVa Online Judge - 10494
# =============================================================================

while True:
    try:
        line = input()
    except EOFError:
        break

    if '/' in line:
        a,b  = list(map(int, line.split('/')))
        print(a // b)
    else:
        a,b  = list(map(int, line.split('%')))
        print(a % b)
