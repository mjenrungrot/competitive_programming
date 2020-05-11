def run():
    n, k = list(map(int, input().split()))

    if n % 2 == 0:
        if n >= k and k % 2 == 0: # 1 + 1 + ... + 1 + (n-k+1)
            print("YES")
            print("{}".format(n - k + 1), end="")
            for i in range(k-1):
                print(" 1", end="")
            print("")
        elif 2*k <= n: # 2 + 2 + ... + 2 + (n-2k+2)
            print("YES")
            print("{}".format(n - 2*k + 2), end="")
            for i in range(k-1):
                print(" 2", end="")
            print("")
        else:
            print("NO")
    else:
        if k%2 == 0:
            print("NO")
        elif k > n:
            print("NO")
        else:
            print("YES")
            print("{}".format(n - k + 1), end="")
            for i in range(k-1):
                print(" 1", end="")
            print("")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()