def run():
    M, K = list(map(int, input().split()))
    
    pairs = []
    counts = [0 for i in range(M)]
    for i in range(K):
        G1, G2, _ = list(map(int, input().split()))
        G1 -= 1
        G2 -= 1
        instants = list(map(int, input().split()))
        pairs.append((G1, G2, instants))

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()