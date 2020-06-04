def run():
    N = int(input())
    A = list(map(int, input().split()))
    mile = sum(list(map(lambda x: (x + 30) // 30 * 10, A)))
    juice = sum(list(map(lambda x: (x + 60) // 60 * 15, A)))
    if mile < juice:
        print(" Mile {}".format(mile))
    elif juice < mile:
        print(" Juice {}".format(juice))
    else:
        print(" Mile Juice {}".format(mile))

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case {}:".format(i+1), end="")
        run()