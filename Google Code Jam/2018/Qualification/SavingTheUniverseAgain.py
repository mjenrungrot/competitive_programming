def testPower(P):
    current = 0
    charge = 1
    for i in range(len(P)):
        if P[i] == 'C':
            charge *= 2
        else:
            current += charge
    return current

def f(D,P):
    nSwap = 0
    
    while True:
        if testPower(P) <= D: break
        
        canSwap = False
        for i in range(len(P)-1):
            if P[i] == 'C' and P[i+1] == 'S':
                P = list(P)
                P[i] = 'S'
                P[i+1] = 'C'
                P = ''.join(P)
                nSwap += 1
                canSwap = True
                break
        if not canSwap:
            return "IMPOSSIBLE"

    return str(nSwap)

T = int(input())
for i in range(T):
    line = input()
    D, P = line.split(' ')
    D = int(D)
    print("Case #{:}: {:}".format(i+1, f(D,P)))

