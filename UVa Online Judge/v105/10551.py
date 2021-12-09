# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10551.py
#  Description:     UVa Online Judge - 10551
# =============================================================================

while True:
    line = input().split()

    if int(line[0]) == 0:
        break

    b = int(line[0])
    p = int(line[1], b)
    m = int(line[2], b)

    rem = p % m
    ans = ""
    while True:
        ans += chr((rem % b) + ord('0'))
        rem //= b
        if rem == 0: break
    
    print(ans[::-1])
