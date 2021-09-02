# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        740.py
#  Description:     UVa Online Judge - 740
# =============================================================================

down_shift = input()
up_shift = input()

while True:
    try:
        line = input()
    except EOFError:
        break

    codes = list(map(lambda x: int(line[x : x + 5], base=2), range(0, len(line), 5)))
    up_state = False

    for code in codes:
        if code == 31:
            up_state = True
            continue
        if code == 27:
            up_state = False
            continue

        if up_state:
            print(up_shift[code], end="")
        else:
            print(down_shift[code], end="")
    print("")
