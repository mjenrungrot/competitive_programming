def run():
    Ns = list(map(int, input().split()))

    if Ns[0] == 0 and Ns[2] == 0:
        bit = 1
        print("0", end="")
        for _ in range(Ns[1]):
            print(bit, end="")
            bit = 1 - bit
        print("")
        return

    elif Ns[0] == 0 and Ns[1] == 0:
        print("1", end="")
        for _ in range(Ns[2]):
            print("1", end="")
        print("")
        return

    elif Ns[1] == 0 and Ns[2] == 0:
        print("0", end="")
        for _ in range(Ns[0]):
            print("0", end="")
        print("")
        return

    elif Ns[0] == 0:
        bit = 1 - (Ns[1] % 2)
        print(bit, end="")
        for _ in range(Ns[1]):
            bit = 1 - bit
            print(bit, end="")
        for _ in range(Ns[2]):
            print("1", end="")
        print("")
    elif Ns[1] == 0:
        # impossible
        raise
        return
    elif Ns[2] == 0:
        bit = (Ns[1] % 2)
        print(bit, end="")
        for _ in range(Ns[1]):
            bit = 1 - bit
            print(bit, end="")
        for _ in range(Ns[0]):
            print("0", end="")
        print("")
    else:
        if Ns[1] % 2 == 0:
            print("1", end="")
            Ns[1] -= 1

        print("0", end="")
        for _ in range(Ns[0]):
            print("0", end="")

        bit = 1
        for _ in range(Ns[1]-1):
            print(bit, end="")
            bit = 1 - bit

        print("1", end="")
        for _ in range(Ns[2]):
            print("1", end="")

        print("")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()
