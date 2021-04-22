# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12854.py
#  Description:     UVa Online Judge - 12854
# =============================================================================

while True:
    try:
        line1 = input()
        line2 = input()
    except EOFError:
        break

    num1 = int(''.join(line1.split()), base=2)
    num2 = int(''.join(line2.split()), base=2)

    if num1 + num2 == 31: print("Y")
    else: print("N")