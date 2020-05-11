from collections import deque

def fill(A, N, M, r, c):
    Q = deque()
    Q.append((r,c))
    while len(Q):
        (r,c) = Q.popleft()
        if A[r][c] == '.':
            continue
        A[r][c] = '.'
        for (dr, dc) in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            if 0 <= r+dr < N and 0 <= c+dc < M:
                if A[r+dr][c+dc] == '#':
                    Q.append((r+dr, c+dc))

def run():
    N, M = list(map(int, input().split()))
    A = [list(input().strip()) for i in range(N)]

    # check impossible
    whiteRow = False
    for r in range(N):
        c = 0
        while c < M and A[r][c] == '.':
            c += 1
        if c == M:
            whiteRow = True
        while c < M and A[r][c] == '#':
            c += 1
        while c < M and A[r][c] == '.':
            c += 1
        if c != M:
            print(-1)
            return

    whiteCol = False
    for c in range(M):
        r = 0
        while r < N and A[r][c] == '.':
            r += 1
        if r == N:
            whiteCol = True
        while r < N and A[r][c] == '#':
            r += 1
        while r < N and A[r][c] == '.':
            r += 1
        if r != N:
            print(-1)
            return

    if whiteCol ^ whiteRow:
        print(-1)
        return

    ans = 0
    for r in range(N):
        for c in range(M):
            if A[r][c] == '#':
                ans += 1
                fill(A, N, M, r, c)

    print(ans)

if __name__ == '__main__':
    run()