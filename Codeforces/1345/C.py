def run():
    N = int(input())
    A = list(map(int, input().split()))

    occupancy = set()
    for i in range(N):
        occupancy.add((i + A[i]) % N)

    if len(occupancy) == N:
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()
