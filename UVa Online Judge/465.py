# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        465.py
#  Description:     UVa Online Judge - 465
# =============================================================================
while True:
    try:
        line = input()
    except EOFError:
        break

    print(line)
    if "+" in line:
        a, b = list(map(int, line.split("+")))
        result = a + b
    elif "*" in line:
        a, b = list(map(int, line.split("*")))
        result = a * b

    if a > (1 << 31) - 1:
        print("first number too big")
    if b > (1 << 31) - 1:
        print("second number too big")
    if result > (1 << 31) - 1:
        print("result too big")
