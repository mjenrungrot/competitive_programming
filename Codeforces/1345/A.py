def run():
    N, M = list(map(int, input().split()))

    if N < M:
        N, M = M, N

    # N >= M
    if M == 1:
        print("YES")
        return
    elif M == N and N == 2:
        print("YES")
        return
    else:
        print("NO")
        return


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()