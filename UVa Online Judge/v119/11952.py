# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11952.py
#  Description:     UVa Online Judge - 11952
# =============================================================================

def conv(num, base):
    ans = 0
    for ch in num:
        ans *= base
        if base >= 2 and ord(ch) - ord('0') >= base:
            raise ValueError
        elif base == 1 and ch != '1':
            raise ValueError
        ans += ord(ch) - ord('0')
    return ans

T = int(input())

for _ in range(T):
    tokens = input().split()
    num1 = tokens[0]
    num2 = tokens[2]
    num3 = tokens[4]

    found = False
    for b in range(1, 19):
        try:
            num1_b = conv(num1, b)
            num2_b = conv(num2, b)
            num3_b = conv(num3, b)
        except:
            continue

        if num1_b + num2_b == num3_b:
            print(b)
            found = True
            break

    if not found:
        print(0)
