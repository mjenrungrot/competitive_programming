T = int(input())

for i in range(T):
    if i: print("")

    a, b = input().split()
    a = int(a, 2)
    b = int(b, 2)

    print('{:031b} {:031b}'.format(a, b))
    for k in range(5):
        c = a ^ b
        d = a & b
        a = c
        if (d << 1) >= (1 << 31):
            print("{:031b} overflow".format(a))
            break
        b = (d << 1) % (1 << 31)
        print('{:031b} {:031b}'.format(a, b))
        if b == 0:
            break