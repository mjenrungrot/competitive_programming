# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        713.py
#  Description:     UVa Online Judge - 713
# =============================================================================

T = int(input())
while T > 0:
    T -= 1
    a, b = input().split()

    num_a = int(a[::-1])
    num_b = int(b[::-1])
    result = str(int(str(num_a + num_b)[::-1]))
    print(result)
