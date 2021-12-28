# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        991.py
#  Description:     UVa Online Judge - 991
# =============================================================================
MAXN = 13

ans = [0, 1]
for i in range(2, MAXN):
    # ans[-1] = (2i - 2)! / ((i-1)! (i-1)!) / i
    # ans[i] = (2i)! / (i! i!) / (i+1)
    #        = (2i-2)! / ((i-1)!(i-1)!) * (2i-1)*(2i) / i^2 /(i+1)
    #        = ans[-1] * (2i-1)*2/(i+1)
    #        = ans[-1] * (4i-2) / (i+1)
    ans.append(ans[-1] * (4*i-2) // (i+1))

if __name__ == '__main__':
    newline = False

    while True:
        try:
            line = input()
        except:
            break

        if line == "":
            continue

        if newline:
            print("")
        newline = True

        print(ans[int(line)])