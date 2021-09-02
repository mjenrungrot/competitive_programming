# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        795.py
#  Description:     UVa Online Judge - 795
# =============================================================================

mapping6x6 = [
    [27, 0, 18, 1, 28, 2],
    [19, 29, 9, 30, 3, 10],
    [31, 20, 4, 11, 21, 32],
    [12, 5, 33, 22, 6, 13],
    [34, 23, 14, 35, 15, 7],
    [24, 16, 25, 8, 26, 17],
]
source = [i for i in range(36)]
target = [mapping6x6[i][j] for i in range(6) for j in range(6)]
target_inv = [None for i in range(36)]
for i in range(36):
    target_inv[target[i]] = i


def convert36(message):
    output = ""
    for i in range(36):
        output += "{}".format(message[target_inv[i]])
    return output


def convertAll(message):
    output = ""
    for i in range(0, len(message), 36):
        output += convert36(message[i : i + 36])
    return output


while True:
    try:
        line = input()
    except EOFError:
        break

    if len(line) % 36 != 0:
        line = line + " " * (36 - len(line) % 36)
    output = convertAll(line)[::-1]

    output = output.rstrip("#")
    print(output)
