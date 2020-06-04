N = int(input())

for i in range(N):
    A = list(map(int, input().split()))

    ans = "Yes"
    for x in A:
        if x == 0:
            ans = "No"
            break

    print("Set #{}: {}".format(i+1, ans))
