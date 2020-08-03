def run():
    D, M, Y, QY = list(map(int, input().split()))

    if D == 29 and M == 2:
        ny = Y // 4 - Y // 100 + Y // 400
        nqy = QY // 4 - QY // 100 + QY // 400
        print(nqy - ny)
    else:
        print(QY - Y)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case {}: ".format(i+1), end="")
        run()