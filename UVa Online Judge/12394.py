while True:
    K, N = list(map(int, input().split()))
    if K == 0 and N == 0: break

    data = []
    for i in range(N):
        tmp = input().split()
        name = tmp[0]
        papers = list(map(int, tmp[1:]))
        data.append((name, papers))

    checked = [True for i in range(N)]

    # Check number of reviews
    n_reviews = [0 for i in range(N)]
    for i in range(N):
        for j in range(K):
            n_reviews[data[i][1][j] - 1] += 1

    for i in range(N):
        if n_reviews[i] != K:
            checked[i] = False

    # Check collaborator
    for i in range(N):
        for j in range(K):
            if data[i][0] == data[data[i][1][j] - 1][0]:
                checked[data[i][1][j] - 1] = False

    # Check same paper
    for i in range(N):
        for j in range(K):
            for k in range(j+1, K):
                if data[i][1][j] == data[i][1][k]:
                    checked[data[i][1][j] - 1] = False


    ans = 0
    for i in range(N):
        if not checked[i]:
            ans += 1

    if ans == 0: print("NO PROBLEMS FOUND")
    elif ans == 1: print("1 PROBLEM FOUND")
    else: print("{} PROBLEMS FOUND".format(ans))
