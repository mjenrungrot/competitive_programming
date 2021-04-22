# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1339.py
#  Description:     UVa Online Judge - 1339
# =============================================================================

while True:
    try: 
        line1 = input()
    except EOFError:
        break

    line2 = input()

    count1 = [0 for i in range(26)]
    count2 = [0 for i in range(26)]

    for i in range(len(line1)):
        count1[ord(line1[i]) - ord('A')] += 1
        count2[ord(line2[i]) - ord('A')] += 1

    checked = True
    count1.sort()
    count2.sort()
    for i in range(26):
        if count1[i] != count2[i]:
            checked = False
            break

    if checked: print("YES")
    else: print("NO")