# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        110.py
#  Description:     UVa Online Judge - 110
# =============================================================================
def run(N):
    vars = [chr(ord("a") + i) for i in range(N)]
    order = [chr(ord("a")) for i in range(N)]

    def f(now, N):
        space = " " * (2 * (now + 1))
        if now == N:
            print("{}writeln({})".format(space, ",".join(order[::-1])))
            return

        print(space, end="")
        for i in range(now, 0, -1):
            order[i] = order[i - 1]
        for i in range(now):
            print("if {} < {} then".format(order[i + 1], vars[now]))
            order[i] = vars[now]
            f(now + 1, N)
            order[i] = order[i + 1]
            print("{}else ".format(space), end="")

        print("")
        order[now] = vars[now]
        f(now + 1, N)

    print("program sort(input,output);")
    print("var")
    print("{} : integer;".format(",".join(vars)))
    print("begin")
    print("  readln({});".format(",".join(vars)))

    f(1, N)

    print("end.")


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        if i:
            print("")
        _ = input()
        N = int(input())
        run(N)
