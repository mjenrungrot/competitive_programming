lines = []
max_length = 0

while True:
    try:
        line = input()
    except EOFError:
        break
    lines.append(line)
    max_length = max(max_length, len(line))

for i in range(max_length):
    for j in range(len(lines)-1, -1 ,-1):
        if i < len(lines[j]):  print(lines[j][i], end="")
        else: print(" ", end="")
    print("")