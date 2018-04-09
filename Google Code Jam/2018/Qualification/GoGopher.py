import sys

def checkDone(x, y):
    if((x,y) == (0,0)): return True
    if((x,y) == (-1,-1)): return True
    return False

def getBestCoord(P, ROW, COL, maxval):
    bestPos = (2,2)
    cost    = -1
    for i in range(2,ROW-1):
        for j in range(2,COL-1):
            sumPos = 9
            sumPos -= P[i-1][j-1] + P[i-1][j] + P[i-1][j+1] + P[i][j-1] + P[i][j] + P[i][j+1] + P[i+1][j-1] + P[i+1][j] + P[i+1][j+1]
            if(sumPos == maxval):
                return (i,j), sumPos
            if(sumPos > cost):
                bestPos = (i,j)
                cost = sumPos
            
    return bestPos, cost


def doTest(testNum):
    A = int(input())
    ROW = 16
    COL = 16
    P = [[0 for i in range(COL+2)] for j in range(ROW+2)]

    curBest = 9
    for i in range(1000):
        (y,x), cost = getBestCoord(P, ROW, COL, curBest);
        # print("{:} {:} cost = {:}".format(x,y,cost), file=sys.stderr)
        if cost < curBest: curBest = cost
        print("{:} {:}".format(x,y))
        sys.stdout.flush()
        inp = input()
        x,y = list(map(int,inp.split()))
        # print("{:} {:}".format(x,y), file=sys.stderr)
        P[y][x] = 1
        if checkDone(x,y):
            return


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        doTest(i)


