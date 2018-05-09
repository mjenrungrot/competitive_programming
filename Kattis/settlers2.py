"""
Problem: settlers2
Link: https://open.kattis.com/problems/settlers2
Source: NWERC 2009
"""
from collections import defaultdict
import math

MAXN = 10000

currentPosition = (0,0)
currentNum = 1
counter = defaultdict()
layers = 1
direction = 0
directionCounter = 0
limitDirectionCounter = [layers, layers-1, layers, layers, layers, layers]
transitionVectors     = [(-1,1), (-2,0),  (-1,-1), (1,-1),  (2,0),  (1,1)]
nMoves = 0

tilesMap = dict()
tilesMap[currentPosition] = currentNum
tilesList = [None, currentNum]
for num in [1,2,3,4,5]: counter[num] = 0
counter[currentNum] += 1


def add(position, vector):
    return (position[0] + vector[0], position[1] + vector[1])

# Preprocess
while len(tilesList) - 1 < MAXN:
    currentPosition = add(currentPosition, transitionVectors[direction])
    directionCounter += 1
    while limitDirectionCounter[direction] == directionCounter:
        # Increase limit counter for next round
        limitDirectionCounter[direction] += 1

        # Change direction
        direction = (direction + 1) % len(transitionVectors)

        # Reset direction counter
        directionCounter = 0


    neighbors = [add(currentPosition, transitionVector) for transitionVector in transitionVectors]
    possibilities = set([1,2,3,4,5])

    # Eliminate similar tiles
    for neighbor in neighbors:
        if neighbor in tilesMap and tilesMap[neighbor] in possibilities:
            possibilities.remove(tilesMap[neighbor])

    # Keep only the least number of tiles
    minCounter = math.inf
    for possibility in possibilities:
        minCounter = min(minCounter, counter[possibility])
    possibilityToRemove = []
    for possibility in possibilities:
        if counter[possibility] != minCounter:
            possibilityToRemove.append(possibility)
    for possibility in possibilityToRemove:
        possibilities.remove(possibility)

    # Sort by number
    possibilities = sorted(possibilities)

    currentNum = possibilities[0]
    tilesMap[currentPosition] = currentNum
    tilesList.append(currentNum)
    counter[currentNum] += 1

# Post-process
C = int(input())
for i in range(C):
    n = int(input())
    print(tilesList[n])
