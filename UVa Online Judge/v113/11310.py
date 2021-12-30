# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11310.py
#  Description:     UVa Online Judge - 11310
# =============================================================================
MAXN = 42

ans = [1, 1, 5]
for i in range(2, MAXN):
    ans.append(ans[-1] + 4 * ans[-2] + 2 * ans[-3])

def solve():
    N = int(input())
    print(ans[N])

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()