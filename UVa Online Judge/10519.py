while True:
    try:
        N = int(input())
    except EOFError:
        break

    if N == 0: print("1")
    else: print(2 + N * (N-1))
