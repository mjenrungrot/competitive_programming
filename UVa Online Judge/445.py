# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        445.py
#  Description:     UVa Online Judge - 445
# =============================================================================
while True:
    try:
        line = input()
    except EOFError:
        break

    num = 0
    for ch in line:
        if ord('0') <= ord(ch) <= ord('9'):
            num += ord(ch) - ord('0')
        elif ord('A') <= ord(ch) <= ord('Z'):
            print("{}".format(ch) * num, end="")
            num = 0
        elif ch == 'b':
            print(" " * num, end="")
            num = 0
        elif ch == '*':
            print("*" * num, end="")
            num = 0
        elif ch == '!':
            print("")
    print("")