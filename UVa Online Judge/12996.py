T = int(input())
for i in range(T):
    N, L = list(map(int, input().split()))

    possible = True
    each_kind = list(map(int, input().split()))
    limit_each_kind = list(map(int, input().split()))
    sum_fruits = 0
    for j in range(N):
        sum_fruits += each_kind[j]
        if limit_each_kind[j] < each_kind[j]:
            possible = False
            break

    if sum_fruits > L:
        possible = False

    if possible: print("Case {}: Yes".format(i+1))
    else: print("Case {}: No".format(i+1))