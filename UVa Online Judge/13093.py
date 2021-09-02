# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13093.py
#  Description:     UVa Online Judge - 13093
# =============================================================================

while True:
    try:
        line1 = input().split()
        line2 = input().split()
    except EOFError:
        break

    acronym1 = "".join(list(map(lambda x: x[0], line1)))
    acronym2 = "".join(list(map(lambda x: x[0], line2)))

    if acronym1 == acronym2:
        print("yes")
    else:
        print("no")
