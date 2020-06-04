import sys

lines = sys.stdin.readlines()
for line in lines:
    line = line.strip()
    P, H, O = list(map(int, line.split()))

    spares = O - P
    if H > spares: print("Hunters win!")
    else: print("Props win!")