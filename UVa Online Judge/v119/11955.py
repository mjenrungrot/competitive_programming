# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11955.py
#  Description:     UVa Online Judge - 11955
# =============================================================================
MAXN = 52

nCr = [[0 for _ in range(MAXN)] for _ in range(MAXN)]
nCr[0][0] = 1
for n in range(MAXN):
    for k in range(n+1):
        if n-1 >= 0 and k-1 >= 0:
            nCr[n][k] += nCr[n-1][k-1]
        if n-1 >= 0:
            nCr[n][k] += nCr[n-1][k]


def solve():
    line = input().split('^')
    power = int(line[1])
    base = line[0].lstrip('(').rstrip(')')
    L, R = base.split('+')

    for k in range(power+1):
        if(k > 0):
            print("+", end="")

        coeff = nCr[power][k]
        if coeff > 1:
            print(f"{coeff}*", end="")
        if power-k > 0:
            if power - k > 1:
                print(f"{L}^{power-k}", end="")
            else:
                print(L, end="")

        if power-k > 0 and k > 0:
            print("*", end="")

        if k > 0:
            if k > 1:
                print(f"{R}^{k}", end="")
            else:
                print(R, end="")
    print("")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print(f"Case {i+1}: ", end="")
        solve()