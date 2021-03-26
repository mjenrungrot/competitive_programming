while True:
    try:
        N, R = list(map(int, input().split()))
    except EOFError:
        break

    survivors = list(map(int, input().split()))
    survived = [False for i in range(N+1)]
    for survivor in survivors:
        survived[survivor] = True

    exist = False
    for i in range(1, N+1):
        if not survived[i]:
            exist = True
            print(i, end=" ")
    if not exist: print("*", end="")
    print("")