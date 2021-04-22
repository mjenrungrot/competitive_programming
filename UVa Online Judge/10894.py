# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10894.py
#  Description:     UVa Online Judge - 10894
# =============================================================================

text = """*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*
*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.
*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..
....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..
*****.*...*...*...*****...*...*.*..**.*****.***...*****...*.."""
rows = text.split()

start = [0, 5, 6, 11, 12, 17, 18, 23, 26, 31, 32, 37, 38, 43, 44, 49, 50, 55, 56]
length = [5, 1, 5, 1, 5,   1,  5,  3, 5,  1, 5, 1,     5,  1,  5,  1, 5,   1,  5]
cols = []
for i in range(len(start)):
    for k in range(5):
        cols.append(rows[k][start[i]:start[i]+length[i]])
cols = ''.join(cols)
cols = [cols[i:i+5] for i in range(0, len(cols), 5)]

while True:
    N = int(input())
    if N == 0: break

    if N < 0:
        L = -N
        for i in range(len(cols) * L):
            r = i // L
            for j in range(len(cols[r]) * L):
                c = j // L
                print(cols[r][c], end="")
            print("")
    else:
        L = N

        for i in range(len(rows) * L):
            r = i // L
            for j in range(len(rows[r]) * L):
                c = j // L
                print(rows[r][c], end="")
            print("")

    print("\n")