# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11664.py
#  Description:     UVa Online Judge - 11664
# =============================================================================

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

while True:
    n, c, x, y = list(map(int, input().split()))
    if n == c == x == y == 0: break

    table = [['.' for j in range(n)] for i in range(n)]
    digit = n*n
    for rr in range(n):
        for cc in range(n):
            digit -= 1
            if (1<<digit) & c:
                table[rr][cc] = 'R'
            else:
                table[rr][cc] = 'B'

    y -= 1
    x -= 1
    di = 0
    passing = False
    while True:
        if y < 0 or y >= n or x < 0 or x >= n:
            break
        if y == x == n-1:
            passing = True
            break

        if table[y][x] == 'B':
            table[y][x] = 'R'
            di = (di + 3) % 4
            y += dy[di]
            x += dx[di]
        else:
            table[y][x] = 'B'
            di = (di + 1) % 4
            y += dy[di]
            x += dx[di]

    if passing: print("Yes")
    else: print("Kaputt!")
 


    