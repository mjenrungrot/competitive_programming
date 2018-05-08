"""
Problem: flexible
Link: https://open.kattis.com/problems/flexible
Source: ACM ICPC 2014 North America Qualifier
"""

W, P = list(map(int, input().split()))
A = [0] + list(map(int, input().split())) + [W]

answer = set()
for i in range(len(A)-1):
    for j in range(i+1,len(A)):
        answer.add(A[j] - A[i])

space = False
answer = sorted(answer)
for i in range(len(answer)):
    if(space): print(" ", end="")
    space = True
    print(answer[i], end="")
print("", end="\n")
