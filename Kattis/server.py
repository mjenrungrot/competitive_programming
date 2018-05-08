"""
Problem: server
Link: https://open.kattis.com/problems/server
Source: Rocky Mountain Regional Contest (RMRC) 2014
"""
n, T = list(map(int, input().split()))
A = list(map(int, input().split()))

sum = 0
counter = 0
for i in range(len(A)):
    if sum + A[i] <= T:
        sum += A[i]
        counter += 1
    else:
        break

print(counter)
