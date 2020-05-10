"""
Problem: Vestigium
Google Codejam - Qualification Round 2020
Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c?show=progress
"""
def run(idx):
    N = int(input())
    A = []
    for _ in range(N):
        tmp = list(map(int, input().strip().split()))
        A.append(tmp)

    trace = 0
    for i in range(N):
        trace += A[i][i]

    nr = 0
    nc = 0
    for i in range(N):
        set_r = set()
        set_c = set()
        add_r = False
        add_c = False
        for j in range(N):
            if A[i][j] in set_r:
                add_r = True
            if A[j][i] in set_c:
                add_c = True
            set_r.add(A[i][j])
            set_c.add(A[j][i])

        if add_r: nr += 1
        if add_c: nc += 1

    print("Case #{}: {} {} {}".format(idx, trace, nr, nc))

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        run(i)
