# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10523.py
#  Description:     UVa Online Judge - 10523
# =============================================================================

while True:
    try:
        line = input()
    except EOFError:
        break

    N, A = list(map(int, line.split()))
    ans = 0
    for i in range(1, N + 1):
        ans += i * (A ** i)
    print(ans)
