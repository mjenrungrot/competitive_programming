# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11805.py
#  Description:     UVa Online Judge - 11805
# =============================================================================

def run():
    N, K, P = list(map(int, input().split()))
    ans = ((K+P) - 1) % N + 1
    print(ans)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case {}: ".format(i+1), end="")
        run()