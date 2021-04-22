# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11074.py
#  Description:     UVa Online Judge - 11074
# =============================================================================

case_no = 0

while True:
    S, T, N = list(map(int, input().split()))
    if S == T == N == 0: break

    case_no += 1
    print("Case {}:".format(case_no))

    for _ in range(T):
        print("*" * ((N + 1) * T + N * S))

    for i in range(N):
        base = "*" * T + "." * S
        for _ in range(S):
            print(base * N + "*" * T)
        for _ in range(T):
            print("*" * ((N + 1) * T + N * S))
    print("")