T = int(input())
total = 0
for i in range(T):
    L, W, D, weight = list(map(float, input().split()))

    passing = False
    if L <= 56.00 and W <= 45.00 and D <= 25.00: passing = True
    if L + W + D <= 125.00: passing = True
    if weight > 7.00: passing = False

    if passing:
        print("1")
        total += 1
    else:
        print("0")

print(total)