"""
Problem: secretmessage
Link: https://open.kattis.com/problems/secretmessage
Source: ACM ICPC 2015 North America Qualifier
"""
import math
import copy

N = int(input())
for _ in range(N):
    string = input()
    L = len(string)
    K = int(math.ceil(math.sqrt(L)))
    A = [["" for c in range(K)] for r in range(K)]

    # Put strings into a matrix
    counter = 0
    for i in range(K):
        for j in range(K):
            if counter < L:
                A[i][j] = string[counter]
                counter += 1
            else:
                A[i][j] = '*'

    # Rotate matrix
    B = [["" for c in range(K)] for r in range(K)]
    for i in range(K-1,-1,-1):
        for j in range(K-1,-1,-1):
            B[i][j] = A[j][K-i-1]
            if(B[i][j] != '*'): print(B[i][j], end="")
    print("", end="\n")
