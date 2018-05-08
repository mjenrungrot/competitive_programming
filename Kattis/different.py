"""
Task: different
Link: https://open.kattis.com/problems/different
Source: Kattis
"""
import sys

lines = sys.stdin
for line in lines:
    n, m = list(map(int, line.split()))
    print(abs(n-m))

