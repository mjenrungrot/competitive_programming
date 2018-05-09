"""
Problem: deduplicatingfiles
Link: https://open.kattis.com/problems/deduplicatingfiles
Source: Kattis
"""

def getHash(string):
    hashVal = 0
    for i in range(len(string)):
        hashVal = hashVal ^ ord(string[i])
    return hashVal

def runTest(N):
    hashDict = dict()
    setString = dict()
    nConflicts = 0
    for i in range(N):
        string = input()

        if string not in setString:
            setString[string] = 0
        setString[string] += 1

        hashVal = getHash(string)

        if hashVal not in hashDict:
            hashDict[hashVal] = 0
        hashDict[hashVal] += 1

        nConflicts += (hashDict[hashVal] - 1)

    for (key, val) in setString.items():
        nConflicts -= val*(val-1) // 2
    print("{:} {:}".format(len(setString), nConflicts))

while True:
    N = int(input())
    if N == 0: break
    runTest(N)
