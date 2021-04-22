# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13151.py
#  Description:     UVa Online Judge - 13151
# =============================================================================
while True:
    ivalue, t = input().split()
    t = int(t)
    if t == 0:
        break

    if '0x' in ivalue:
        ivalue = int(ivalue[2:], base=16)
    elif '0' == ivalue[0]:
        ivalue = int(ivalue, base=8)
    else:
        ivalue = int(ivalue, base=10)

    score = 0
    expected = ivalue
    for i in range(t):
        line = input().split()
        instruction = line[0]
        val = int(line[1])

        correct = False

        if instruction == '++i':
            expected += 1
        elif instruction == '--i':
            expected -= 1

        if val == expected:
            correct = True
            
        if correct:
            score += 1
        else:
            expected = val
            
        if instruction == 'i++':
            expected += 1
        elif instruction == 'i--':
            expected -= 1
        

    print(score)