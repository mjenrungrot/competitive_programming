# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11744.py
#  Description:     UVa Online Judge - 11744
# =============================================================================

def run():
    a, b = input().split()
    a = int(a, base=2)
    b = int(b, base=2)

    print("{:031b} {:031b}".format(a, b))
    while True:
        c = a ^ b
        d = a & b

        a = c
        b = (d << 1)
        if b == 0:
            print("{:031b} {:031b}".format(a, b))
            break
        elif b >= (1 << 31):
            print("{:031b} overflow".format(a))
            break
        else:
            print("{:031b} {:031b}".format(a, b))


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        if i: print("")
        run()
