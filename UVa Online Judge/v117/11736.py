# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11736.py
#  Description:     UVa Online Judge - 11736
# =============================================================================

while True:
    try:
        line = input()
    except EOFError:
        break

    b, v = list(map(int, line.split()))
    variables = {}
    name = []
    length = []
    total_length = 0
    for i in range(v):
        line = input().split()
        name.append(line[0])
        variables[name[-1]] = 0
        length.append(int(line[1]))
        total_length += length[-1]

    for i in range(v):
        for j in range(length[i]):
            line = input()
            variables[name[i]] *= (1 << b)
            variables[name[i]] += int(line, base=2)
    
    q = int(input())
    for _ in range(q):
        line = input()
        if line in variables:
            print("{}={}".format(line, variables[line]))
        else:
            print("{}=".format(line))
