# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11547.py
#  Description:     UVa Online Judge - 11547
# =============================================================================

def run():
    n = int(input())
    n = n * 567
    n = n // 9
    n = n + 7492
    n = n * 235
    n = n // 47
    n = n - 498
    n = abs(n)
    print((n % 100) // 10)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()