def run():
    N = int(input())
    line = input()

    countB = sum(map(lambda x: x == 'B', line))
    countW = sum(map(lambda x: x == 'W', line))
    countT = sum(map(lambda x: x == 'T', line))

    if countT == 0 and countW == 0 and countB == 0: print("ABANDONED")
    elif countT == 0 and countW == 0 and countB: print("BANGLAWASH")
    elif countT == 0 and countB == 0 and countW: print("WHITEWASH")
    elif countW == countB: print("DRAW {} {}".format(countW, countT))
    elif countW > countB: print("WWW {} - {}".format(countW, countB))
    else: print("BANGLADESH {} - {}".format(countB, countW))

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case {}: ".format(i+1), end="")
        run()