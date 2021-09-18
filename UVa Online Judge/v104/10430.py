# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10430.py
#  Description:     UVa Online Judge - 10430
# =============================================================================

nt = 0
print("Dear GOD, Pardon Me")
while True:
    try:
        T, N = list(map(int, input().split()))
    except EOFError:
        break

    if nt:
        print("")
    nt += 1

    X = 1
    K = T
    for i in range(N - 1):
        X += K
        K *= T
    print("X = {}".format(X))
    print("K = {}".format(K))
