T = int(input())

while T > 0:
    T -= 1
    A, B = list(map(int, input().split()))
    print(A-B)