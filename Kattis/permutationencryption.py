"""
Problem: permutationencryption
Link: https://open.kattis.com/problems/permutationencryption
Source: Kattis
"""

while True:
    N = list(map(int, input().split()))
    A = N[1:]
    N = N[0]
    if N == 0: break
    string = input()
    L = len(string)
    while L % N != 0:
        string += ' '
        L += 1
    print("'", end="")
    for i in range(0, L, N):
        for j in range(N):
            print(string[i+A[j]-1], end='')
    print("'", end="\n")
