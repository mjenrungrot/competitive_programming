# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        444.py
#  Description:     UVa Online Judge - 444
# =============================================================================
while True:
    try:
        line = input()
    except EOFError:
        break

    if len(line) > 0 and line[0].isdigit():
        line = line[::-1]

        idx = 0
        while idx < len(line):
            if line[idx] == "1":
                print(chr(int(line[idx : idx + 3])), end="")
                idx += 3
            else:
                print(chr(int(line[idx : idx + 2])), end="")
                idx += 2
        print("")
    else:
        line = line[::-1]
        for ch in line:
            print(str(ord(ch))[::-1], end="")
        print("")
