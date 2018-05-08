"""
Problem: mandelbrot
Link: https://open.kattis.com/problems/mandelbrot
Source: ACM ICPC 2012 World Finals Practice
"""
import sys
import math

caseNum = 0
lines = sys.stdin
for line in lines:
    x, y, r = line.split()
    x = float(x)
    y = float(y)
    r = int(r)

    caseNum += 1
    divergent = False
    zi = (0,0)
    for i in range(r):
        zi_x = zi[0]
        zi_y = zi[1]
        zi = (zi_x * zi_x - zi_y * zi_y + x, 2 * zi_x * zi_y + y)
        dist = math.sqrt(zi[0]*zi[0] + zi[1]*zi[1])

        if dist > 2:
            divergent = True
            print("Case {:}: OUT".format(caseNum))
            break

    if not divergent:
        print("Case {:}: IN".format(caseNum))
