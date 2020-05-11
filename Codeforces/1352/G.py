def run():
    N = int(input())

    if N == 2 or N == 3:
        print("-1")
        return

    space = False
    while N >= 5:
        if N - 5 == 2 or N - 5 == 3:
            break
        if space: print(" ", end="")
        space = True
        print("{} {} {} {} {}".format(N, N-3, N-1, N-4, N-2), end="")
        N -= 5

    if N == 0:
        print("")
    elif N == 1: # pre N = 3
        if space: print(" ", end="")
        space = True
        print("1")
    elif N == 2:
        pass
    elif N == 3:
        pass
    elif N == 4:
        if space: print(" ", end="")
        space = True
        print("3 1 4 2")
    elif N == 7:
        if space: print(" ", end="")
        space = True
        print("7 4 2 6 3 1 5")
    elif N == 8:
        if space: print(" ", end="")
        space = True
        print("8 5 7 3 1 4 6 2")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()