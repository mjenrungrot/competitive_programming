"""
Problem: busnumbers
Link: https://open.kattis.com/problems/busnumbers
Source: Kattis
"""

N = int(input())
A = list(map(int, input().split()))
A = sorted(A)

left = 0
right = left
answer = []

while True:
    right = left
    while right + 1 < len(A) and A[right + 1] == A[right] + 1:
        right += 1
    if right > left + 1:
        answer.append("{:}-{:}".format(A[left], A[right]))
        left = right + 1
    elif right > left:
        answer.append("{:}".format(A[left]))
        answer.append("{:}".format(A[right]))
        left = right + 1
    else:
        answer.append("{:}".format(A[left]))
        left = right + 1

    if left >= len(A): break

space = False
for bus in answer:
    if(space): print(" ", end="")
    space = True
    print(bus, end="")

print("", end="\n")
