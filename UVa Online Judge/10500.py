def f(boards, x, y, nn):
    boards[y][x] = '*0'
    
    for (dy, dx) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
        newy = y + dy
        newx = x + dx
        if newy < 0 or newy >= len(boards): continue
        if newx < 0 or newx >= len(boards[y]): continue
        boards[newy][newx] = '{}*'.format(boards[newy][newx])

    for (dy, dx) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
        newy = y + dy
        newx = x + dx
        if newy < 0 or newy >= len(boards): continue
        if newx < 0 or newx >= len(boards[y]): continue
        if boards[newy][newx][0] == '*': continue
        if '0' in boards[newy][newx]:
            nn[0] += 1
            f(boards, newx, newy, nn)
            return 

while True:
    N, M = list(map(int, input().split()))
    if N == M == 0: break
    y0, x0 = list(map(int, input().split()))
    x0 -= 1
    y0 -= 1

    boards = []
    for i in range(N):
        boards.append(input().split())

    n_movements = [0]
    f(boards, x0, y0, n_movements)
    
    print("")
    print("---".join(list("|" * (M + 1))))
    for i in range(N):
        print("|", end="")
        for j in range(M):
            val = boards[i][j]
            if "*" not in val: val = "?"
            else: val = val.replace('*', '')
            print(" {} |".format(val), end="")
        print("")
        print("---".join(list("|" * (M + 1))))
    print("")
    print("NUMBER OF MOVEMENTS: {}".format(n_movements[0]))