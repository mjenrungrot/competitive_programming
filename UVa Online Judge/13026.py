# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13026.py
#  Description:     UVa Online Judge - 13026
# =============================================================================
T = int(input())
for i in range(T):
    print("Case {}:".format(i+1))

    N = int(input())
    contacts = [input() for _ in range(N)]
    call = input()

    for contact in contacts:
        n_diff = 0
        for j in range(len(contact)):
            if contact[j] != call[j]: n_diff += 1
        if n_diff <= 1: print(contact)