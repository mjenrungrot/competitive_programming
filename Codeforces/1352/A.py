def run():
    n = int(input())

    outputs = []
    base = int(1)
    while n > 0:
        if n % 10 > 0:
            outputs.append(base * (n % 10))
        n = n // 10
        base *= 10

    print(len(outputs))
    for i in range(len(outputs)):
        if i: print(" ", end="")
        print(outputs[i], end="")
    print("")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()