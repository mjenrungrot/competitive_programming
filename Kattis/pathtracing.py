"""
Problem: pathtracing
Link: https://open.kattis.com/problems/pathtracing
Source: Kattis
"""
import sys
import math

currentPos = (0,0) # (r,c)
trace = [currentPos]
minX = 0
minY = 0
maxX = 0
maxY = 0

lines = sys.stdin
for line in lines:
    line = line.strip()
    if line == "down":
        currentPos = (currentPos[0] + 1, currentPos[1])
    elif line == "up":
        currentPos = (currentPos[0] - 1, currentPos[1])
    elif line == "left":
        currentPos = (currentPos[0], currentPos[1] - 1)
    elif line == "right":
        currentPos = (currentPos[0], currentPos[1] + 1)

    minX = min(minX, currentPos[1])
    minY = min(minY, currentPos[0])
    trace.append(currentPos)

translatedTrace = []
for tracePoint in trace:
    translatedTrace.append((tracePoint[0] - minY + 1, tracePoint[1] - minX + 1))
    maxX = max(maxX, tracePoint[1] - minX + 1)
    maxY = max(maxY, tracePoint[0] - minY + 1)

A = [ [' ' for c in range(maxX+2) ] for r in range(maxY+2) ]
for r in [0, maxY+1]:
    for c in range(maxX+2):
        A[r][c] = '#'

for r in range(maxY+2):
    for c in [0, maxX+1]:
        A[r][c] = '#'

for tracePoint in translatedTrace:
    A[tracePoint[0]][tracePoint[1]] = '*'

A[translatedTrace[0][0]][translatedTrace[0][1]] = 'S'
A[translatedTrace[-1][0]][translatedTrace[-1][1]] = 'E'

for r in range(maxY+2):
    for c in range(maxX+2):
        print(A[r][c], end="")
    print("", end="\n")
