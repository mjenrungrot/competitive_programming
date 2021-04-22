# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11482.py
#  Description:     UVa Online Judge - 11482
# =============================================================================

case_no = 0

while True:
    M, N = list(map(int, input().split()))
    if M == N == 0: break

    case_no += 1
    print("Triangular Museum {}".format(case_no))

    for lv in range(1, N+1):
        for k in range(1, M+1):
            space = ' ' * (M * (N - lv) + (M - k))
            if k < M:
                print(space, end="")
                for i in range(lv):
                    if i: print("{}".format(' ' * 2 * (M-k)), end="")
                    print("/{}\\".format(' ' * 2*(k - 1)), end="")
                print("")
            else:
                print(space, end="")
                for i in range(lv):
                    print("/{}\\".format('_' * 2*(k - 1)), end="")
                print("")


    print("")