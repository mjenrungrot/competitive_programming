"""
Problem: collatz
Link: https://open.kattis.com/problems/collatz
Source: Kattis / CTU Open 2011
"""

while True:
    A, B = list(map(int, input().split()))
    if A == 0 and B == 0: break

    if A == B:
        print("{:} needs 0 steps, {:} needs 0 steps, they meet at {:}".format(A, B, A))
        continue

    origA = A
    origB = B
    mapA = dict()
    mapB = dict()
    mapA[A] = 0
    mapB[B] = 0
    stepA = 0
    stepB = 0

    while True:
        if A != 1:
            if A % 2 == 0:
                A = A // 2
            else:
                A = 3*A + 1
        if A not in mapA:
            stepA += 1
            mapA[A] = stepA

        if B != 1:
            if B % 2 == 0:
                B = B // 2
            else:
                B = 3*B + 1
        if B not in mapB:
            stepB += 1
            mapB[B] = stepB


        if A in mapB:
            print("{:} needs {:} steps, {:} needs {:} steps, they meet at {:}".format(origA, stepA, origB, mapB[A], A))
            break

        if B in mapA:
            print("{:} needs {:} steps, {:} needs {:} steps, they meet at {:}".format(origA, mapA[B], origB, stepB, B))
            break
        
