# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        902.py
#  Description:     UVa Online Judge - 902
# =============================================================================

def reader():
    while True:
        line = input().split()
        for x in line:
            yield x


gen = reader()
while True:
    try:
        N = next(gen)
        line = next(gen)
    except EOFError:
        break
    
    N = int(N)
    length = len(line)

    memory = {}
    for i in range(length):
        j = i + N
        if j > length: break
        if line[i:j] not in memory:
            memory[line[i:j]] = 0

        memory[line[i:j]] += 1

    best_key = -1
    best_key_val = 0
    for key in memory:
        if memory[key] > best_key_val:
            best_key_val = memory[key]
            best_key = key
    print(best_key)