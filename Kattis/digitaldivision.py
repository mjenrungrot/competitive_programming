"""
Problem: digitaldivision
Link: https://open.kattis.com/problems/digitdivision
Source: CERC 2015
"""

N, M = list(map(int, input().split()))
A = list(map(int,input()))

cuttingPosition = []
curr = 0
MOD = int(1e9 + 7)
for i in range(N):
    curr = (curr * 10 + A[i]) % M
    if(curr % M == 0):
        cuttingPosition.append(i)
        curr = 0

if curr != 0:
    print(0)
else:
    ans = 1
    for i in range(len(cuttingPosition) - 1):
        ans = (ans * 2) % MOD
    print(ans)
