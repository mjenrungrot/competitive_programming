# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11734.py
#  Description:     UVa Online Judge - 11734
# =============================================================================
N = int(input())

for i in range(1, N+1):
    line1 = input()
    line2 = input()

    if line1 == line2:
        print(f"Case {i}: Yes")
    elif line1.replace(" ", "") == line2.replace(" ", ""):
        print(f"Case {i}: Output Format Error")
    else:
        print(f"Case {i}: Wrong Answer")
