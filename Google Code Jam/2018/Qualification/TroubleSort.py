def doTest(testNum):
    N = int(input())
    V = list(map(int,input().split(' ')))
    evens = V[::2]
    odds  = V[1::2]

    sorted_evens = sorted(evens)
    sorted_odds = sorted(odds)
    
    interleaved = sorted_evens + sorted_odds
    interleaved[::2] = sorted_evens
    interleaved[1::2] = sorted_odds
    
    def findIndex(A):
        for i in range(len(A)-1):
            if A[i] > A[i+1]:
                return i
        return -1

    index = findIndex(interleaved)

    if index >= 0:
        print("Case #{:}: {:}".format(testNum, index))
    else:
        print("Case #{:}: OK".format(testNum))

T = int(input())
for i in range(T):
    doTest(i+1)


