import math

def run():
    line = input()

    N = len(line)
    if int(math.sqrt(N)) ** 2 != N:
        print("INVALID")
        return

    K = int(math.sqrt(N))
    square = list(map(lambda x: line[x:x+K], range(0, N, K)))
    for c in range(K):
        for r in range(K):
            print(square[r][c], end="")
    print("")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()