import sys

while True:
    line = sys.stdin.readline()

    if line == "": break

    A, B = list(map(int, line.strip().split()))

    if A == B: print(A)
    else: print(max(A, B))