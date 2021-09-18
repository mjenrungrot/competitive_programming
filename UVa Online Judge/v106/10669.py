# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10669.py
#  Description:     UVa Online Judge - 10669
# =============================================================================

while True:
    N = int(input())
    if N == 0:
        break

    N -= 1
    binary = bin(N)[2:]
    outputs = []
    for i in range(len(binary)):
        if binary[i] == "0":
            continue
        expo = len(binary) - i - 1
        outputs.append(str(3 ** expo))
    print("{", ", ".join(outputs[::-1]), "}")
