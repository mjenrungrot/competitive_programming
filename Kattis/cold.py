"""
Problem: cold
Link: https://open.kattis.com/problems/cold 
Source: Kattis
"""
N = int(input())
A = list(map(int, input().split()))

answer = 0
for i in range(len(A)):
    answer += (A[i] < 0)

print(answer)
