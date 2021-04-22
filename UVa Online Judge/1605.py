# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1605.py
#  Description:     UVa Online Judge - 1605
# =============================================================================

newline = False
characters = [chr(ord('A') + i) for i in range(26)] + [chr(ord('a') + i) for i in range(26)]

while True:
    try:
        N = int(input())
    except EOFError:
        break
    
    if newline: print("")
    newline = True


    h = N
    l = 3
    w = 3 * N

    print("{} {} {}".format(h, w, l))
    for i in range(h):
        if i: print("")

        base = characters[i]

        print("{}".format(base) * w)
        print(''.join(list(map(lambda x: "{}{}{}".format(base, characters[x], base), range(h)))))
        print("{}".format(base) * w)