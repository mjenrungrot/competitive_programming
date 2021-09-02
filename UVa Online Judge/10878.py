# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10878.py
#  Description:     UVa Online Judge - 10878
# =============================================================================

lines = []
while True:
    try:
        line = input()
    except EOFError:
        break
    lines.append(line)

embeddings = list(map(lambda x: list(x[1:6] + x[7:10]), lines[1:-1]))
embeddings_bin = [
    "".join(list(map(lambda x: "1" if x == "o" else "0", embedding)))
    for embedding in embeddings
]
embeddings_ord = list(map(lambda x: int(x, base=2), embeddings_bin))
output = "".join(list(map(chr, embeddings_ord)))
print(output.strip())
