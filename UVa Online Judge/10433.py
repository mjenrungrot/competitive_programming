# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10433.py
#  Description:     UVa Online Judge - 10433
# =============================================================================

while True:
    try:
        str_N = input()
    except EOFError:
        break

    N = int(str_N)
    N2 = N * N
    str_N2 = str(N2)
    len_N = len(str_N)

    if str_N2[-len_N:] == str_N:
        print("Automorphic number of {}-digit.".format(len_N))
    else:
        print("Not an Automorphic number.")
