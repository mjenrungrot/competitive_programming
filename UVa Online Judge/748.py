# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        748.py
#  Description:     UVa Online Judge - 748
# =============================================================================

while True:
    try:
        line = input()
    except EOFError:
        break

    line = line.split()
    n_fractions = 0
    found = False
    for i in range(len(line[0]) - 1, -1, -1):
        if line[0][i] == ".":
            break
        # if line[0][i] != '0': found = True
        # elif not found: continue
        n_fractions += 1

    r = int(line[0].replace(".", ""))
    n = int(line[1])
    output = str(r ** n)
    n_fractions *= n

    if len(output) < n_fractions:
        diff = n_fractions - len(output)
        print(".{}{}".format("0" * diff, output.rstrip("0")))
    else:
        print("{}.{}".format(output[:-n_fractions], output[-n_fractions:].rstrip("0")))
