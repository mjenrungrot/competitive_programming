"""
Problem: stockprices
Link: https://open.kattis.com/problems/stockprices
Source: NWERC 2010
"""
import queue
import sys

def runTest():
    N = int(input())
    buyHeap = queue.PriorityQueue()   # MinHeap
    sellHeap = queue.PriorityQueue()  # MinHeap
    stockPrice = None
    for i in range(N):
        command, n, _, _, price = input().split()
        n = int(n)
        price = int(price)
        if command == "buy":
            buyHeap.put((int(-price), n))
        else:
            sellHeap.put((int(price), n))

        bestBid = buyHeap.queue[0] if len(buyHeap.queue) > 0 else None
        bestAsk = sellHeap.queue[0] if len(sellHeap.queue) > 0 else None

        while (bestBid is not None) and (bestAsk is not None) and (-bestBid[0] >= bestAsk[0]):
            stockPrice = bestAsk[0]
            nBid = bestBid[1]
            nAsk = bestAsk[1]
            print("Best bid = {:} ({:})".format(-bestBid[0], nBid), file=sys.stderr)
            print("Best ask = {:} ({:})".format(bestAsk[0], nAsk), file=sys.stderr)
            if nBid > nAsk:
                buyHeap.get()
                sellHeap.get()
                buyHeap.put((bestBid[0], nBid-nAsk))
            elif nBid < nAsk:
                buyHeap.get()
                sellHeap.get()
                sellHeap.put((bestAsk[0], nAsk-nBid))
            else:
                buyHeap.get()
                sellHeap.get()

            bestBid = buyHeap.queue[0] if len(buyHeap.queue) > 0 else None
            bestAsk = sellHeap.queue[0] if len(sellHeap.queue) > 0 else None

        bestBid = buyHeap.queue[0] if len(buyHeap.queue) > 0 else None
        bestAsk = sellHeap.queue[0] if len(sellHeap.queue) > 0 else None

        if bestAsk is not None:  print("{:}".format(int(bestAsk[0])), end=" ")
        else: print("-", end=" ")

        if bestBid is not None:  print("{:}".format(int(-bestBid[0])), end=" ")
        else: print("-", end=" ")

        if stockPrice is not None:  print("{:}".format(int(stockPrice)), end="\n")
        else: print("-", end="\n")

T = int(input())
for i in range(T):
    runTest()
