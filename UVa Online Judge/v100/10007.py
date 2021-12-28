# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        991.py
#  Description:     UVa Online Judge - 991
# =============================================================================
MAXN = 303

cat = [0, 1]
fact = [1, 1]
for i in range(2, MAXN):
    # ans[-1] = (2i - 2)! / ((i-1)! (i-1)!) / i
    # ans[i] = (2i)! / (i! i!) / (i+1)
    #        = (2i-2)! / ((i-1)!(i-1)!) * (2i-1)*(2i) / i^2 /(i+1)
    #        = ans[-1] * (2i-1)*2/(i+1)
    #        = ans[-1] * (4i-2) / (i+1)
    cat.append(cat[-1] * (4*i-2) // (i+1))
    fact.append(fact[-1] * i)

if __name__ == '__main__':
    while True:
        line = input()
        N = int(line)
        if N == 0:
            break
        print(cat[N] * fact[N])