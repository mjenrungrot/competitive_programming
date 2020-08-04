import math

def run():
    L, R = list(map(int, input().split()))

    if L < R:
        swap = True
        L, R = R, L
    else:
        swap = False

    assert(L >= R)

    # phase 1
    l = 1
    r = int(1e18 + 1)
    while(l < r):
        m = (l+r) // 2
        sum_m = m*(m+1) // 2
        if(L >= sum_m and L - sum_m >= R): l = m + 1
        else: r = m
    n = l - 1
    L -= n*(n+1) // 2
    # print(n, L, R, swap)

    if(L >= R):
        if L == R: swap = False
        if L >= n+1:
            L -= n+1
            n += 1
        else:
            if swap: print(" {} {} {}".format(n, R, L))
            else: print(" {} {} {}".format(n, L, R))
            return

    assert(L < R)
    # print(n, L, R, swap)

    # phase 2
    l = n+1
    r = int(1e18+1)
    while(l < r):
        m = (l+r) // 2
        n_L = (m - n) // 2
        n_R = (m - n) - n_L
        sum_R = n_R * ((n+1) + (n+2*n_R-1)) // 2
        sum_L = n_L * ((n+2) + (n+2*n_L)) // 2
        if(L >= sum_L and R >= sum_R): l = m+1
        else: r = m

    m = l - 1
    n_L = (m - n) // 2
    n_R = (m - n) - n_L
    sum_R = n_R * ((n+1) + (n+2*n_R-1)) // 2
    sum_L = n_L * ((n+2) + (n+2*n_L)) // 2
    L -= sum_L
    R -= sum_R
    n = m
    # print(n, L, R)

    if swap:
        print(" {} {} {}".format(n, R, L))
    else:
        print(" {} {} {}".format(n, L, R))
    

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case #{}:".format(i+1), end='')
        run()