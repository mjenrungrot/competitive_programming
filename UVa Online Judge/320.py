# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        320.py
#  Description:     UVa Online Judge - 320
# =============================================================================
def run():
    x, y = list(map(int, input().split()))
    moves = input()

    boards = [list('.' * 32) for _ in range(32)]
    for i in range(len(moves)):
        move = moves[i]
        if move == '.': break

        if move == 'E':
            if y-1 >= 0: boards[y-1][x] = 'X'
            x += 1
        elif move == 'W':
            if x-1 >= 0: boards[y][x-1] = 'X'
            x -= 1
        elif move == 'N':
            boards[y][x] = 'X'
            y += 1
        else:
            if y-1 >= 0 and x-1 >= 0: boards[y-1][x-1] = 'X'
            y -= 1

    for i in range(31, -1, -1):
        print(''.join(boards[i]))

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Bitmap #{}".format(i+1))
        run()
        print("")